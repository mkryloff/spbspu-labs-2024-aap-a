#include <iostream>
#include <cstdlib>
#include <fstream>
#include "input_matrix.h"
#include "output_matrix.h"

int main(int argc, char ** argv)
{
  if (argc > 4)
  {
    std::cerr << "Too many arguments" << "\n";
    return 1;
  }
  else if (argc == 0)
  {
    std::cerr << "Not enough arguments" << "\n";
    return 1;
  }
  else if (argc < 3)
  {
    std::cerr << "Too few arguments" << "\n";
    return 1;
  }
  long int num = 0;
  const char *str = argv[1];
  char* endptr;
  num = std::strtol(str, &endptr, 10);
  if (num != 1 && num != 2)
  {
    std::cerr << "First parameter is out of range" << "\n";
    return 1;
  }
  size_t strk = 0;
  size_t stl = 0;
  size_t size_matrix = 0;
  std::ifstream input(argv[2]);
  input >> strk >> stl;
  if (!input)
  {
    std::cerr << "Not a matrix" << "\n";
    return 2;
  }
  size_matrix = strk * stl;
  int matrix[10000];
  std::ofstream output(argv[2]);
  if (num == 1)
  {
    input_matrix(std::cin, matrix, size_matrix);
    output_matrix(std::cout, matrix, strk, stl);
  }
  if (num == 2)
  {
    int *dynamic_matrix = new int[size_matrix];
    input_matrix(std::cin, dynamic_matrix, size_matrix);
    output_matrix(std::cout, dynamic_matrix, strk, stl);
    delete[] dynamic_matrix;
  }
}
