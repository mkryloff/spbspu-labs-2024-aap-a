#ifndef SHAPE_HPP
#define SHAPE_HPP
#include <memory>
#include "base-types.hpp"

namespace hismatova
{
  class shape
  {
  public:
    virtual ~shape() = default;
    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual void move(double dx, double dy) = 0;
    virtual void move(const point_t& newPos) = 0;
    virtual void scale(double index) = 0;
  };
}

#endif
