#include "animal.hpp"

#include <iostream>

#include "zoo.hpp"

int main(int argc, char *argv[])
{
  std::cout << "Hello World!" << std::endl;

  Animal foo("kissa", "kala", std::vector<AnimalID>());
  
  Zoo zoo;

  zoo.addAnimal(Animal("Dog one", "Meat")); // todo dog type??
  zoo.addAnimal(Animal("Parrot one", "Grain")); // todo wingspan??
  zoo.addAnimal(Animal("Chicken one", "Corn"));
  zoo.addAnimal(Animal("Dog two", "Fresh meat"));

  zoo.printAnimals();


  return 0;
}