// Checks if a given 2D point (x, y) is inside a triangle.
bool insideTriangle(int x, int y, const Vector3f *_v)
{
    Vector3f point(x, y, 0);

    Vector3f vertex1 = _v[0];
    Vector3f vertex2 = _v[1];
    Vector3f vertex3 = _v[2];

    Vector3f edge1 = vertex2 - vertex1;
    Vector3f edge2 = vertex3 - vertex2;
    Vector3f edge3 = vertex1 - vertex3;

    Vector3f vector1 = point - vertex1;
    Vector3f vector2 = point - vertex2;
    Vector3f vector3 = point - vertex3;

    // Compute z-component of cross products.
    float cross1 = edge1.x() * vector1.y() - edge1.y() * vector1.x();
    float cross2 = edge2.x() * vector2.y() - edge2.y() * vector2.x();
    float cross3 = edge3.x() * vector3.y() - edge3.y() * vector3.x();

    /*
        The point is iside if all cross products have the same sign. This is because having the same sign
        indicates that the point is consistently located on the same side of each triangle edge.
    */
    bool isInside = (cross1 < 0 && cross2 < 0 && cross3 < 0) || (cross1 > 0 && cross2 > 0 && cross3 > 0);

    return isInside;
}

// Rasterize a triangle onto the framebuffer.
void rasterizeTriangle(const Triangle &t)
{
    auto v = t.toVector4();

    /*
        Determine the axis-aligned bounding box of the triangle.

        We use a bounding box to limit the rasterization area and improve performance. By iterating
        only through pixels within the triangle's bounding box, we can reduce unnecessary computations.
    */
    float minX = std::min({v[0].x(), v[1].x(), v[2].x()});
    float maxX = std::max({v[0].x(), v[1].x(), v[2].x()});
    float minY = std::min({v[0].y(), v[1].y(), v[2].y()});
    float maxY = std::max({v[0].y(), v[1].y(), v[2].y()});

    int left = (int)std::floor(minX);
    int right = (int)std::floor(maxX);
    int bottom = (int)std::floor(minY);
    int top = (int)std::floor(maxY);

    // Iterate through all pixels within the bounding box.
    for (int x = left; x <= right; x++)
    {
        for (int y = bottom; y <= top; y++)
        {
            float pixelCenterX = (float)x + 0.5f;
            float pixelCenterY = (float)y + 0.5f;

            // Check if the pixel center is inside the triangle
            if (insideTriangle(pixelCenterX, pixelCenterY, t.v))
            {
                // If inside, calculate the depth (z-value) using barycentric interpolation.
                auto [alpha, beta, gamma] = computeBarycentric2D(pixelCenterX, pixelCenterY, t.v);
                float w_reciprocal = 1.0f / (alpha / v[0].w() + beta / v[1].w() + gamma / v[2].w());
                float z_interpolated = alpha * v[0].z() / v[0].w() + beta * v[1].z() / v[1].w() + gamma * v[2].z() / v[2].w();
                z_interpolated *= w_reciprocal;

                int index = get_index(x, y);

                // Update depth buffer and set pixel color if the current pixel is closer to the camera.
                if (z_interpolated > depth_buf[index])
                {
                    depth_buf[index] = z_interpolated;

                    set_pixel(Eigen::Vector3f(x, y, 0), t.getColor());
                }
            }
        }
    }
}