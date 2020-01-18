#include <iostream>
#include "animal.hpp"
#include "zoo.hpp"
#include "dog.hpp"

int main(int argc, char *argv[])
{
  std::cout << "Hello World!" << std::endl;

  Zoo zoo;

  Dog dog1("Dog one", "Meat", "Hunting dog");
  Dog dog2("Dog two", "Fresh meat", "Assistance dog");
  zoo.addAnimal(&dog1);
  zoo.addAnimal(&dog2);

  zoo.printAnimals();

  zoo.printAnimals();

  return 0;
}