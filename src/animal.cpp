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