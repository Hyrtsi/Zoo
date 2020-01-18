#include "parrot.hpp"

void Parrot::print(void)
{
  const std::string canSpeakStr = (_canSpeak) ? "can speak" : "cannot speak";
  printf("%s, favorite food %s, %d friends, wingspan %.2f, %s\n",
         _name.c_str(),
         _favoriteFood.c_str(),
         _friends.size(),
         _wingSpan,
         canSpeakStr.c_str());
}