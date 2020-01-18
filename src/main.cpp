#include "animal.hpp"

#include <iostream>

int main(int argc, char *argv[])
{
  std::cout << "Hello World!" << std::endl;

  Animal foo("kissa", "kala", std::vector<AnimalID>());
  
  return 0;
}