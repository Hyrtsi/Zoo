#include "dog.hpp"

void Dog::print(void)
{
  printf("%s, favorite food %s, %d friends, type %s\n",
         _name.c_str(),
         _favoriteFood.c_str(),
         _friends.size(),
         _dogType.c_str());
}