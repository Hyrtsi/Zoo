#ifndef ZOO_HPP
#define ZOO_HPP

#include "animal.hpp"
#include <unordered_map>

class Zoo
{
  public:
    Zoo(void) {};

    // Print all animals, their properties and friends
    void printAnimals(void);

    // Update the friends of all animals; print changes
    void liveDay(void);

    void addAnimal(Animal* animal);
    
  private:
    std::vector<Animal*> _animals;
    std::unordered_map<AnimalID, Animal*> _animalMap;
    AnimalID _runningID;
    void editFriendship(Animal* animal1, Animal* animal2, bool isFriend);
};

#endif // ZOO_HPP
