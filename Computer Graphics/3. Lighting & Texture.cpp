/*
    Blinn-Phong Model

    - Ambient Lighting: ka * ambient_intensity
    - Diffuse Lighting: kd * (light_intensity / r^2) * max(0, N · L)
    - Specular Lighting: ks * (light_intensity / r^2) * (N · H)^p
      - H: Normalized halfway vector (H = (V + L) / |V + L|)
      - p: Shininess exponent (larger p -> smaller, sharper highlight)

    Eigen::Vector3f cwiseProduct(const Eigen::Vector3f &other)
    - This performs an element-wise multiplication between two vectors.
    - Unlike matrix multiplication, this operation multiplies corresponding elements.
*/
Eigen::Vector3f phong_fragment_shader(const fragment_shader_payload &payload)
{
    // Lighting coefficients
    Eigen::Vector3f ka = Eigen::Vector3f(0.005, 0.005, 0.005);
    Eigen::Vector3f kd = payload.color;
    Eigen::Vector3f ks = Eigen::Vector3f(0.7937, 0.7937, 0.7937);

    // Point lights
    auto l1 = light{{20, 20, 20}, {500, 500, 500}};
    auto l2 = light{{-20, 20, 0}, {500, 500, 500}};
    std::vector<light> lights = {l1, l2};

    Eigen::Vector3f amb_light_intensity{10, 10, 10};

    Eigen::Vector3f eyePosition{0, 0, 10};

    float p = 150.f;

    Eigen::Vector3f point = payload.view_pos;
    Eigen::Vector3f normal = payload.normal.normalized();
    Eigen::Vector3f viewDirection = (eyePosition - point).normalized();

    Eigen::Vector3f resultColor = {0, 0, 0};

    for (auto &light : lights)
    {
        // Ambient term
        Eigen::Vector3f ambient = ka.cwiseProduct(amb_light_intensity);

        float rSquare = (light.position - point).dot(light.position - point);
        Eigen::Vector3f lightDirection = (light.position - point).normalized();

        // Diffuse term
        float nDotL = std::max(0.0f, normal.dot(lightDirection));
        Eigen::Vector3f diffuse = kd.cwiseProduct(light.intensity / rSquare) * nDotL;

        // Specular term
        Eigen::Vector3f halfwayVector = (viewDirection + lightDirection).normalized();
        float nDotH = std::max(0.0f, normal.dot(halfwayVector));
        Eigen::Vector3f specular = ks.cwiseProduct(light.intensity / rSquare) * std::pow(nDotH, p);

        resultColor += ambient + diffuse + specular;
    }

    return resultColor * 255.f;
}

/*
    Texture fragment shader samples color from a texture and uses that as the diffuse term
    in the Blinn-Phong model.
*/
Eigen::Vector3f texture_fragment_shader(
    const fragment_shader_payload &payload)
{
    Eigen::Vector3f textureColor = {0, 0, 0};

    // If a texture is provided, sample it using the (u,v) coordinates
    if (payload.texture)
    {
        Eigen::Vector2f textureCoordinates = payload.tex_coords;
        textureColor = payload.texture->getColor(textureCoordinates.x(), textureCoordinates.y());
    }

    // Lighting coefficients (Convert sampled texture color into a suitable range for kd)
    Eigen::Vector3f ka = Eigen::Vector3f(0.005, 0.005, 0.005);
    Eigen::Vector3f kd = textureColor / 255.f;
    Eigen::Vector3f ks = Eigen::Vector3f(0.7937, 0.7937, 0.7937);

    // Point lights
    auto l1 = light{{20, 20, 20}, {500, 500, 500}};
    auto l2 = light{{-20, 20, 0}, {500, 500, 500}};
    std::vector<light> lights = {l1, l2};

    Eigen::Vector3f amb_light_intensity{10, 10, 10};

    Eigen::Vector3f eyePosition{0, 0, 10};

    float p = 150.f;

    Eigen::Vector3f point = payload.view_pos;
    Eigen::Vector3f normal = payload.normal;
    Eigen::Vector3f viewDirection = (eyePosition - point).normalized();

    Eigen::Vector3f resultColor = {0, 0, 0};

    for (auto &light : lights)
    {
        // Ambient term
        Eigen::Vector3f ambient = ka.cwiseProduct(amb_light_intensity);

        float rSquare = (light.position - point).dot(light.position - point);
        Eigen::Vector3f lightDirection = (light.position - point).normalized();

        // Diffuse term
        float nDotL = std::max(0.0f, normal.dot(lightDirection));
        Eigen::Vector3f diffuse = kd.cwiseProduct(light.intensity / rSquare) * nDotL;

        // Specular term
        Eigen::Vector3f halfwayVector = (viewDirection + lightDirection).normalized();
        float nDotH = std::max(0.0f, normal.dot(halfwayVector));
        Eigen::Vector3f specular = ks.cwiseProduct(light.intensity / rSquare) * std::pow(nDotH, p);

        resultColor += ambient + diffuse + specular;
    }

    return resultColor * 255.f;
}

/*
    Here, we interpret the texture as a height map. We use the TBN (Tangent-Bitangent-Normal)
    matrix to modify the normal and displace the surface position based on the height map.
    This physically alters the geometry, creating actual depth and bumps rather than just a
    visual effect.

    Finite Difference Method (FDM)
    - We use the FDM to approximate the partial derivatives of the height function h(u, v)
      with respect to texture coordinates u and v.
    - The rate of height change in the u direction (Since Δu is very small)
      ∂h/∂u = ( h(u + Δu, v) - h(u, v) ) / Δu = h(u + Δu, v) - h(u, v) = h(u2, v) - h(u, v)
    - The rate of height change in the v direction (Since Δv is very small)
      ∂h/∂v = ( h(u, v + Δv) - h(u, v) ) / Δv = h(u, v + Δv) - h(u, v) = h(u, v2) - h(u, v)

    Perturbed Normal Vector
    - In tangent space, flat surface has a normal of (0, 0, 1).
    - If the surface rises in the +u direction by dU, the normal tilts in the -u direction by dU.
    - The same applies to the v direction.
    - Thus, we construct the perturbed normal in tangent space as (-dU, -dV, 1).
    - And multiply TBD matrix to transform it to the perturbed normal in real space.
*/
Eigen::Vector3f displacement_fragment_shader(
    const fragment_shader_payload &payload)
{
    Eigen::Vector3f ka = Eigen::Vector3f(0.005, 0.005, 0.005);
    Eigen::Vector3f kd = payload.color;
    Eigen::Vector3f ks = Eigen::Vector3f(0.7937, 0.7937, 0.7937);

    auto l1 = light{{20, 20, 20}, {500, 500, 500}};
    auto l2 = light{{-20, 20, 0}, {500, 500, 500}};
    std::vector<light> lights = {l1, l2};

    Eigen::Vector3f amb_light_intensity{10, 10, 10};
    Eigen::Vector3f eyePosition{0, 0, 10};

    Eigen::Vector3f point = payload.view_pos;
    Eigen::Vector3f normal = payload.normal;
    Eigen::Matrix3f TBN = payload.TBN;

    // Parameters controlling the displacement effect
    float kh = 0.2, kn = 0.1;

    float u = payload.tex_coords.x();
    float v = payload.tex_coords.y();
    float w = payload.texture->width;
    float h = payload.texture->height;

    float u2 = u + 1.0f / w; // u2 = u + Δu = u + 1/w
    float v2 = v + 1.0f / h; // v2 = v + Δv = v + 1/h

    Eigen::Vector3f textureColor = payload.texture->getColor(u, v);
    Eigen::Vector3f textureColorU2 = payload.texture->getColor(u2, v);
    Eigen::Vector3f textureColorV2 = payload.texture->getColor(u, v2);

    float huv = textureColor.norm();
    float hu2v = textureColorU2.norm(); // h(u2, v) = h(u + Δu, v)
    float huv2 = textureColorV2.norm(); // h(u, v2) = h(u, v + Δv)

    // Approximate height derivatives using finite difference method
    float dU = kh * kn * (hu2v - huv); // = ∂h/∂u
    float dV = kh * kn * (huv2 - huv); // = ∂h/∂v

    // Construct a perturbed normal vector
    Eigen::Vector3f normalInTangentSpace = Vector3f(-dU, -dV, 1.0f);
    Eigen::Vector3f normalInRealSpace = TBN * normalInTangentSpace;
    Eigen::Vector3f n = normalInRealSpace.normalized();

    // Displace the original position along the perturbed normal
    Eigen::Vector3f newPoint = point + n * huv * kn;

    Eigen::Vector3f viewDirection = (eyePosition - newPoint).normalized();

    Eigen::Vector3f resultColor = {0, 0, 0};

    for (auto &light : lights)
    {
        // Ambient term
        Eigen::Vector3f ambient = ka.cwiseProduct(amb_light_intensity);

        float rSquare = (light.position - newPoint).dot(light.position - newPoint);
        Eigen::Vector3f lightDirection = (light.position - newPoint).normalized();

        // Diffuse term
        float nDotL = std::max(0.0f, n.dot(lightDirection));
        Eigen::Vector3f diffuse = kd.cwiseProduct(light.intensity / rSquare) * nDotL;

        // Specular term
        Eigen::Vector3f halfwayVector = (viewDirection + lightDirection).normalized();
        float nDotH = std::max(0.0f, n.dot(halfwayVector));
        Eigen::Vector3f specular = ks.cwiseProduct(light.intensity / rSquare) * nDotH;

        resultColor += ambient + diffuse + specular;
    }

    return resultColor * 255.f;
}
