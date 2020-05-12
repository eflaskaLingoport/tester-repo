/**CPPFile*********************************************************************
 * Hash Table Class Implementation
 * 
 * Authors: Eric Flaska and Andrew Campbell
 * 
 * Eric wrote the driver file as well as the implementation for the Quadratic Probe and the Chaining(Linked List)
 * While Andrew handled the full implementation of the Linear Probe functions. 
*******************************************************************************/

#ifndef HASH_HPP
#define HASH_HPP
#include <string>
const int SIZE = 100;

using namespace std;

struct node
{
    int key;
    int value;
    struct node* next;
};

class HashTable
{
    int tableSize;  // No. of buckets (linked lists)
    int currentSize;
    // Pointer to an array containing buckets
    node* *table;
    int numOfcolision =0;
    node* createNode(int key, node* next);
public:
    HashTable();
    HashTable(int bsize);  // Constructor
    ~HashTable();
    unsigned int hashFunction(int key);
    void printTable();
    int getNumOfCollision();
    void linearProbe(int key);
    int linProbeSearch(int key);
    void InsertQuad(int key);
    int FindQuad(int key);
    void insertItemLL(int v);
    node* searchItem(int key);
    int linSearch(int value);
    int quadSearch(int value);
    void resetColl();


};

#endif
