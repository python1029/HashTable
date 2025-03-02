#include <iostream>
#include <string>
#include <cmath>
// You are free to use additional libraries as long as it's not PROHIBITED per instruction.

using namespace std;
class HashTable {

    int _slots;

    public: 
        // constructor 
        HashTable(int slots);
        // Deconstructor
        ~HashTable();

    int hash_function(string text);
    void display();

}; 