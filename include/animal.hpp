#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <cstdint> // fixed width integer types
#include <vector>
#include <string>

typedef int64_t AnimalID;

class Animal
{
public:
  Animal(const std::string name, const std::string favoriteFood,
         const std::vector<AnimalID>& friends = std::vector<AnimalID>()) :
    _name(name), _favoriteFood(favoriteFood), _friends(friends) { }

  void print(void);

private:
  const std::string _name;
  const std::string _favoriteFood;
  std::vector<AnimalID> _friends;
};

#endif // ANIMAL_HPP