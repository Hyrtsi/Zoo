#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <inttypes.h>
#include <vector>
#include <string>
#include <unordered_map>
#include <random>

typedef int64_t AnimalID;

class Animal
{
public:
  Animal(const std::string name, const std::string favoriteFood,
         const std::vector<AnimalID>& friends = std::vector<AnimalID>()) :
    _name(name), _favoriteFood(favoriteFood), _friends(friends) { }

  virtual void printProperties(void) = 0;
  
  void printFriends(std::unordered_map<AnimalID, Animal*>& animalMap);

  bool isFriendWith(AnimalID animal);

  void setFriendship(AnimalID animal, bool status);

  AnimalID loseOneRandomFriend(void);
  size_t nFriends(void);

  const std::string name(void) const;

protected:
  const std::string _name;
  const std::string _favoriteFood;
  std::vector<AnimalID> _friends;

};

#endif // ANIMAL_HPP