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
  // as all friend stuff is commutative, the isfriendcurrently
  // should not be checked always two times...
  // maybe remove it from here... and assume that it's checked
  // on caller site?

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

void Animal::printFriends(void)
{
  printf("Friends of %s are: ", _name.c_str());
  for (auto& friendID : _friends)
  {
    printf("%ld ", friendID);
  }

  printf("\n\n");
}