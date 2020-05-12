/**CPPFile*********************************************************************
 * Linked List Class Implementation
 * 
 * Authors: Eric Flaska and Andrew Campbell
 * 
 * Andrew coded up most of the Linked List implementation for the class and getting the class to be fully functional
 * Eric covered the driver function and getting the output csv files
*******************************************************************************/

struct Node 
{
  int key;
  Node* next;
};

class LL {
private:
  Node* head;
 
public:
  LL();      /* Constructor */
  ~LL();     /* Destructor */

  Node* search(int num);   
  void insertNode(Node* left, int num); 
  void printLL();        

};