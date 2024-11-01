#include "input_matrix.h"
#include <stdexcept>

void input_matrix(std::istream & in, int *matrix, size_t size_matrix)
{
  for (size_t i = 0; i < size_matrix; i++)
  {
    in >> matrix[i];
  }
  if (!in)
  {
    throw std::logic_error("input fail");
  }
}
