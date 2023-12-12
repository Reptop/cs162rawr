/******************************************************
** Program: linked_list.cpp
** Author: Your Name
** Date: 12/10/2023
** Description: Functions definitions for all standard linked list functions
** Input: Raed Kabir
** Output: Performs standard linked list functions
******************************************************/

#include "linked_list.h"

Linked_List::Linked_List() : length(0), head(nullptr) {}

int Linked_List::get_length() {
  // getter for length
  return length;
}

void Linked_List::print() {
  if (head == nullptr)
    return;

  Node *current;
  current = head;

  cout << " ";

  while (current != nullptr) {
    cout << current->val << " ";
    current = current->next;
  }

  cout << endl;
}

void Linked_List::clear() {
  Node *current = head;

  // deletes everything more efficiently
  //
  // I could also call pop_back or pop_front for each element

  while (current != nullptr) {
    Node *temp = current;
    current = current->next;
    delete temp;
  }

  head = nullptr;
  length = 0;
}

void Linked_List::push_front(int val) {
  Node *newNode = new Node();
  newNode->val = val;
  newNode->next = head;
  head = newNode;

  ++length;

  return;
}

void Linked_List::push_back(int val) {
  Node *newNode = new Node(val);

  if (head == nullptr) {
    head = newNode;

  } else {
    Node *current = head;

    while (current->next != nullptr)
      current = current->next;
    current->next = newNode;
  }

  ++length;

  return;
}

void Linked_List::insert(int val, int index) {
  if (index < 0 || index > length)
    return;

  Node *newNode = new Node();
  newNode->val = val;

  if (index == 0) {
    newNode->next = head;
    head = newNode;

  } else {
    Node *current = head;

    for (int i = 0; i < index - 1; ++i)
      current = current->next;

    // insert the new node
    newNode->next = current->next;
    current->next = newNode;
  }

  ++length;
}

void Linked_List::pop_back() {
  if (length == 0)
    return;

  if (head->next == nullptr) {
    // only one element in the list
    delete head;
    head = nullptr;

  } else {
    // traverse to the second last node
    Node *current = head;

    while (current->next->next != nullptr)
      current = current->next;

    delete current->next;
    current->next = nullptr;
  }

  if (length > 0)
    --length;
}

void Linked_List::pop_front() {
  if (head == nullptr)
    return;

  Node *secondElement = head->next;

  delete head;

  head = secondElement;

  if (length > 0)
    --length;
}

void Linked_List::remove(int index) {
  // invalid index check
  if (length == 0 || index < 0 || index >= length)
    return;

  Node *current = head;

  // removing the head if the user wants to remove first element
  if (index == 0) {
    head = head->next;
    delete current;

  } else {
    // traverse before the node that will be removed
    for (int i = 0; i < index - 1; ++i)
      current = current->next;

    // make sure lists has correct pointers by pointing current to the node
    // after the one to delete
    Node *nodeToDelete = current->next;
    current->next = nodeToDelete->next;

    delete nodeToDelete;
  }

  --length;
}

Node *Linked_List::mergeSort(Node *head) {
  if (!head || !head->next)
    return head;

  Node *midpoint = findMidpoint(head);
  Node *left = head;
  Node *right = midpoint->next;
  midpoint->next = nullptr;

  // sort each side
  left = mergeSort(left);
  right = mergeSort(right);

  // merge when finished
  return merge(left, right);
}

Node *Linked_List::findMidpoint(Node *head) {
  Node *slow = head;
  Node *fast = head->next;

  while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
  }

  return slow;
}

Node *Linked_List::merge(Node *left, Node *right) {
  // if side one is empty, return the other side
  if (left == nullptr)
    return right;
  if (right == nullptr)
    return left;

  // sorted lists' head
  Node *mergedHead = nullptr;

  if (left->val < right->val) {
    // copy left node to mergedHead
    mergedHead = left;
    // recursive call for next element
    mergedHead->next = merge(left->next, right);
  } else {
    // copy left node to mergedHead
    mergedHead = right;
    // recursive call for next element
    mergedHead->next = merge(left, right->next);
  }
  return mergedHead;
}

void Linked_List::sort_ascending() {
  // call mergeSort
  head = mergeSort(head);

  return;
}

// Function to find the node with the minimum value and its previous node
void Linked_List::findMaxNode(Node *head, Node *&maxPrev, Node *&maxNode) {
  maxNode = head;
  maxPrev = nullptr;
  Node *prev = nullptr;
  Node *current = head;

  while (current) {
    if (current->val > maxNode->val) {
      maxNode = current;
      maxPrev = prev;
    }

    prev = current;
    current = current->next;
  }
}

// handling for swapping node's next pointers
/*
Justification for over 15 lines: This swapping function was prone to many errors
                                 I decided to add more checks for edge cases
                                 that allowed the function to work
*/
void Linked_List::swapNodes(Node *&head, Node *prev1, Node *node1, Node *prev2,
                            Node *node2) {

  // do nothing if both nodes are the same
  if (node1 == node2)
    return;

  // swap adjacent nodes handling
  if (node1->next == node2) {
    node1->next = node2->next;
    node2->next = node1;

    if (prev1)
      prev1->next = node2;
    if (head == node1)
      head = node2;
    return;

  } else if (node2->next == node1) {
    node2->next = node1->next;
    node1->next = node2;
    if (prev2)
      prev2->next = node1;
    if (head == node2)
      head = node1;
    return;
  }

  // orthodox swap handling
  // this swaps their next pointers
  Node *temp = node1->next;
  node1->next = node2->next;
  node2->next = temp;

  // preserves the linked list structure
  // check if
  if (prev1)
    prev1->next = node2;
  if (prev2)
    prev2->next = node1;
  if (head == node1)
    head = node2;
  else if (head == node2)
    head = node1;
}

void Linked_List::selectionSortRecursive(Node *&start) {
  if (start == nullptr || start->next == nullptr)
    return;

  Node *maxPrev = nullptr;
  Node *maxNode = nullptr;

  findMaxNode(start, maxPrev, maxNode);

  if (maxNode != start) {
    Node *prev = nullptr;
    Node *curr = head;
    while (curr != start) {
      prev = curr;
      curr = curr->next;
    }
    swapNodes(head, prev, start, maxPrev, maxNode);
  }

  // recursive call for the next element in the list
  selectionSortRecursive(start->next);
}

void Linked_List::sort_descending() {
  // sort the nodes in descending order
  // Your code goes here:

  selectionSortRecursive(head);

  return;
}
