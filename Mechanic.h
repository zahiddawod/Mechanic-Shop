#ifndef MECHANIC_H
#define MECHANIC_H

#include <string>
#include "Person.h"

using namespace std;

class Mechanic : Person {
    public:
        Mechanic(string="", string="", string="", string="", float=0);
        float getSalary();
	int getId() const;
	friend void operator<<(ostream&, Mechanic*);

    private:
        static int nextId;
        const int id;
	float salary;
};

#endif
