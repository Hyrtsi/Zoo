#include "animal.hpp"
#include <algorithm>

bool Animal::isFriendWith(AnimalID animal)
{
  for (auto& friendID : _friends)
  {
    if (friendID == animal)
    {
      return true;
    }
  }
  return false;
}

void Animal::setFriendship(AnimalID animal, bool status)
{
  bool isFriendCurrently = isFriendWith(animal);
  if (!isFriendCurrently && status)
  {
    // add as friend
    _friends.push_back(animal);
  }
  else if (isFriendCurrently && !status)
  {
    // remove from friends
    _friends.erase(std::remove(_friends.begin(), _friends.end(), animal), _friends.end());
  }
}

AnimalID Animal::loseOneRandomFriend(void)
{
  // Take random number from 0 to nFriends
  int64_t randIndex = rand() % _friends.size();

  AnimalID lostFriendID = _friends[randIndex];

  // Lose the random friend
  setFriendship(lostFriendID, false);

  return lostFriendID;
}

size_t Animal::nFriends(void)
{
  return _friends.size();
}

void Animal::printFriends(const std::unordered_map<AnimalID, Animal*>& animalMap)
{
  printf("Friends of %s are:\n", _name.c_str());
  for (auto& friendID : _friends)
  {
    auto animalPtr = animalMap.at(friendID);
    printf("%s\n", animalPtr->name().c_str());
  }

  printf("\n");
}

const std::string Animal::name(void) const
{
  return _name;
}