#include <iostream>
#include <string>
#include <cmath>
// You are free to use additional libraries as long as it's not PROHIBITED per instruction.

using namespace std;

// Node class for linking item
struct Node
{
    string _word;
    Node *_next;

    // Constructor
    //  First element will kth slot, if k = 5
    //  0  ->   nullptr
    //  1  ->   nullptr
    //  2  ->   nullptr
    //  3  ->   nullptr
    //  4  ->   nullptr
    Node(string word)
    {
        _word = word;
        _next = nullptr;
    }
};

class HashTable
{
    Node **table; // pointer of pointer of element, this will be an array
    int _slots;   // numbers of slot

public:
    // constructor
    HashTable(int slots);
    // Deconstructor
    ~HashTable();

    // Mutator
    string prepend(string word);
    string append(string word);
    double stdDev();

    int hash_function(string text);
    void displayLength(); // Display the length of each slot
    void display();       // Display each slot items

private:
    double mean();     // Find the mean
    double variance(); // Find the variance
};
