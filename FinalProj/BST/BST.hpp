/**CPPFile*********************************************************************
 * Hash Table Class Implementation
 * 
 * Authors: Eric Flaska and Andrew Campbell
 * 
 * Andrew wrote the driver file while Eric wrote the class implementation for the BST
 * 
*******************************************************************************/

#include <iostream>
using namespace std;
struct Node
{
  int data;
  Node *left;
  Node *right;
};
class BST
{
  private:
    Node *root;

    public:
    BST();
    ~BST(); 
    void insert(int value);
    Node* search(int value);  
    void printTree(Node* n);
    Node* getRoot();
};
