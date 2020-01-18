#ifndef CHICKEN_HPP
#define CHICKEN_HPP

#include "bird.hpp"

class Chicken : public Bird
{
public:
  Chicken(const std::string name, const std::string favoriteFood,
      double wingSpan, bool isBroiler,
      const std::vector<AnimalID>& friends = std::vector<AnimalID>()) :
    Bird(name, favoriteFood, wingSpan, friends),
    _isBroiler(isBroiler)
  {
  }

  void printProperties(void);

private:
  bool _isBroiler;
};

#endif // CHICKEN_HPP
