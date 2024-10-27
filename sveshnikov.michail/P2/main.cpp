#include "taylor.hpp"

int main()
{
  double left = 0.0, right = 0.0;
  size_t k = 0;
  std::cin >> left >> right >> k;
  if (!std::cin)
  {
    std::cerr << "ERROR: the input could not be recognized\n";
    return 1;
  }
  try
  {
    if (left <= -1 || right >= 1)
    {
      throw std::logic_error("the interval is incorrect");
    }
  }
  catch (const std::logic_error &e)
  {
    std::cerr << "ERROR: the interval is incorrect\n";
    return 1;
  }
  sveshnikov::table(left, right, k);
  return 0;
}
