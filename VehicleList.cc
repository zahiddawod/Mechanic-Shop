#include <sstream>
using namespace std;

#include "VehicleList.h"

VehicleList::VehicleList() : head(0) { }


VehicleList::~VehicleList()
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

void VehicleList::operator+=(Vehicle* newVeh) {
  Node *currNode, *prevNode;
  Node* newNode = new Node;
  newNode->data = newVeh;
  newNode->next = 0;

  currNode = head;
  prevNode = 0;

  while (currNode != 0) {
    if (newNode->data > currNode->data) break;
    prevNode = currNode;
    currNode = currNode->next;
  }

  if (prevNode == 0) head = newNode;
  else prevNode->next = newNode;
  newNode->next = currNode;	
}

void VehicleList::operator-=(Vehicle* v) {
	Node *currNode, *prevNode;
	currNode = head;
	prevNode = 0;

	while (currNode != 0) {
		if (currNode->data == v) break;
		prevNode = currNode;
		currNode = currNode->next;
	}
	
	if (currNode == 0) return;
	if (prevNode == 0) head = currNode->next;
	else prevNode->next = currNode->next;
	delete currNode->data;
	delete currNode;
}

Vehicle* VehicleList::operator[](int index) const {
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

int VehicleList::getSize() const {
  Node *currNode = head;
  int size = 0;

  while (currNode != 0) {
    currNode = currNode->next;
    size++;
  }
  
  return size;
}

void operator<<(ostream& output, VehicleList& vList) {
	if (vList.head == 0) return;
	for (int i = 0; i < vList.getSize(); i++) output << vList[i];
}

