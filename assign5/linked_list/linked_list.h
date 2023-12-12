#ifndef LINKED_LIST
#define LINKED_LIST

#include "node.h"
#include <iostream>

using namespace std;

class Linked_List {
private:
  int length; // the number of nodes contained in the list
  Node *head; // a pointer to the first node in the list

public:
  /*********************************************************************
   ** Function: get_length
   ** Description: Returns the number of elements in the linked list.
   ** Parameters: None
   ** Pre-Conditions: The list has been initialized.
   ** Post-Conditions: Returns the current length of the list.
   *********************************************************************/
  int get_length();

  /*********************************************************************
   ** Function: print
   ** Description: Outputs a list of all integers contained within the list.
   ** Parameters: None
   ** Pre-Conditions: The list has been initialized.
   ** Post-Conditions: All elements of the list are printed to standard output.
   *********************************************************************/
  void print(); // output a list of all integers contained within the list

  /*********************************************************************
   ** Function: clear
   ** Description: Deletes the entire list, removing all nodes and resetting
   *length to 0.
   ** Parameters: None
   ** Pre-Conditions: The list has been initialized.
   ** Post-Conditions: The list is empty and its length is reset to 0.
   *********************************************************************/
  void clear();

  /*********************************************************************
   ** Function: push_front
   ** Description: Inserts a new value at the front of the list.
   ** Parameters: int value - The value to insert.
   ** Pre-Conditions: The list has been initialized.
   ** Post-Conditions: A new node with the given value is added at the front of
   *the list.
   *********************************************************************/
  void push_front(int);

  /*********************************************************************
   ** Function: push_back
   ** Description: Inserts a new value at the back of the list.
   ** Parameters: int value - The value to insert.
   ** Pre-Conditions: The list has been initialized.
   ** Post-Conditions: A new node with the given value is added at the back of
   *the list.
   *********************************************************************/
  void push_back(int);

  /*********************************************************************
  ** Function: insert
  ** Description: Inserts a new value in the list at the specified index.
  ** Parameters: int index - The index at which to insert the value.
              int value - The value to insert.
  ** Pre-Conditions: The list has been initialized and the index is within the
  bounds of the list.
  ** Post-Conditions: A new node with the given value is inserted at the
  specified index in the list.
  *********************************************************************/
  void insert(int, int);

  /*********************************************************************
  ** Function: pop_back
  ** Description: Removes the node at the back of the list.
  ** Parameters: None
  ** Pre-Conditions: The list has been initialized and is not empty.
  ** Post-Conditions: The last node of the list is removed.
  *********************************************************************/
  void pop_back();
  /*********************************************************************
   ** Function: pop_front
   ** Description: Removes the node at the front of the list.
   ** Parameters: None
   ** Pre-Conditions: The list has been initialized and is not empty.
   ** Post-Conditions: The first node of the list is removed.
   *********************************************************************/
  void pop_front();
  /*********************************************************************
   ** Function: remove
   ** Description: Removes the node at the specified index of the list.
   ** Parameters: int index - The index of the node to remove.
   ** Pre-Conditions: The list has been initialized and the index is within the
   *bounds of the list.
   ** Post-Conditions: The node at the specified index is removed from the list.
   *********************************************************************/
  void remove(int);

  /*********************************************************************
   ** Function: sort_ascending
   ** Description: Sorts the nodes in the list in ascending order using the
   *Merge Sort algorithm.
   ** Parameters: None
   ** Pre-Conditions: The list has been initialized.
   ** Post-Conditions: The list is sorted in ascending order.
   *********************************************************************/
  void sort_ascending();

  /*********************************************************************
   ** Function: sort_descending
   ** Description: Sorts the nodes in the list in descending order.
   ** Parameters: None
   ** Pre-Conditions: The list has been initialized.
   ** Post-Conditions: The list is sorted in descending order.
   *********************************************************************/
  void sort_descending();

  /*********************************************************************
  ** Function: Linked_List
  ** Description: Constructor for the Linked List.
  ** Parameters: None
  ** Pre-Conditions: None
  ** Post-Conditions: A new Linked List object is created.
  *********************************************************************/
  Linked_List();

  /*********************************************************************
  ** Function: merge
  ** Description: Merges two sublists into a single sorted list.
  ** Parameters: Node *a - The first sublist.
                Node *b - The second sublist.
  ** Pre-Conditions: Both sublists 'a' and 'b' are sorted.
  ** Post-Conditions: Returns a new sorted list that is the result of merging
  'a' and 'b'.
  *********************************************************************/
  Node *merge(Node *, Node *);

  /*********************************************************************
   ** Function: findMidpoint
   ** Description: Finds the midpoint of a linked list.
   ** Parameters: Node *head - The head node of the list.
   ** Pre-Conditions: The list starting at 'head' is properly initialized.
   ** Post-Conditions: Returns the node that is at the midpoint of the list.
   *********************************************************************/
  Node *findMidpoint(Node *);

  /*********************************************************************
   ** Function: mergeSort
   ** Description: Sorts the linked list using the Merge Sort algorithm.
   ** Parameters: Node *head - The head node of the list to sort.
   ** Pre-Conditions: The list starting at 'head' is properly initialized.
   ** Post-Conditions: Returns the head node of the sorted list.
   *********************************************************************/
  Node *mergeSort(Node *);

  /*********************************************************************
** Function: findMaxNode
** Description: Finds the maximum node in a linked list.
** Parameters: Node *current - The current node to start the search.
              Node *&maxNode - A reference to the pointer that will hold the max
node found. Node *&prevMax - A reference to the pointer that will hold the node
previous to the max node.
** Pre-Conditions: The list starting at 'current' is properly initialized.
** Post-Conditions: The 'maxNode' and 'prevMax' pointers are set to the maximum
node and its previous node, respectively.
*********************************************************************/
  void findMaxNode(Node *, Node *&, Node *&);

  /*********************************************************************
  ** Function: swapNodes
  ** Description: Swaps two nodes in the linked list.
  ** Parameters: Node *&head - A reference to the head of the list.
              Node *prev1 - The previous node to the first node to swap.
              Node *node1 - The first node to swap.
              Node *prev2 - The previous node to the second node to swap.
              Node *node2 - The second node to swap.
  ** Pre-Conditions: The list is properly initialized, and the nodes exist in
  the list.
  ** Post-Conditions: The positions of 'node1' and 'node2' are swapped in the
  list.
  *********************************************************************/
  void swapNodes(Node *&head, Node *prev1, Node *node1, Node *prev2,
                 Node *node2);

  /*********************************************************************
   ** Function: selectionSortRecursive
   ** Description: Sorts the linked list using the Selection Sort algorithm
   *recursively.
   ** Parameters: Node *&start - A reference to the start node of the sublist to
   *sort.
   ** Pre-Conditions: The list starting at 'start' is properly initialized.
   ** Post-Conditions: The sublist starting at 'start' is sorted in ascending
   *order.
   *********************************************************************/
  void selectionSortRecursive(Node *&start);
};

#endif
