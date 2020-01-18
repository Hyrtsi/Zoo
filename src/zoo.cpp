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
                [&](std::pair<AnimalID, Animal*> animalData)
  {
    // Copies are fine since it's just some ID we're not going to change
    // and it's some ptr we're not going to change (however, contents are modified...)
    AnimalID animalID = animalData.first;
    Animal* animal = animalData.second;

    printf("Updating animal %ld\n", animalID);

    if (animal->nFriends() > 0)
    {
      AnimalID lostFriend = animal->loseOneRandomFriend();
      _animalMap[lostFriend]->setFriendship(animalID, false);
      printf("Animal %ld lost friend %ld\n", animalID, lostFriend);
    }


    // Surf all animals randomly? until found non-friend...

   // _animalMap.size();

  });

}

void Zoo::addAnimal(Animal* animal)
{
  _animalMap[_runningID] = animal;
  ++_runningID;
}

void Zoo::editFriendship(Animal* animal1, Animal* animal2, bool isFriend)
{

}
