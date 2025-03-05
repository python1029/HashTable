#include <iostream>
#include <string>
#include "hash.h"

using namespace std;

// Constructor
HashTable::HashTable(int slots)
{
    _slots = slots;
    table = new Node *[slots]; // an dynamic array that stores pointers to linked list heads
    for (int i = 0; i < slots; i++)
    {
        table[i] = nullptr; // Right now all slots are empty
    }
}

// Deconstructor
HashTable::~HashTable()
{
    for (int i = 0; i < _slots; i++)
    {
        Node *currentNode = table[i];
        while (currentNode)
        {
            Node *temp = currentNode;
            currentNode = currentNode->_next;
            delete temp;
        }
    }
    delete[] table; // Deallocate the table from heap memory
}

/// @brief Hash function, that finds value it in a slot
/// @param text The string value
/// @return Integer value
int HashTable::hash_function(string text)
{
    // Implement your own hash function here
    int totalSlot = _slots;
    int sumValue = 0;
    for (char ch : text)
    {
        sumValue += (int)ch; // Add all decimal values of characters (based on ASCII)
    }
    int hashValue = sumValue % totalSlot; // Get the remainder
    return hashValue;
}

/// @brief Add new string at the head of a slot
/// @param word The new string
/// @return The added Node's value
string HashTable::prepend(string word)
{
    // New Node pointer
    Node *newNode = new Node(word);
    int hashValue = hash_function(word);
    newNode->_next = table[hashValue];
    table[hashValue] = newNode;
    return word;
}

/// @brief Display the current state of Hash Table
void HashTable::display()
{
    for (int i = 0; i < 5; i++)
    {
        cout << "Slot " << i << ": ";
        Node *currentNode = table[i];
        while (currentNode)
        {
            cout << " " << currentNode->_word;
            currentNode = currentNode->_next;
        }
        cout << endl;
    }
}

/// @brief Display the length of each slot of the Hash Table
void HashTable::displayLength()
{
    for (int i = 0; i < _slots; i++)
    {
        int count = 0;
        Node *currentNode = table[i];
        while (currentNode)
        {
            currentNode = currentNode->_next;
            count++;
        }
        cout << "Slot " << i << ": " << count << endl;
    }
}

/// @brief Find the mean of the Hash Table by taking all (strings/slots)
/// @return The mean
double HashTable::mean()
{
    double mean = 0.0;
    for (int i = 0; i < _slots; i++)
    {
        int count = 0;
        Node *currentNode = table[i];
        while (currentNode)
        {
            count++;
            currentNode = currentNode->_next;
        }
        mean += count;
    }
    mean /= _slots;
    return mean;
}

/// @brief Find the variance of Hash Table by taking ( sum( (Xs_of_a_slot - mean) ^ 2 ) ) / slots
/// @return The variance
double HashTable::variance()
{
    double variance = 0.0;
    int *slotLengths = new int[_slots];
    for (int i = 0; i < _slots; i++)
    {
        int count = 0;
        Node *currentNode = table[i];
        while (currentNode)
        {
            count++;
            currentNode = currentNode->_next;
        }
        slotLengths[i] = count;
    }
    for (int i = 0; i < _slots; i++)
    {
        variance += pow(slotLengths[i] - mean(), 2);
    }
    variance /= _slots;
    delete slotLengths;
    return variance;
}

/// @brief Find the standard deviation of the Hash Table
/// Smaller stdDev the better performance of Hash Table
/// @return The stanard deviation
double HashTable::stdDev()
{
    double _variance = variance(), stdDev = 0;
    stdDev = sqrt(_variance);
    return stdDev;
}

// NOTE: this not work yet

// Add new string at the end
// string HashTable::append(string word)
// {
//     Node *newNode = new Node(word);
//     int hashValue = hash_function(word);
//     Node *currentNode = table[hashValue];
//     while (currentNode->_next != nullptr)
//     {
//         currentNode = currentNode->_next;
//     }
//     currentNode->_next = newNode;
//     newNode->_next = nullptr;
//     return newNode->_word;
// }
