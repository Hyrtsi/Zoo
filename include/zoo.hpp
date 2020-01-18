#ifndef ZOO_HPP
#define ZOO_HPP

#include "animal.hpp"

class Zoo
{
  public:
    Zoo(void) {};

    // necessary...?
    //Zoo(std::vector<Animal> animals);

    // Print all animals, their properties and friends
    void printAnimals(void);

    // Update the friends of all animals; print changes
    void liveDay(void);

    void addAnimal(Animal animal);

  private:
    std::vector<Animal> _animals;
};

#endif // ZOO_HPP
