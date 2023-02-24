#include <iostream>
#include <string>

using namespace std;

/* 

* studying for test 1 on 2/23/23 at 12:00 PM *

20 MCQ 75% of the total points
3 programming questions 25% of points

NO notes! syntax mistakes are okay!

items that could be on the test:
- class, public, private, try, catch, throw,
  friend, const, operator, the this variable

vocabulary:
- subclass, superclass, data members/attributes, 
  functional members/methods, inheritance,

  (not on this test: aggregation, composition,
   derivation)

coding concepts:
- pass by reference vs. pass by value
- mixing const in with pass by reference
    class:
    - realize that pass by value, pass by reference,
    const pass by reference can be used in class
    functional members (methods)


*/

class Animal {
    string sound;
    string commonName;
    string scientificName;
    public:
    Animal(string newCommonName, string newScientificName="", string newSound="") {
        sound = newSound;
        commonName = newCommonName;
        scientificName = newScientificName;
    }
    void output() {
        cout << commonName << ' ' << scientificName << " makes sound of "
        << sound << endl;     
    }
    void setSound(string newSound) {
        // Question 1: 1 pt
        sound = newSound;
    }
    void setCommonName(string newCommonName) {
        commonName = newCommonName;
    }
    // Question 2: 3 pt
    // Write a function setScientific name that takes a string and sets the
    // instances scientificName attribute.
    void setScientificName(string newScientificName) {
        scientificName = newScientificName;
    }

};

// Question 3: 5 pt
// Write a class Mammal that is derived from Animal and defaults the
// sound to roar

/*on test*/ class Mammal: public Animal {
    public:
    Mammal (string newCommonName, string newScientificName="", string newSound="roar") : 
/*not on test*/    Animal(newCommonName, newScientificName, newSound) {

    }

};

int main() {

    Animal a("cat");
    a.setSound("meow");
    a.setCommonName("kitty");
    a.setScientificName("felis catus");
    a.output();
    Mammal d("dog");
    d.output();

    
    return 0;
}

