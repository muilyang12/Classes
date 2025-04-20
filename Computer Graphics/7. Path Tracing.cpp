/*
    Path Tracing
*/
Vector3f castRay(const Ray &ray, int depth)
{
    if (depth > 5)
        return Vector3f(0.0f);

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

    // Cast a shadow ray to check if any object blocks the light
    Ray shadowCheckRay(intersection.coords + intersection.normal * 1e-4f, pointToLightDirection);
    Intersection shadowIntersection = intersect(shadowCheckRay);

    Vector3f directLight(0.0f);

    // If the path to the light is not blocked
    if (!shadowIntersection.happened || shadowIntersection.distance * shadowIntersection.distance > distSquare - 1e-4f)
    {
        float cosTheta = std::max(0.0f, dotProduct(pointToLightDirection, intersection.normal));
        float cosThetaLight = std::max(0.0f, dotProduct(-pointToLightDirection, lightIntersection.normal));
        Vector3f fr = intersection.m->eval(ray.direction, pointToLightDirection, intersection.normal);

        directLight = lightIntersection.emit * fr * cosTheta * (cosThetaLight / distSquare) / lightPdf;
    }

    Vector3f indirectLight(0.0f);
    const float RussianRoulette = 0.3f;

    // When we are using smaller RussianRoulette value, there are less noise
    if (get_random_float() < RussianRoulette)
    {
        // Sample an incoming direction for indirect lighting and compute its PDF
        Vector3f incomingDirection = intersection.m->sample(ray.direction, intersection.normal);
        float pdfIncomingDirection = intersection.m->pdf(ray.direction, incomingDirection, intersection.normal);

        // Only proceed if the sampled direction has a non-zero PDF
        if (pdfIncomingDirection > 1e-6f)
        {
            Ray newRay(intersection.coords + intersection.normal * 1e-4f, incomingDirection);
            Vector3f Li = castRay(newRay, depth + 1);
            Vector3f fr = intersection.m->eval(ray.direction, incomingDirection, intersection.normal);
            float cosN = std::max(0.0f, dotProduct(incomingDirection, intersection.normal));

            indirectLight = Li * fr * cosN / pdfIncomingDirection / RussianRoulette;
        }
    }

    return directLight + indirectLight;
}