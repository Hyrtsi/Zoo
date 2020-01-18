#ifndef PARROT_HPP
#define PARROT_HPP

#include "bird.hpp"

class Parrot : public Bird
{
public:
  Parrot(const std::string name, const std::string favoriteFood,
          double wingSpan, bool canSpeak,
          const std::vector<AnimalID>& friends = std::vector<AnimalID>()) :
    Bird(name, favoriteFood, wingSpan, friends),
    _canSpeak(canSpeak)
  {
  }

  void print(void);
private:
  bool _canSpeak;
};

#endif // PARROT_HPP
