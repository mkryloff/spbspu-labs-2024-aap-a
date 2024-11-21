#include <ios>
#include <iostream>
#include "isexpression.hpp"
#include "geline.hpp"

int main()
{
  constexpr char stop = '\n';
  char * line = nullptr;
  try
  {
    line = brevnov::getline(std::cin, stop);
  }
  catch(const std::bad_alloc& e)
  {
    std::cerr << "Not enough memory\n";
    return 1;
  }
  if (*line == 0)
  {
    std::cerr << "Empty input\n";
    delete[] line;
    return 1;
  }
  std::cout << std::boolalpha << brevnov::isExpression(line) << "\n";
  return 0;
}
