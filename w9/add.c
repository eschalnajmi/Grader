
#include "linkedList.h"
#include "add.h"

/*
 * add a node to the list at the head
 */

Node *addNodeAtHead( Node *head, Node *newNode ) {

  newNode->next = head;

  return newNode;
}

/*
 * insert a node after a given location
 */

//new comment test

void insertNodeAfter( Node *location, Node *new ) {

  new->next = location->next;
  location->next = new;

  return;
}

/*
 * delete a node from the list
 */

Node *deleteNextNode( Node *location ) {

  Node *toBeRemoved = location->next;
  location->next = toBeRemoved->next;  // unlink from the list

  return toBeRemoved;
}

