#ifndef ZOO_HPP
#define ZOO_HPP

#include "animal.hpp"
#include <unordered_map>

class Zoo
{
  public:
    Zoo(void) : _runningID(0L) { };

    // Print all animals, their properties and friends
    void printAnimals(void);

    // Update the friends of all animals; print changes
    void liveDay(void);

    void addAnimal(Animal* animal);
    
    void tryAddRandomFriend(AnimalID animalID, Animal* animal);

    void tryRemoveRandomFriend(AnimalID animalID, Animal* animal);

  private:
    std::unordered_map<AnimalID, Animal*> _animalMap;
    std::vector<AnimalID> _animalIDs;
    AnimalID _runningID;
};

#endif // ZOO_HPP
