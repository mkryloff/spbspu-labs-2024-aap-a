#include <iostream>
#include <fstream>
#include <cstdlib>
#include "matrix.hpp"

int main(int argc, char **argv)
{
  if (argc > 4)
  {
    std::cerr << "Too many arguments\n";
    return 1;
  }
  if (argc < 4)
  {
    std::cerr << "Not enough arguments\n";
    return 1;
  }
  if (atoi(argv[1]) > 2 || atoi(argv[1]) < 1)
  {
    std::cerr << "First parameter is out of range\n";
    return 1;
  }
  std::ifstream input(argv[2]);
  std::ofstream output(argv[3]);
  int nums[10000] = {};
  size_t m = 0;
  size_t n = 0;
  size_t read = 0;
  if (atoi(argv[1]) == 1)
  {
    input >> m >> n;
    abramov::input_matrix(input, nums, m, n, read);
    abramov::output_matrix(output, nums, m, n);
  }
  else if (atoi(argv[2]) == 2)
  {
    input >> m >> n;
    int *matrix = nullptr;
    try
    {
      matrix = new int[m * n];
    }
    catch (const std::bad_alloc &e)
    {
      std::cerr << "Memory fail\n";
      return 2;
    }
    abramov::input_matrix(input, matrix, m, n, read);
    abramov::output_matrix(output, matrix, m, n);
  }
}
