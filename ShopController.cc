#include "ShopController.h"

ShopController::ShopController() {

    initShop();

}

void ShopController::launch() {

    int choice;

    while (1) {
        choice = -1;
        view.mainMenu(choice);
        
        if (choice == 1) {
            view.printCustomers(mechanicShop.getCustomers());
            view.pause();
        } else if (choice == 2) {
            string fname, lname, address, phone;
            view.promptUserInfo(fname, lname, address, phone);
            mechanicShop += (new Customer(fname, lname, address, phone));
            view.pause();
        } else if (choice == 3) {
            int id;
            view.promptUserId(id);
            Customer* cust = mechanicShop.getCustomer(id);
            if (cust != 0) {
                string make, model, colour;
                int year, milage;
                view.promptVehicleInfo(make, model, colour, year, milage);
                *cust += (new Vehicle(make, model, colour, year, milage));
            } else {
                view.displayInvalid();
            }
            view.pause();
        } else if (choice == 4) {
			int id;
			view.promptUserId(id);
			Customer* cust = mechanicShop.getCustomer(id);
			if (cust != 0) {
				for (int i = 0; i < cust->getVehicles().getSize(); i++)
					cust->getVehicles() -= cust->getVehicles()[i];
				mechanicShop -= cust;
			} else {
				view.displayInvalid();
			}
			view.pause();
        } else if (choice == 5) {
			int id;
			view.promptUserId(id);
			Customer* cust = mechanicShop.getCustomer(id);
			if(cust != 0) {
				view.promptVehicle(id);
				cust->getVehicles() -= cust->getVehicles()[id];
			} else {
				view.displayInvalid();
			}
			view.pause();
        } else if (choice == 6) {
			view.printMechanics(mechanicShop);
            view.pause();
		} else {
            break;
        }
    }
}


void ShopController::initShop() {
	Mechanic* newMechanic;
    Customer* newCustomer;
    Vehicle* newVehicle;

	newMechanic = new Mechanic("Zahid", "Dawod", "26 Avenue Rd", "(613)305-3502", 200000);
	mechanicShop += newMechanic;
	newMechanic = new Mechanic("Bob", "Vance", "1101 Refrigeration Rd", "(202)336-6250", 62500);
	mechanicShop += newMechanic;
	newMechanic = new Mechanic("Rita", "Book", "1156 Bayshore Dr", "(613)985-1653", 86500);
	mechanicShop += newMechanic;

    newCustomer = new Customer("Maurice", "Mooney", "2600 Colonel By Dr.", "(613)728-9568");
    newVehicle = new Vehicle("Ford", "Fiesta", "Red", 2007, 100000);
    *newCustomer += newVehicle;
    mechanicShop += newCustomer;

    
    newCustomer = new Customer("Abigail", "Atwood", "43 Carling Dr.", "(613)345-6743");
    newVehicle = new Vehicle("Subaru", "Forester", "Green", 2016, 40000);
    *newCustomer += newVehicle;
    mechanicShop += newCustomer;


    newCustomer = new Customer("Brook", "Banding", "1 Bayshore Dr.", "(613)123-7456");
    newVehicle = new Vehicle("Honda", "Accord", "White", 2018, 5000);
    *newCustomer += newVehicle;
    newVehicle = new Vehicle("Volkswagon", "Beetle", "White", 1972, 5000);
    *newCustomer += newVehicle;
    mechanicShop += newCustomer;


    newCustomer = new Customer("Ethan", "Esser", "245 Rideau St.", "(613)234-9677");
    newVehicle = new Vehicle("Toyota", "Camery", "Black", 2010, 50000);
    *newCustomer += newVehicle;
    mechanicShop += newCustomer;
    

    newCustomer = new Customer("Eve", "Engram", "75 Bronson Ave.", "(613)456-2345");
    newVehicle = new Vehicle("Toyota", "Corolla", "Green", 2013, 80000);
    *newCustomer += newVehicle;
    newVehicle = new Vehicle("Toyota", "Rav4", "Gold", 2015, 20000);
    *newCustomer += newVehicle;
    newVehicle = new Vehicle("Toyota", "Prius", "Blue", 2017, 10000);
    *newCustomer += newVehicle;
    mechanicShop += newCustomer;

    
    newCustomer = new Customer("Victor", "Vanvalkenburg", "425 O'Connor St.", "(613)432-7622");
    newVehicle = new Vehicle("GM", "Envoy", "Purple", 2012, 60000);
    *newCustomer += newVehicle;
    newVehicle = new Vehicle("GM", "Escalade", "Black", 2016, 40000);
    *newCustomer += newVehicle;
    newVehicle = new Vehicle("GM", "Malibu", "Red", 2015, 20000);
    *newCustomer += newVehicle;
    newVehicle = new Vehicle("GM", "Trailblazer", "Orange", 2012, 90000);
    *newCustomer += newVehicle;
    //newVehicle = new Vehicle("GM", "Vue", "Blue", 2015, 20000);
    //newCustomer->addVehicle(newVehicle);
    mechanicShop += newCustomer;

}
