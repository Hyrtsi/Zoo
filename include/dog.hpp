#ifndef DOG_HPP
#define DOG_HPP

#include "animal.hpp"


class Dog : public Animal
{
public:
  Dog(const std::string name, const std::string favoriteFood,
      const std::string dogType,
      const std::vector<AnimalID>& friends = std::vector<AnimalID>()) :
    Animal(name, favoriteFood, friends),
    _dogType(dogType) {}


  void print(void);
private:
  const std::string _dogType;
};

#endif // DOG_HPP
