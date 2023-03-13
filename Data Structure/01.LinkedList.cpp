#include <iostream>
#include "01.LinkedList.h"

LinkedList::LinkedList() {
  head = NULL;
	tail = NULL;
}

LinkedList::LinkedList(int data) {
  Node* temp = new Node();
  temp->data = data;

  head = temp;
  tail = temp;
}

Node* LinkedList::getHead() {
  return head;
}

void LinkedList::appendNode(int data) {
  Node* temp = new Node();
  temp->data = data;

  if (head == NULL) {
    head = temp;
    tail = temp;
  } else {
    tail->nextNode = temp;
    tail = temp;
  }
}

void LinkedList::insertNode(int data, int at) {
  Node* pointer = head;

  for (int i = 0; i < at - 1; i++) {
    pointer = pointer->nextNode;
  }

  Node* temp = new Node();
  temp->data = data;

  temp->nextNode = pointer->nextNode;
  pointer->nextNode = temp;
}

void LinkedList::deleteNode(int at) {
  Node* pointer = head;

  for (int i = 0; i < at - 1; i++) {
    pointer = pointer->nextNode;
  }

  Node* tartget = pointer->nextNode;
  pointer->nextNode = target->nextNode;

  delete target;
}

void LinkedList::display(Node* start) {
  std::cout << "===== Print the whole Linked List =====" << std::endl;

  Node* pointer = head;
  int index = 0;
  while (pointer != NULL) {
    std::cout << "Node " << index << ": " << pointer->data << std::endl;
    pointer = pointer->nextNode;
    index += 1;
  }
}
