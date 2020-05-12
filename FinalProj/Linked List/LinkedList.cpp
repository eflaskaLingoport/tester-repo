#include<iostream>
#include "LL.hpp"
using namespace std;

LL::LL() 
{
  head = NULL;
}

LL::~LL() 
{
    Node *temp = head;
    while(head != NULL)
    {
        head = head->next;
        delete temp;
        temp = head;
    }
    head = NULL;
}



Node* LL::search(int num) 
{
  Node* temp = head;
  
  while (temp != 0) {
    if (temp->key == num) 
    {
        return temp;
    }
    temp = temp->next;
  }
  
  return NULL;
}

void LL::insertNode(Node* left, int num) 
{
    if(left == 0 && head == NULL)
    {
        Node *node = new Node;
        node->key = num;
        node->next = NULL;
        head = node;
        return;
    }
    else if(left == 0 && head != NULL)
    {
        Node *node = new Node;
        node->key = num;
        node->next = head;
        head = node;
    }
    else
    {
        Node *newN = new Node;
        newN->key = num;
        Node *temp = left->next;
        if(left->next == NULL)
        {
            left->next = newN;
            newN->next = NULL;
        }
        else
        {
            left->next = newN;
            newN->next = temp;
        }
    return;    
  }
    
 
}
void LL::printLL() {
  Node* temp = head;
  if(temp == NULL)
  {
      cout << "Empty" << endl;
  }
  while (temp->next != 0) 
  {
    cout << temp->key << "->";
    temp = temp->next;
  }
  cout << temp->key << endl;
}