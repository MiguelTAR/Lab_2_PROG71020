// Lab 2 - Truck calculation
// Miguel, Zuwair, and Ivan

// Within this lab, the program uses classes to represent drivers, trucks, and locations.
// It calculates the distance between the two trucks and the distance from each truck to the origin.
// This is how truck companies might track their vehicles and measure distances with geometry.

#include <iostream>
#include <cmath>
#include <string>

using namespace std;


//-----------------------
// Driver Class - Miguel
//_______________________

//The driver class represents the truck driver, 
// With attributes for their first name, last name, and a unique driver ID.
class Driver 
{
public:
	string first_name;													// The driver's first name
	string last_name;													// The driver's last name
	int Driver_ID;														// A unique identifier for the driver(Truck driver ID)

	// Constructor to initialize the driver's attributes
	Driver(string f, string l, int id) 
	{
		first_name = f;
		last_name = l;
		Driver_ID = id;
	}
};


//-------------------------
// Location Class - Miguel
//_________________________

// The Location class represents a point in a 2D space.
class Location 
{
public:
	double x;															// The x-coordinate of the location(horizontal)
	double y;															// The y-coordinate of the location(vertical)

	// Constructor to initialize the location's coordinates
	Location(double x_coord, double y_coord) 
	{
		x = x_coord;
		y = y_coord;
	}
};


//-------------------------
// Truck Class - Zuwair
//_________________________

// The Truck class represents a truck in the system.
// Each truck has a unique truck ID, a driver, and a location.
// The class also contains a function that calculates the
// distance between the truck's location and another location.

class Truck 
{
public:

	int Truck_ID;														// Unique truck identifier
	Driver driver;														// Driver assigned to the truck
	Location location;													// Current location of the truck

	// Constructor to initialize truck information
	Truck(int id, Driver d, Location l)
		: Truck_ID(id), driver(d), location(l) 
	{
	}

	// Calculates the distance between the truck's current location and another location using the distance formula.
	double distanceFrom(Location otherLocation) 
	{
		return sqrt(pow(location.x - otherLocation.x, 2) + pow(location.y - otherLocation.y, 2));
	}

	// Overloaded function to calculate the distance from another truck's location.
	double distanceFrom(Truck otherTruck) 
	{
		return distanceFrom(otherTruck.location);
	}
};


//-------------------------
//	Main Function - Ivan
//-------------------------

int main() 
{
	Driver driver1("Liz", "Brian", 35);									// Creates a driver with the name "Liz Brian" and a driver ID of 35
	Driver driver2("Mike", "Smith", 69);								// Creates a driver with the name "Mike Smith" and a driver ID of 69

	Location location1(2, 3);											// Creates a location with coordinates (2, 3)
	Location location2(5, 2);											// Creates a location with coordinates (5, 2)
	Location origin(0, 0);												// Creates a location representing the origin (0, 0)

	Truck truck1(178534, driver1, location1);							// Creates a truck with ID 178534, assigned to driver1, and located at location1
	Truck truck2(245817, driver2, location2);							// Creates a truck with ID 245817, assigned to driver2, and located at location2

	cout << "The distance between the two trucks is: " << truck1.distanceFrom(truck2) << endl;								// Calculates and prints the distance between truck1 and truck2
	cout << "The distance between the truck (with ID = 178534) and the origin is: " << truck1.distanceFrom(origin) << endl;	// Calculates and prints the distance between truck1 and the origin
	cout << "The distance between the truck (with ID = 245817) and the origin is: " << truck2.distanceFrom(origin) << endl;	// Calculates and prints the distance between truck2 and the origin

	return 0;															// Returns 0 to indicate that the program ended successfully
}