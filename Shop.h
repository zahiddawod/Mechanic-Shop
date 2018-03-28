#ifndef SHOP_H
#define SHOP_H

#include "Mechanic.h"
#include "Customer.h"
#include "CustomerList.h"
#include "defs.h"

class Shop{

    public:
	Shop();
	~Shop();
	void operator+=(Customer*);
	void operator+=(Mechanic*);
	void operator-=(Customer*);
        Customer* getCustomer(int);
        CustomerList& getCustomers();
	Mechanic* getMechanic(int);
	int getNumMechanics();

    private:
        CustomerList customers;
	Mechanic* mechanics[MAX_MECHANICS];
	int size;

};

#endif
