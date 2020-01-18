#include "animal.hpp"
#include "zoo.hpp"
#include "dog.hpp"
#include "chicken.hpp"
#include "parrot.hpp"

#include <time.h>
#include <iostream>
#include <cctype>

bool pollCommands(Zoo& zoo);

int main(int argc, char *argv[])
{
  srand(time(NULL));

  // Initialize zoo

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

  // Poll for user input
  bool gotExit = false;
  while (!gotExit)
  {
    gotExit = pollCommands(zoo);
  }
  
  printf("Exiting program\n");

  return 0;
}

bool pollCommands(Zoo& zoo)
{
  printf("\nPlease enter the next command.\n"
         "1 = List all animals, properties and friends\n"
         "2 = Live one day and update friendships\n"
         "3 = Exit\n");

  std::string commandStr;
  std::cin >> commandStr;

  if (!std::cin)
  {
    return false;
  }

  bool gotExit = false;
  int32_t command = std::atoi(commandStr.c_str());

  if (command == 1)
  {
    // List all animals
    printf("\n");
    zoo.printAnimals();
  }
  else if (command == 2)
  {
    // Live one day
    printf("\n");
    zoo.liveDay();
  }
  else if (command == 3)
  {
    // Exit
    gotExit = true;
  }
  else
  {
    // Invalid input
    printf("Please enter a valid input (integer, 1,2 or 3)!\n");
  }

  return gotExit;
}
