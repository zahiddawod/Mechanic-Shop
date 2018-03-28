#include "Shop.h"

Shop::Shop() : size(0) {}

Shop::~Shop() {	for (int i = 0; i < size; i++) delete mechanics[i]; }

void Shop::operator+=(Customer* c) { customers += c; }

void Shop::operator-=(Customer* c) { customers -= c; }

Customer* Shop::getCustomer(int i)  { return customers.get(i); } 

CustomerList& Shop::getCustomers() { return customers; }

Mechanic* Shop::getMechanic(int i) { return mechanics[i]; }

int Shop::getNumMechanics() { return size; }

void Shop::operator+=(Mechanic* m) {
	if (size >= MAX_MECHANICS) return;
	mechanics[size++] = m;
}
