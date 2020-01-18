#include <iostream>
#include "animal.hpp"
#include "zoo.hpp"
#include "dog.hpp"
#include "chicken.hpp"

int main(int argc, char *argv[])
{
  std::cout << "Hello World!" << std::endl;

  Zoo zoo;

  Dog dog1("Dog one", "Meat", "Hunting dog");
  Dog dog2("Dog two", "Fresh meat", "Assistance dog");
  Chicken chicken1("Chicken one", "Corn", 0.75, true);
  zoo.addAnimal(&dog1);
  zoo.addAnimal(&dog2);
  zoo.addAnimal(&chicken1);

  zoo.printAnimals();

  zoo.printAnimals();

  return 0;
}