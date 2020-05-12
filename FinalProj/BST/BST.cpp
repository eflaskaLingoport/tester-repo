#include<iostream>
#include "BST.hpp"
#define COUNT 10
using namespace std;
  BST::BST()
  {
    root = NULL;
  }
  void delNode(Node *n)
  {
      if(n!=NULL)
      {
          delNode(n->left);
          delNode(n->right);
          if(n->left == NULL && n->right == NULL)
          {
            delete n;
            n = NULL;
          }

      }
  }
  BST::~BST()
  {
    delNode(root); //This will effectively delete our tree.
  }
  Node *makeNode(int value)
  {
      Node* n = new Node;
      n->data = value;
      n->left = NULL;
      n->right = NULL;
      return n;
  }
  Node* insertHelp(Node* &root, Node *n)
  {
    if (root == NULL)
    {
      return n;
    }
    if(root->data > n->data) 
    {
      root->left = insertHelp(root->left, n); 
    }
    else if (root->data < n->data) 
    {
      root->right = insertHelp(root->right, n);    
    }
    return root; 
  }
  void BST::insert(int value)
  {
    Node *n = makeNode(value);
    if(root == NULL)
    {
      root = n;
    }
    else
    {
        insertHelp(root, n);

    }
    
  }
  Node* BST::search(int value)
  {
    Node* temp = root;
    while(temp->data != value && temp != NULL)
    {
      if(temp->data > value)
      {
        temp = temp->left;
      }
      else if(temp->data < value)
      {
        temp = temp->right;
      }
      else
      {
        return temp;
      }
    }
    // return NULL;
  }
  void BST::printTree(Node *n)
  {
    if(n != NULL)
    {
      printTree(n->left);
      cout << n->data << endl;
      printTree(n->right);
    } 
  }
  Node *BST::getRoot()
  {
    return root;
  }