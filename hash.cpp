#include <iostream>
#include <string>
#include "hash.h"

using namespace std;

// Constructor
HashTable::HashTable(int slots)
{
    _slots = slots;
    Node **table; // pointer of pointer of element
    table = new Node *[slots];
    for (int i = 0; i < slots; i++)
    {
        table[i] = nullptr; // Right now all slots are empty
    }
}

HashTable::~HashTable()
{
}

int HashTable::hash_function(string text)
{
    // Implement your own hash function here
    int totalSlot = _slots;
    char letter = text[0];              // Take the first character(in ASCII) of the word
    int hashValue = letter % totalSlot; // Get the remainder
    return hashValue;
}