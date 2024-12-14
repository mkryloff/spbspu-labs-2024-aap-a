#include "rectangle.hpp"
#include <stdexcept>

krylov::Rectangle::Rectangle(const point_t& bottomLeft, const point_t& topRight):
  bottomLeft_(bottomLeft),
  topRight_(topRight)
{
  if (bottomLeft_.x >= topRight_.x || bottomLeft_.y >= topRight_.y)
  {
      throw std::invalid_argument("Invalid rectangle coordinates");
  }
}

double krylov::Rectangle::getArea() const
{
    return (topRight_.x - bottomLeft_.x) * (topRight_.y - bottomLeft_.y);
}

rectangle_t krylov::Rectangle::getFrameRect() const
{
  return {topRight_.x - bottomLeft_.x, topRight_.y - bottomLeft_.y,
          {(bottomLeft_.x + topRight_.x) / 2, (bottomLeft_.y + topRight_.y) / 2}};
}

void krylov::Rectangle::move(const point_t& point)
{
  double dx = point.x - (bottomLeft_.x + topRight_.x) / 2;
  double dy = point.y - (bottomLeft_.y + topRight_.y) / 2;
  move(dx, dy);
}

void krylov::Rectangle::move(double dx, double dy)
{
  bottomLeft_.x += dx;
  bottomLeft_.y += dy;
  topRight_.x += dx;
  topRight_.y += dy;
}

void krylov::Rectangle::scale(double factor)
{
  if (factor <= 0)
  {
    throw std::invalid_argument("Scale factor must be positive");
  }
  point_t center = {(bottomLeft_.x + topRight_.x) / 2, (bottomLeft_.y + topRight_.y) / 2};
  bottomLeft_.x = center.x + (bottomLeft_.x - center.x) * factor;
  bottomLeft_.y = center.y + (bottomLeft_.y - center.y) * factor;
  topRight_.x = center.x + (topRight_.x - center.x) * factor;
  topRight_.y = center.y + (topRight_.y - center.y) * factor;
}
