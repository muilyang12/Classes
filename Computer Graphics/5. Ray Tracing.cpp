/*
    Möller–Trumbore Algorithm

    The Möller–Trumbore algorithm is a widely-used method for computing the intersection between a ray and
    a triangle in 3D space. Given a triangle defined by three vertices (v0, v1, v2) and a ray defined by an
    origin and a direction vector, this algorithm checks whether the ray intersects the triangle. If there
    is an intersection, it calculates the distance from the ray origin to the intersection point (tnear),
    as well as the barycentric coordinates (u, v) of that point on the triangle's surface.

    origin + t ⋅ direction = (1 − u − v) ⋅ v0 + u ⋅ v1 + v ⋅ v2
*/
bool doesRayTriangleIntersect(const Vector3f &v0, const Vector3f &v1,
                              const Vector3f &v2, const Vector3f &orig,
                              const Vector3f &dir, float &tnear, float &u,
                              float &v)
{
    Vector3f edge1 = v1 - v0;
    Vector3f edge2 = v2 - v0;

    Vector3f pVector = crossProduct(dir, edge2);
    float determinant = dotProduct(edge1, pVector);

    // If determinant is near zero, ray is parallel to the triangle.
    if (fabs(determinant) < 1e-8)
        return false;

    float invDeterminant = 1.0f / determinant;

    Vector3f tVector = orig - v0;
    float newU = dotProduct(tVector, pVector) * invDeterminant;
    if (newU < 0.0f || newU > 1.0f)
        return false;

    Vector3f qVector = crossProduct(tVector, edge1);
    float newV = dotProduct(dir, qVector) * invDeterminant;
    if (newV < 0.0f || newU + newV > 1.0f)
        return false;

    float newTNear = dotProduct(edge2, qVector) * invDeterminant;
    if (newTNear < 0.0f)
        return false;

    tnear = newTNear;
    u = newU;
    v = newV;

    return true;
}

/*
    Ray Generation

    This is the core ray generation process used in ray tracing. For each pixel on the screen, a ray is
    constructed that starts at the camera position and passes through a corresponding point on the view
    plane in world space.
*/
void render(const Scene &scene)
{
    std::vector<Vector3f> framebuffer(scene.width * scene.height);
    int m = 0;

    float scale = std::tan(deg2rad(scene.fov * 0.5f));
    float imageAspectRatio = scene.width / (float)scene.height;

    Vector3f cameraPosition = Vector3f(0, 0, 0);
    Vector3f cameraForward = Vector3f(0, 0, -1);
    Vector3f cameraUp = Vector3f(0, 1, 0);
    Vector3f cameraRight = Vector3f(1, 0, 0);

    Vector3f cameraPlaneCenter = cameraPosition + cameraForward;

    for (int j = 0; j < scene.height; j++)
    {
        for (int i = 0; i < scene.width; i++)
        {
            float px = i + 0.5f;
            float py = j + 0.5f;

            float normalizedPx = 2 * (px / (float)scene.width) - 1.0f;
            float normalizedPy = 1 - 2 * (py / (float)scene.height);

            float x = normalizedPx * imageAspectRatio * scale;
            float y = normalizedPy * scale;

            Vector3f pixelPosition = cameraPlaneCenter + cameraRight * x + cameraUp * y;

            Vector3f direction = normalize(pixelPosition - cameraPosition);

            framebuffer[m] = castRay(cameraPosition, direction, scene, 0);
            m++;
        }
    }
}