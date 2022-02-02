/*
Written by : Ryan Vales
Student ID : S00339723
Written on : 7/9/21
Assignment : RyanValesHomework4.cpp
*/

// This project is intended to be a system that an airport may use when a customer
// enters the airport and is looking to schedule a flight according to varying criteria
// such as cost, depart time, destination, etc. 

#include "Flight.h"
#include "Global.h"

using namespace std;

int main() {
    while (shouldExit != true) {
        displayMenuOptions();
        handleMenuSelection();
    }

    return 0;
}