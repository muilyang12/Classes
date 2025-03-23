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
