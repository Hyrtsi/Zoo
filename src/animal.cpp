#include "animal.hpp"

void Animal::print(void)
{
  printf("%s %s %d\n", _name.c_str(), _favoriteFood.c_str(), _friends.size());
}