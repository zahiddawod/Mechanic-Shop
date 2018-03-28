#include <sstream>
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
#include "Customer.h"


int Customer::nextId = 1000;

Customer::Customer(string fname, string lname, string add, string pnum) : 
        id(Customer::nextId++) { 
    firstName   = fname;
    lastName    = lname;
    address     = add;
    phoneNumber = pnum;
}

int           Customer::getId() const { return id; }
int           Customer::getNumVehicles() const  { return vehicles.getSize(); }
VehicleList&  Customer::getVehicles()           { return vehicles; }

void Customer::operator+=(Vehicle* v) { vehicles += v; }

void operator<<(ostream& output, Customer* c) {
	 output << "Customer ID " << c->getId() << endl << endl
		       << "    Name: " << setw(40) << c->getFname() + " " + c->getLname() << endl 
		       << "    Address: " << setw(37) << c->getAddress() << endl
		       << "    Phone Number: " << setw(32) <<  c->getPhoneNumber() << endl << endl;    
	if (c->getNumVehicles() > 0) {
	    output << "    " << c->getNumVehicles() 
	              << " vehicle(s): " << endl << endl;

	    output << c->getVehicles();
		output << endl;
	}
}

bool Customer::operator<(Customer* c) { return lastName < c->getLname(); }
bool Customer::operator>(Customer* c) { return lastName > c->getLname(); }

