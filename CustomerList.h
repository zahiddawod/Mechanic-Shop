#ifndef CUSTOMERLIST_H
#define CUSTOMERLIST_H

#include "Customer.h"


class CustomerList
{
  class Node
  {
    friend class CustomerList;
    private:
      Customer* data;
      Node*    next;
  };

  public:
    CustomerList();
    ~CustomerList();
    int getSize() const;
    Customer* get(int);
	void operator+=(Customer*);
	void operator-=(Customer*);
	Customer* operator[](int) const;
	friend void operator<<(ostream&, CustomerList&);
  private:
    Node* head;
};

#endif
