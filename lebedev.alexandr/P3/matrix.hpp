#ifndef TABLE_HPP
#define TABLE_HPP
#include <fstream>
namespace lebedev
{
std::istream& input(std::istream& inputFile, int* arr, size_t m);
void output(std::ostream& outputFile, const int* arr, size_t m);
}
#endif
