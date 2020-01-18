#include "zoo.hpp"
#include <stdio.h>
#include <algorithm> // for each

#include "dog.hpp"
#include "chicken.hpp"
#include "parrot.hpp"

void Zoo::initializeZoo(void)
{
  //std::unique_ptr<Dog> ptr = std::make_unique<Dog>("Dog one", "Meat", "Hunting dog");
  //addAnimal(ptr);

  //Dog dog1("Dog one", "Meat", "Hunting dog");
  //Dog dog2("Dog two", "Fresh meat", "Assistance dog");
  //Dog dog3("Dog three", "Pedigree", "Racing dog");
  //Chicken chicken1("Chicken one", "Corn", 0.75, true);
  //Chicken chicken2("Chicken two", "Corn", 0.75, false);
  //Parrot parrot1("Parrot one", "Grain", 0.25, false);
  //Parrot parrot2("Parrot two", "Corn", 0.50, true);

  //addAnimal(&dog1);
  //addAnimal(&dog2);
  //addAnimal(&dog3);
  //addAnimal(&chicken1);
  //addAnimal(&chicken2);
  //addAnimal(&parrot1);
  //addAnimal(&parrot2);
}


void Zoo::printAnimals(void)
{
  std::for_each(_animalMap.begin(), _animalMap.end(),
                [](std::pair<AnimalID, Animal*> elem)
  {
    printf("%ld:", elem.first);
    elem.second->print();
  });
}

void Zoo::liveDay(void)
{
  //for (auto& animal : _animals)
  //{
  //  // Make one random friend
  //  // That is, take one random animal from list of all animals
  //  // until found one that is not yet friend with this one
  //  // Add friends to both



  //  // Lose one random friend
  //  // same but vice versa...
  //}

  std::for_each(_animalMap.begin(), _animalMap.end(),
                [](std::pair<AnimalID, Animal*> elem)
  {
    printf("%ld:", elem.first);
    elem.second->print();
  });

}

void Zoo::addAnimal(Animal* animal)
{
  _animals.push_back(animal);

  _animalMap[_runningID] = animal;
  ++_runningID;
}

void Zoo::editFriendship(Animal* animal1, Animal* animal2, bool isFriend)
{

}
