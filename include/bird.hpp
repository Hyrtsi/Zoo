#ifndef BIRD_HPP
#define BIRD_HPP

#include "animal.hpp"

class Bird : public Animal
{
public:
  Bird(const std::string name, const std::string favoriteFood,
      double wingSpan,
      const std::vector<AnimalID>& friends = std::vector<AnimalID>()) :
    Animal(name, favoriteFood, friends),
    _wingSpan(wingSpan)
  {
  }

  void printProperties(void) = 0;

protected:
  double _wingSpan;
};

#endif // BIRD_HPP
