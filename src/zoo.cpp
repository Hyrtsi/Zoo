#include "zoo.hpp"
#include <stdio.h>
#include <algorithm> // for each

void Zoo::printAnimals(void)
{
  std::for_each(_animalMap.begin(), _animalMap.end(),
                [&](std::pair<AnimalID, Animal*> elem)
  {
    elem.second->printProperties();

    elem.second->printFriends(_animalMap);
  });
}

void Zoo::liveDay(void)
{
  std::for_each(_animalMap.begin(), _animalMap.end(),
                [&](std::pair<AnimalID, Animal*> animalData)
  {
    // Copies are fine since it's just some ID we're not going to change
    // and it's some ptr we're not going to change (however, contents are modified...)
    AnimalID animalID = animalData.first;
    Animal* animal = animalData.second;

    tryRemoveRandomFriend(animalID, animal);
    tryAddRandomFriend(animalID, animal);
  });

}

void Zoo::addAnimal(Animal* animal)
{
  _animalMap[_runningID] = animal;
  _animalIDs.push_back(_runningID);

  ++_runningID;
}

void Zoo::tryAddRandomFriend(AnimalID animalID, Animal* animal)
{
  if (animal->nFriends() >= _animalMap.size() - 1)
  {
    // Already friend of everyone(expect oneself)
    return;
  }

  // Loop until found an animal that
  // (1) is not self
  // (2) is not yet a friend

  bool foundNewFriend = false;
    
  while (!foundNewFriend)
  {
    // Take random number from 0 to nFriends
    int64_t randIndex = rand() % _animalIDs.size();
    AnimalID newFriendCandidateID = _animalIDs[randIndex];

    // Check that it's not self
    // Check if it's a new friend
    if ((newFriendCandidateID != animalID)
        && !animal->isFriendWith(newFriendCandidateID))
    {
      animal->setFriendship(newFriendCandidateID, true);
        
      // set also the other way around...

      _animalMap[newFriendCandidateID]->setFriendship(animalID, true);

      printf("%s has establised friendship with %s\n",
              _animalMap.at(animalID)->name().c_str(),
              _animalMap.at(newFriendCandidateID)->name().c_str());

      foundNewFriend = true;
    }
  }

}

void Zoo::tryRemoveRandomFriend(AnimalID animalID, Animal* animal)
{
  if (animal->nFriends() > 0)
  {
    AnimalID lostFriend = animal->loseOneRandomFriend();
    _animalMap[lostFriend]->setFriendship(animalID, false);

    printf("%s has lost friendship with %s\n",
           _animalMap.at(animalID)->name().c_str(),
           _animalMap.at(lostFriend)->name().c_str());
  }
}