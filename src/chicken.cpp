#include "chicken.hpp"

void Chicken::print(void)
{
  const std::string broilerStr = (_isBroiler) ? "is broiler" : "is not broiler";
  printf("%s, favorite food %s, %d friends, wingspan %.2f, %s\n",
         _name.c_str(),
         _favoriteFood.c_str(),
         _friends.size(),
         _wingSpan,
         broilerStr.c_str());
}