#include "matrix.hpp"

std::istream& lebedev::input(std::istream& inputFile, int* arr, size_t m)
{
  for (size_t i = 0; i < m * m; ++i)
  {
    inputFile >> arr[i];
  }
  return inputFile;
}

void lebedev::output(std::ostream& outputFile, const int* arr, size_t m)
{
  bool flag = true;
  for (size_t i = 0; i < m; ++i)
  {
    for (size_t j = i + 1; j < m; ++j)
    {
      if (arr[i * m + j] != 0)
      {
        flag = false;
        break;
      }
    }
  }
  if (flag && m > 1)
  {
    outputFile << "true" << '\n';
  }
  else
  {
    outputFile << "false" << '\n';
  }
}
