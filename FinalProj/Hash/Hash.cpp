#include<iostream>
#include "hash.hpp"
// const int bsize = 40009;
using namespace std;
HashTable::HashTable()
{
    tableSize = 40009;
    table = new node *[40009];
    for(int i = 0; i < tableSize; i++)
    {
        table[i] = NULL;
    }
}
HashTable::HashTable(int bsize)
{
    tableSize = bsize;
    table = new node *[bsize];
    for(int i = 0; i < bsize; i++)
    {
        table[i] = NULL;
    }
}  // Constructor
HashTable::~HashTable()
{
    for(int i = 0; i < tableSize; i++)
    {
        node *temp = table[i];
        while(temp != NULL)
        {
            node *current = temp;
            temp = temp->next;
            delete current;
        }
    }
    delete[] table;
}
// hash function to map values to key
unsigned int HashTable::hashFunction(int key)
{
    int hash = (key % tableSize);
    return hash;
}
void HashTable::printTable()
{
    for (int i = 0; i < tableSize; i++)
    {
      if (table[i] != 0)
      {
        cout << "[" << i << "] -> Key: " << table[i]->key << " (#" << hashFunction(table[i]->key) << ") Value: " << table[i]->value << endl;
        if(table[i]->next != NULL)
        {
            node *temp = table[i];
            while(temp != NULL)
            {
                cout << "[" << i << "] -> Key: " << temp->key << " (#" << hashFunction(temp->key) << ") Value: " << temp->value << endl;
                temp = temp->next;
            }
        }
      }
      else
      {
        cout << "[" << i << "] -> Empty" << endl;
      }
    }
}
int HashTable::getNumOfCollision()
{
    return numOfcolision;
}
void HashTable::linearProbe(int key)
{
    node *n = new node;
    n->value = key;
    n->next = NULL;
    int key2 = hashFunction(key);
    if(table[key2] == NULL)
    {
        n->key = key2;
        table[key2] = n;
        currentSize++;
    }
    else
    {
        int keyVal = -1;
        keyVal = linProbeSearch(key2);
        n->key = keyVal;
        if(table[keyVal] == NULL)
        {
            table[keyVal] = n;
            currentSize++;
        }
        else
        {
             cout << "Summin wrawng boss" << endl;
        }
        
    }
}
int HashTable::linProbeSearch(int key)
{
    int pos = key;
    bool flag = false;
    while(table[pos] != NULL && pos != tableSize)
    {
        pos++;
        numOfcolision++;
        if(pos == tableSize)
        {
            flag = true;
            break;
        }
    }    
    if(pos == tableSize)
    {
        pos = 0;
        while(table[pos] != NULL)
        {
            pos++;
            numOfcolision++;
        }
    }
    return pos;
}
void HashTable::InsertQuad(int key)
{
    node *n = new node;
    n->next = NULL;
    n->value = key;
    int pos = hashFunction(key);
    int finalPos = FindQuad(pos);
    n->key = finalPos;
    if(currentSize != tableSize)
    {
        table[finalPos] = n;
        currentSize++;
    }
    return;
}
int HashTable::FindQuad(int key)
{
    int pos = hashFunction(key);
    int collisions = 0;
    while(table[pos] != NULL)
    {
        pos = pos + (2 * collisions);
        if (pos >= tableSize)
        {
            pos = pos - tableSize;
        }
        numOfcolision++;
        collisions++;
    }
    return pos;
}
void HashTable::insertItemLL(int v)
{
    node* temp = new node;
    temp->value = v;
    temp->next = NULL;
    temp->key = hashFunction(v);
    int index = hashFunction(v);
    if (table[index] == NULL)
    {
        table[index] = temp;
        currentSize++;
    }
    else 
    {
        numOfcolision++;
        table[index]->next = temp;
        // temp->next = table[index];
        currentSize++;
    }
}
node* HashTable::searchItem(int key)
{
    int i = hashFunction(key);
    if(table[i]->next != NULL)
    {
        numOfcolision++;
        node *temp = table[i]->next;
        while(temp != NULL)
        {
            if(temp->key == key)
            {
                // cout << temp->value << endl;
                return temp;
            }
            else
            {
            numOfcolision++;
            temp = temp->next;
            }

        }
    }
}
int HashTable::linSearch(int value)
{
    int temp = hashFunction(value);
    if(table[temp]->value == value)
    {
        return table[temp]->value;
    }
    else
    {
        bool flag = false;
        while(!flag)
        {
            numOfcolision++;
            if(table[temp]->value == value)
            {
                return table[temp]->value;
            }
            temp++;
            if(temp == tableSize)
            {
                temp = 0;
            }
        }
    }
    return 0;
}
int HashTable::quadSearch(int value)
{
    int pos = hashFunction(value);
    int collisions = 0;
    while(table[pos]->value != value)
    {
        pos = pos + (2 * collisions);
        if (pos >= tableSize)
        {
            cout << "cap" << endl;
            pos = pos - tableSize;
        }
        numOfcolision++;
        collisions++;
    }
    return pos;
}
void HashTable::resetColl()
{
    numOfcolision = 0;
}