#include <sstream>
#include <iostream>
#include <iomanip>
using namespace std;
#include <string>

#include "CustomerList.h"

CustomerList::CustomerList() : head(0) { }


CustomerList::~CustomerList()
{
  Node *currNode, *nextNode;

  currNode = head;

  while (currNode != 0) {
    nextNode = currNode->next;
    delete currNode->data;
    delete currNode;
    currNode = nextNode;
  }
}

void CustomerList::operator+=(Customer* newCust) {
  Node *currNode, *prevNode;
  Node* newNode = new Node;
  newNode->data = newCust;
  newNode->next = 0;

  currNode = head;
  prevNode = 0;

  while (currNode != 0) {
    if (*newNode->data < currNode->data) break;
    prevNode = currNode;
    currNode = currNode->next;
  }

  if (prevNode == 0) head = newNode;
  else prevNode->next = newNode;
  newNode->next = currNode;
}

void CustomerList::operator-=(Customer* c) {
	Node *currNode, *prevNode;
	currNode = head;
	prevNode = 0;

	while (currNode != 0) {
		if (currNode->data == c) break;
		prevNode = currNode;
		currNode = currNode->next;
	}
	
	if (currNode == 0) return;
	if (prevNode == 0) head = currNode->next;
	else prevNode->next = currNode->next;
	delete currNode->data;
	delete currNode;
}

Customer* CustomerList::operator[](int index) const {
	if (index < 0) return 0;
	Node *currNode = head;
	int currIndex = 0;

	while (currNode != 0) {
		if (currIndex == index) return currNode->data;
		currNode = currNode->next;
		currIndex++;
	}

	return 0;
}

Customer* CustomerList::get(int id) {
  Node *currNode = head;

  while (currNode != 0) {
    if(currNode->data->getId() == id) {
      return currNode->data;
    }
    currNode = currNode->next;
  }

  return 0;
}

int CustomerList::getSize() const {
  Node *currNode = head;
  int size = 0;

  while (currNode != 0) {
    currNode = currNode->next;
    size++;
  }
  
  return size;
}

void operator<<(ostream& output, CustomerList& cList) {
	if (cList.head == 0) return;
	for (int i = 0; i < cList.getSize(); i++) output << cList[i];
}

