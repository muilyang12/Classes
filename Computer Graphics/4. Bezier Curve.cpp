/*
  Bezier Curve

  A Bezier curve is a mathematical method for drawing smooth curves using one or more control points. It is widely used
  in vector graphic tools, font design, and animation.
*/

/*
  Naive Bezier

  The most basic form of a cubic Bezier curve is defined using four control points (C0, C1, C2, and C3) and is expressed
  by the following formula.

  B(t) = (
    (1 - t)^3 * P0
    + 3 * t * (1 - t)^2 * P1
    + 3 * t^2 * (1 - t) * P2
    + t^3 * P3
  )
  where 0 <= t <= 1.
*/
void naive_bezier(const std::vector<cv::Point2f> &points, cv::Mat &window)
{
  auto &p0 = points[0];
  auto &p1 = points[1];
  auto &p2 = points[2];
  auto &p3 = points[3];

  for (double t = 0.0; t <= 1.0; t += 0.001)
  {
    auto point = std::pow(1 - t, 3) * p0 + 3 * t * std::pow(1 - t, 2) * p1 +
                 3 * std::pow(t, 2) * (1 - t) * p2 + std::pow(t, 3) * p3;

    window.at<cv::Vec3b>(point.y, point.x)[2] = 255;
  }
}

/*
  De Casteljau's Algorithm for Bezier Curve

  The De Casteljau's algorithm is an alternative method for computing Bézier curves.

  Unlike the naive Bezier approach, this method computes the point on the curve through multiple stages. At each stage, it
  performs interpolation only between adjacent points. By recursively repeating this process to compute the next level of
  points, it ultimately produces a single point on the curve.

  Since it does not involve higher-degree terms like (1 - t)^3 or t^3 used in the naive Bezier method, De Casteljau's
  algorithm is more numerically stable and more flexible when working with a larger number of control points.
*/
void bezier(const std::vector<cv::Point2f> &control_points, cv::Mat &window)
{
  for (double t = 0.0; t <= 1.0; t += 0.001)
  {
    cv::Point2f point = recursive_bezier(control_points, static_cast<float>(t));

    // Convert coordinates to integers, and clamp them to valid image pixel positions.
    int px = std::clamp(static_cast<int>(std::round(point.x)), 0, window.cols - 1);
    int py = std::clamp(static_cast<int>(std::round(point.y)), 0, window.rows - 1);

    window.at<cv::Vec3b>(py, px)[1] = 255;
  }
}

cv::Point2f recursive_bezier(const std::vector<cv::Point2f> &control_points,
                             float t)
{
  if (control_points.size() == 1)
  {
    return control_points[0];
  }

  // Create a new list of control points for the next stage. Since we interpolate between adjacent points, the new list will
  // have (size - 1) points.
  std::vector<cv::Point2f> nextLevel;
  nextLevel.reserve(control_points.size() - 1);

  // Iterate over all adjacent point pairs (P0 & P1, P1 & P2, ..., Pn-2 & Pn-1)
  for (size_t i = 0; i < control_points.size() - 1; i++)
  {
    float x = (1 - t) * control_points[i].x + t * control_points[i + 1].x;
    float y = (1 - t) * control_points[i].y + t * control_points[i + 1].y;

    // Add the interpolated point to the new list of control points for the next stage.
    nextLevel.push_back(cv::Point2f(x, y));
  }

  return recursive_bezier(nextLevel, t);
}