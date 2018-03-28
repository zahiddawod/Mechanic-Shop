#ifndef VIEW_H
#define VIEW_H

#include "CustomerList.h"
#include "Shop.h"

class View {

    public:
        void mainMenu(int&);
        void printCustomers(CustomerList&) const;
        void pause() const;
        void promptUserInfo(string&, string&, string&, string&);
        void promptUserId(int&);
	void promptVehicle(int&);
        void displayInvalid();
        void promptVehicleInfo(string&, string&, string&, int&, int&);
	void printMechanics(Shop&);
    private:
        int readInt() const;
};

#endif
