OBJ = main.o ShopController.o View.o Shop.o CustomerList.o VehicleList.o Customer.o Vehicle.o Person.o Mechanic.o

mechanicshop:	$(OBJ)
	g++ -o mechanicshop $(OBJ)

main.o:	main.cc 
	g++ -c main.cc -g

ShopController.o:	ShopController.cc ShopController.h Shop.h View.h
	g++ -c ShopController.cc -g

View.o:	View.cc View.h 
	g++ -c View.cc -g

Shop.o:	Shop.cc Shop.h CustomerList.h  
	g++ -c Shop.cc -g

CustomerList.o: CustomerList.cc CustomerList.h Customer.h defs.h
	g++ -c CustomerList.cc -g

VehicleList.o:	VehicleList.cc VehicleList.h Vehicle.h defs.h
	g++ -c VehicleList.cc -g

Customer.o:	Customer.cc Customer.h 
	g++ -c Customer.cc -g

Person.o:	Person.cc Person.h 
	g++ -c Person.cc -g

Mechanic.o:	Mechanic.cc Mechanic.h
	g++ -c Mechanic.cc -g

Vehicle.o: Vehicle.cc Vehicle.h
	g++ -c Vehicle.cc -g

clean:
	rm -f $(OBJ) mechanicshop
