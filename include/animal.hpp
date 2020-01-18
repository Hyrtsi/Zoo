#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <inttypes.h>
#include <vector>
#include <string>

typedef int64_t AnimalID;

class Animal
{
public:
  Animal(const std::string name, const std::string favoriteFood,
         const std::vector<AnimalID>& friends = std::vector<AnimalID>()) :
    _name(name), _favoriteFood(favoriteFood), _friends(friends) { }

  virtual void print(void) = 0;

  bool isFriendWith(AnimalID animal);

  void setFriendship(AnimalID animal, bool status);

  AnimalID loseOneRandomFriend(void);
  size_t nFriends(void);

protected:
  const std::string _name;
  const std::string _favoriteFood;
  std::vector<AnimalID> _friends;

};

#endif // ANIMAL_HPP