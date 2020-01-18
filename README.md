# Zoo

## Problem

The task is to create an application that
- Holds a database of a zoo with different kinds of animals
- Edits relationships (friendship) between animals according to rules
- Prints relevant data to the console
- Allows user input via console

## Design

### Challenges 

Several challenges were faced solving this puzzle. The following paragraph discusses what choices has been done and why.

- There are different kinds of animals with different kinds of properties. One must be able to conveniently add them to the database and print their properties. The correct properties must be printed: dog doesn't have wingspan, for instance.

It seems that all animals have name, favorite food and friends. Each dog has dog type property. Each bird has a wingspan. Parrots can or can not speak. Chickens have a property to be broiler. This sense of hierarchy suggests that using inheritance is *possible*. It makes sense as we assume that all animals belong to one and only one base class. Thus, we should not face the multiple inheritance problem or any other inherent problem ("feature") of inheritance.

The goal is to be able to initialize each animal with appropriate arguments according to their type but still be able to store them into the same data structure for being able to traverse them easily (list of animals).

How to let the class "know" its type (Dog, Parrot,...) and thus print the correct properties? There are many options:
- Templated function overloads
- Let class own a number of generic properties and each property is able to return itself as a string for printing
- Use virtual functions to make custom behavior for each animal (if one uses inheritance, this is the way to go)

- There must be some data structure that contains the information of the friends of the animal. The structure must be convenient to read and write

One could model the friends of all animals as a graph: one node for each animal, connections between nodes represent friendship. Then, interactions that change friendship change the connections.

A way to implement this is to set up a `n x n` matrix where each cell represents whether there is a friendship between two animals. For instance, `friends[i][j]` is `1` if animal `i` and `j` are friends. The matrix would be symmetrical along the diagonal so there would also be obsolete information in the data structure. In a considerably big zoo, the data structure could be flattened into 1D vector for faster search.

This seemed overkill (and especially *boring*) at first so in the end the friendship was modeled with simply having list of animal IDs in a vector and editing that accordingly upon friendship updates.

### Details

As inheritance is used, let `Animal` be the base class which is inherited by `Dog` and `Bird`. Moreover, `Bird` is inherited by `Chicked` and `Parrot`. As we want to have a way to pick a specific animal regardless of its derived class, we have an unordered map where the key is `AnimalID` and the value is pointer to the `Animal` instance. `AnimalID`s are unique for each animal and they may be accessed in various data structures using this. It is cleaner to use the ID than passing around the pointer to the data in every interface.

### Program flow

The animal data resides inside the scope of `main`. It could be inside `Zoo` but I didn't find that necessary in the context of this assignment. Doing it this way is safe: it ensures that the lifetime of the data is at least the lifetime of everyone using it.

After setting up the zoo, the program polls for user input until it gets exit. It is ensured that the user does not input anything else than the desired commands.

`printAnimals` will traverse the animal map and print the properties of the animals using the implementation of the appropriate derived class. After that, it will use a common function to print the friends as every animal holds the list of friends.

`liveDay` will traverse the animal map and first try to remove a random friend from the list of friends of the animal, if any. If it removes a friend, also the occurrence of this animal is removed from the list of its friend. Then, similarly, random friend is tried to be added to the animal if it is not already friend of all animals. If friend is added, it is done for both animals: the friend lists for both animals are updated as friendship is commutative.

### Discussion on this solution

One could have used [CRTP](https://en.wikipedia.org/wiki/Curiously_recurring_template_pattern) instead

One could have used [ECS](https://en.wikipedia.org/wiki/Entity_component_system) like [this one](https://github.com/Lehdari/TemplateECS)

I tried to avoid overkill solutions for this (seemingly) simple task. However, I don't think I ended up with an **elegant** solution after all.

The zoo in this task is 7 animals, so I didn't even bother to think the time complexity of searches in the data structures. If there would have been a note on scalability in the problem poster, I would have done this probably differently and benchmarked different options.

### Known limitations/"features"

- In a day, animal may lose a friend and get the same friend back instantly

## Installation (Ubuntu)

### Requirements
- Git
- CMake (3.10 was used in testing, probably older will do)
- C++ 14 -compatible compiler (g++ 7.4.0 was used in testing)

```bash
git clone https://github.com/Hyrtsi/Zoo.git
cd Zoo
mkdir build
cd build
cmake ..
make
```

## Usage

After build,

```bash
./Zoo
```

Instructions are printed to console. Press keys 1-3 to use the program.

## Tests

Last but not least. How this program was verified. As it is dealing with functions that have side effects by nature (printing to console) and randomness, I didn't think unit tests make sense for many functions.

Things that may be tested automatically
- `animal.hpp`: Create instance of an animal with known list of friends instead of empty list OR use `setFriendship`. Check with `isFriendWith` and `nFriends` that the results are according to what was set
- `zoo.hpp`: Amount of friends for a given animal should change after `tryAddRandomFriend` and `tryRemoveRandomFriend` unless the animal had 0/max friends. `liveDay` should increase amount of friends 

Manual tests
- Feeding valid and invalid inputs to the program
- Iterating many many days and checking if the amount of friends goes out of bounds or something else in prints seems out of place
- Checking if the number of friends changes according the prints after a day
- Checking that properties are correct for each animal
