#include <sstream>
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
#include "Mechanic.h"

int Mechanic::nextId = 5000;

Mechanic::Mechanic(string fname, string lname, string add, string pnum, float sal) : 
        id(Mechanic::nextId++) { 
    firstName   = fname;
    lastName    = lname;
    address     = add;
    phoneNumber = pnum;
	salary = sal;
}


int   Mechanic::getId() const { return id; }
float Mechanic::getSalary() { return salary; }

void operator<<(ostream& output, Mechanic* m) {
	 output << "Mechanic ID " << m->getId() << endl << endl
		       << "    Name: \t\t" << m->getFname() + " " + m->getLname() << endl
		       << "    Address: \t\t" << m->getAddress() << endl
		       << "    Phone Number: \t" <<  m->getPhoneNumber() << endl
		       << "    Salary: \t\t" <<  m->getSalary() << endl << endl;
}
