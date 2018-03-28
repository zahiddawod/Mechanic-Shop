#ifndef VEHICLELIST_H
#define VEHICLELIST_H

#include "Vehicle.h"


class VehicleList
{
  class Node
  {
    friend class VehicleList;
    private:
      Vehicle* data;
      Node*    next;
  };

  public:
    VehicleList();
    ~VehicleList();
    int getSize() const;
	void operator+=(Vehicle*);	
	void operator-=(Vehicle*);
	Vehicle* operator[](int) const;
	friend void operator<<(ostream&, VehicleList&);
  private:
    Node* head;
};

#endif
