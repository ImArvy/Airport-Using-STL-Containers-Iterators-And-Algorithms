#ifndef FLIGHT_H
#define FLIGHT_H

#include <string>

using namespace std;

// Class for flights.
class Flight {
    private: // Private contains data members.
        string airLine = "";
        string flightDestination = "";
        int flightNumber = 0;
        int flightPrice = 0;
        int flightDuration = 0;
        int flightDepartTime = 0;
    public: // Public contains member function prototypes.
        void setAirline(string);
        string getAirline();

        void setFlightDestination(string);
        string getFlightDestination();

        void setFlightNumber(int);
        int getFlightNumber();

        void setFlightPrice(int);
        int getFlightPrice();

        void setFlightDuration(int);
        int getFlightDuration();

        void setDepartTime(int);
        int getDepartTime();
};

// Function declarations to be defined in Flight.cpp
void displayMenuOptions();
void handleMenuSelection();

#endif // FLIGHT_H