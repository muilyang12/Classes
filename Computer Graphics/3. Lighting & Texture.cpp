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