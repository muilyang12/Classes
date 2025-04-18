/*
    Bounding Volume Hierarchy

    To determine whether a ray intersects with objects in the scene, it is inefficient to test against
    every object individually. BVH is an acceleration structure that speeds up this process by organizing
    objects into a binary tree, where each node contains a bounding box that encloses a group of objects.
    The BVH tree starts with a root node that bounds all objects. This node is recursively split into two
    child nodes, each containing a subset of the objects with their own bounding boxes. Instead of checking
    for intersection with every object, we first test whether the ray intersects the bounding box of the
    root node. If it does, we recursively check the child nodes.
*/

Intersection getIntersection(BVHBuildNode *node, const Ray &ray)
{
    Intersection intersection;

    if (node == nullptr)
        return intersection;

    // Check if the ray intersects its bounding box
    if (!node->bounds.IntersectP(ray, ray.direction_inv))
        return intersect;

    // If this is a leaf node, compute the actual intersection with the object
    if (node->left == nullptr && node->right == nullptr)
        return node->object->getIntersection(ray);

    Intersection intersectionLeft = getIntersection(node->left, ray);
    Intersection intersectionRight = getIntersection(node->right, ray);

    if (intersectionLeft.happened && intersectionRight.happened)
        return intersectionLeft.distance < intersectionRight.distance ? intersectionLeft : intersectionRight;
    else if (intersectionLeft.happened)
        return intersectionLeft;
    else if (intersectionRight.happened)
        return intersectionRight;
    else
        return intersection;
}

/*
    Test whether a given ray intersects the axis-aligned bounding box (AABB)

    The variable "t" represents the parametric distance along the ray, as defined in the ray equation
    "P(t) = origin + t * direction". Although "t" originates from the idea of "time", in ray tracing it
    is used to measure distance along the ray.

    This function uses the slab method to compute the intersection range [tEnter, tExit] along the ray
    for each axis x, y, and z. It checks whether the ray intersects the box on all three axes simultaneously
    by determining if a valid intersection interval exists.
*/
bool IntersectP(const Ray &ray, const Vector3f &invDir)
{
    double tEnter = -std::numeric_limits<double>::infinity();
    double tExit = std::numeric_limits<double>::infinity();

    for (int i = 0; i < 3; i++)
    {
        // t0 is the distance (time) to the near plane (entering the box), and t1 is the distance (time) to
        // the far plane (exiting the box).
        double t0 = (pMin[i] - ray.origin[i]) * invDir[i];
        double t1 = (pMax[i] - ray.origin[i]) * invDir[i];
        if (t0 > t1)
            std::swap(t0, t1);

        tEnter = std::max(tEnter, t0);
        tExit = std::min(tExit, t1);

        // When there is no valid intersection interval
        if (tExit < tEnter)
            return false;
    }

    return true;
}