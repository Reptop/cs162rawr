#ifndef NODE_H
#define NODE_H

class Node {
public:
  int val;    // the value that this node stores
  Node *next; // a pointer to the next node in the list

  /*********************************************************************
   ** Function: Node (default constructor)
   ** Description: Constructs a new Node with default values.
   ** Parameters: None
   ** Pre-Conditions: None
   ** Post-Conditions: A new Node is created with default initialization
   *(usually null initialization for pointers and default values for other data
   *types).
   *********************************************************************/
  Node();

  /*********************************************************************
   ** Function: Node (non-default constructor)
   ** Description: Constructs a new Node with a specified integer value.
   ** Parameters: int value - The integer value to be stored in the Node.
   ** Pre-Conditions: None
   ** Post-Conditions: A new Node is created with the specified integer value
   *and typically next pointers set to nullptr (assuming a singly linked list
   *unless otherwise specified).
   *********************************************************************/
  Node(int);

  /*********************************************************************
   ** Function: ~Node (destructor)
   ** Description: Destroys the Node, freeing any resources allocated.
   ** Parameters: None
   ** Pre-Conditions: The Node should exist and have been properly initialized.
   ** Post-Conditions: The Node is destroyed, and any dynamically allocated
   *memory or resources are freed. This operation ensures proper memory
   *management, preventing memory leaks.
   *********************************************************************/
  ~Node();
};

#endif
