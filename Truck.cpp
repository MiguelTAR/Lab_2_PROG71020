//Miguel, Zuwair, and Ivan
// Lab 2 - Truck calculatioN
// Within this lab, the program uses classes to represent drivers, truck, and location
// It then calculates the distance from the truck's current location to the origin and prints the result.
//This is how truck companies might track their vehicles and measure distances with geometry.

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

//-----------------------
//Driver Class - Miguel
//_______________________

//The driver class represents the truck driver, 
// With attributes for their first name, last name, and a unique driver ID.
class Driver {
public:
	string first_name;// The driver's first name
	string last_name;//	The driver's last name
	int Driver_ID;// A unique identifier for the driver(Truck driver ID)

	// Constructor to initialize the driver's attributes
	Driver(string f, string l, int id) {
		first_name = f;
		last_name = l;
		Driver_ID = id;
	}

};


//-------------------------
//Location Class - Miguel
//_________________________

// The Location class represents a point in a 2D space,
class Location {
public:
	double x;// The x-coordinate of the location(horizantal)
	double y;// The y-coordinate of the location(vertical)

	// Constructor to initialize the location's coordinates
	Location(double x_coord, double y_coord) {
		x = x_coord;
		y = y_coord;
	}
};


//-------------------------
//Truck Class - Zuwair
//_________________________

// The Truck class represents a truck in the system.
// Each truck has a unique truck ID, a driver, and a location.
// The class also contains a function that calculates the
// distance between the truck's location and another location.

class Truck {
public:

	int Truck_ID;          // Unique truck identifier
	Driver driver;         // Driver assigned to the truck
	Location location;     // Current location of the truck

	// Constructor to initialize truck information
	Truck(int id, Driver d, Location l)
		: Truck_ID(id), driver(d), location(l) {
	}

	// Calculates the distance between the truck's current
	// location and another location using the distance formula.
	double distanceFrom(Location otherLocation) {

		return sqrt(
			pow(location.x - otherLocation.x, 2) +
			pow(location.y - otherLocation.y, 2)
		);
	}
};