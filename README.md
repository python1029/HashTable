Author: Hoang Le Nguyen

# Testing:

For Windows comamnd prompt:

- The input files is in "inputs" directory
- Build the C++ program into bianry executable by:
  - `g++ -o fileName fileName.cpp`, `Get-Content path\to\inputs\ | fileName.exe`.
    This can be done if main.cpp `#include "hash.cpp"` not `hash.h`
  - Ex: `g++ -o main main.cpp` then
    `Get-Content inputs\atoz.txt | .\main.exe`

If "main.cpp" `#include "hash.h"`: this will link main.cpp and hash.cpp together, replace "something" with name of executable

    - g++ -o something main.cpp hash.cpp

# HashTable

Custom Hash Table

Functions:

1. Constructor: "HashTable(int slots)" k slots

   - When initialize an object, create a dynamic array of pointers with kth pointer elements that points to null pointer

2. Deconstructor: "~HashTable()"
   - Usage: "delete createdHashTable"
   - This function restore the memory on the heap manually by deleting the "createdHashTable"
3. Hash function: "hash_function(string text)

   - Return a integer value according to the size of a hash table

4. Add new node: "prepent(string word)"

   - Add a new node at the top of a slot
   - Return the node's value in string type

5. Diplay hash table: "display()"

   - Display the current state of the hash table

6. Display length of slot: "displayLength()"

   - Display the length of each slot of the Hash Table

7. Find standard Deviation: "stdDev()"
   - Find the standard deviation of the Hash Table. Smaller stdDev the better performance of Hash Table
   - Return result as "double"
