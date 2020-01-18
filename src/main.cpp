#include "animal.hpp"
#include "zoo.hpp"
#include "dog.hpp"
#include "chicken.hpp"
#include "parrot.hpp"

#include <time.h>


int main(int argc, char *argv[])
{
  srand(time(NULL));


  Zoo zoo;

  Dog dog1("Dog one", "Meat", "Hunting dog");
  Dog dog2("Dog two", "Fresh meat", "Assistance dog");
  Dog dog3("Dog three", "Pedigree", "Racing dog");
  Chicken chicken1("Chicken one", "Corn", 0.75, true);
  Chicken chicken2("Chicken two", "Corn", 0.75, false);
  Parrot parrot1("Parrot one", "Grain", 0.25, false);
  Parrot parrot2("Parrot two", "Corn", 0.50, true);

  zoo.addAnimal(&dog1);
  zoo.addAnimal(&dog2);
  zoo.addAnimal(&dog3);
  zoo.addAnimal(&chicken1);
  zoo.addAnimal(&chicken2);
  zoo.addAnimal(&parrot1);
  zoo.addAnimal(&parrot2);

  zoo.printAnimals();
  
  printf("\n");

  zoo.liveDay();


  return 0;
}