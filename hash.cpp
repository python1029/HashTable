#include <iostream>
#include <string>
#include "hash.h"

using namespace std;

struct Node {
    string _word;
    Node* _next;

    //Constructor
    // First element will kth slot, if k = 5 
    // 0  ->   nullptr 
    // 1  ->   nullptr 
    // 2  ->   nullptr 
    // 3  ->   nullptr 
    // 4  ->   nullptr 
    Node(string word) {
        _word = word;
        _next = nullptr; 
    }
};

//Constructor 
HashTable::HashTable(int slots){
    _slots = slots;
    Node** table; // pointer of pointer of element 
    table = new Node*[slots];
    for (int i = 0; i < slots ; i++) {
        table[i] = nullptr; // Right now all slots are empty 
    } 
}

HashTable::~HashTable() { 

}

int HashTable::hash_function(string text) {
    // Implement your own hash function here
    int totalSlot = _slots; 
    char letter = text[0]; // Take the first character(in ASCII) of the word 
    int hashValue = letter % totalSlot; // Get the remainder 
    return hashValue;
}