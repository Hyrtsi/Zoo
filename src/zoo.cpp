#include "zoo.hpp"
#include <stdio.h>
#include <algorithm> // for each

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
