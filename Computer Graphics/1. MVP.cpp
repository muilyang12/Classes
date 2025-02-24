/*
    4x4 transformation matrix for rotation around the Z-axis.

    Formula
    [cos θ  -sin θ  0   0]
    [sin θ  cos θ   0   0]
    [0      0       1   0]
    [0      0       0   1]
*/

Eigen::Matrix4f getModelMatrix(float rotationAngleZ)
{
    Eigen::Matrix4f model = Eigen::Matrix4f::Identity();

    float rad = DEG2RAD(rotationAngleZ);
    float cosTheta = std::cos(rad);
    float sinTheta = std::sin(rad);

    model(0, 0) = cosTheta;
    model(0, 1) = -sinTheta;
    model(1, 0) = sinTheta;
    model(1, 1) = cosTheta;

    return model;
}

/*
    4x4 perspective projection matrix.

    [n/r    0       0               0]
    [0      n/t     0               0]
    [0      0       -(f+n)/(f-n)    -2fn/(f-n)]
    [0      0       -1              0]

    - 'n' = -zNear (negative due to camera space conventions).
    - 'f' = -zFar (negative due to camera space conventions).
    - 't' = n * tan(fov/2), the top of the frustum in camera space.
    - 'r' = t * aspectRatio, the right side of the frustum in camera space.
*/
Eigen::Matrix4f getProjectionMatrix(float eyeFov, float aspectRatio,
                                    float zNear, float zFar)
{
    Eigen::Matrix4f projection = Eigen::Matrix4f::Identity();

    float n = -zNear;
    float f = -zFar;

    float eyeFovRad = DEG2RAD(eyeFov);
    float t = n * std::tan(eyeFovRad / 2);
    float r = t * aspectRatio;

    projection(0, 0) = n / r;

    projection(1, 1) = n / t;

    projection(2, 2) = -(f + n) / (f - n);
    projection(2, 3) = -2 * f * n / (f - n);

    projection(3, 2) = -1;
    projection(3, 3) = 0;

    return projection;
}