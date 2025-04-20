/*
    Path Tracing
*/
Vector3f castRay(const Ray &ray, int depth)
{
    Intersection intersection = intersect(ray);

    // If the ray does not hit anything
    if (!intersection.happened)
        return Vector3f(0.0f);

    // If the intersection is with a light source
    if (intersection.m->hasEmission())
        return intersection.m->getEmission();

    // Randomly sample a point on one of the light sources in the scene
    Intersection lightIntersection;
    float lightPdf = 0.0f;
    sampleLight(lightIntersection, lightPdf);

    // Compute the direction and distance from the intersection point to the sampled light point
    Vector3f pointToLight = lightIntersection.coords - intersection.coords;
    Vector3f pointToLightDirection = normalize(pointToLight);
    float distSquare = dotProduct(pointToLight, pointToLight);
}