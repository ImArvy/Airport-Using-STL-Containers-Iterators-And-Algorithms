#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>
#include "Flight.h"
#include "Global.h"

using namespace std;

// Function definitions for member functions.
void Flight::setAirline(string airLineParam) {
    airLine = airLineParam;
}
string Flight::getAirline() {
    return airLine;
}

void Flight::setFlightDestination(string destinationParam) {
    flightDestination = destinationParam;
}
string Flight::getFlightDestination() {
    return flightDestination;
}

void Flight::setFlightNumber(int numberParam) {
    flightNumber = numberParam;
}
int Flight::getFlightNumber() {
    return flightNumber;
}

void Flight::setFlightPrice(int priceParam) {
    flightPrice = priceParam;
}
int Flight::getFlightPrice() {
    return flightPrice;
}

void Flight::setFlightDuration(int durationParam) {
    flightDuration = durationParam;
}
int Flight::getFlightDuration() {
    return flightDuration;
}

void Flight::setDepartTime(int departTimeParam) {
    flightDepartTime = departTimeParam;
}
int Flight::getDepartTime() {
    return flightDepartTime;
}

//----------------------------------------------------------------------------------------------

bool shouldExit = false; // This global boolean will determine if the program should exit or not.

vector<Flight> flightsVector; // Vector container to hold all flights.
vector<string> airLinesVector; // Vector container to hold the names of airlines of all flights.
vector<string> destinationsVector; //Vector container to hold the depart times of all flights.
vector<int> flightNumbersVector; // Vector container to hold the flight numbers of all flights.
vector<int> pricesVector; // Vector container to hold the prices of all flights.
vector<int> durationsVector; // Vector container to hold the duration of all flights.
vector<int> departTimesVector; // Vector container to hold the departure times of all flights.

void displayMenuOptions() { // This function will display the menu to the user
    cout << "Welcome to the Auburn University at Montgomery Airport!" << "\n\n";
    
    cout << "Here is a list of our menu options:" << "\n\n";

    cout << "1) Add new flight(s) to the list." << endl;
    cout << "2) View the list of flights." << endl;
    cout << "3) See if there is a flight with your desired airline." << endl;
    cout << "4) Check if there is a flight with your flight number." << endl;
    cout << "5) Find the flight with the lowest price." << endl;
    cout << "6) Find the flight with the highest price." << endl;
    cout << "7) See if there is a flight with the right duration for you." << endl;
    cout << "8) Remove a flight from the system." << endl;
    cout << "9) Exit the system." << endl;

    cout << "\n";
}

void addNewFlights() { // This function allows the user to create a new flight and add it to the vector of flights.
    int newFlightAmount; // Integer that will determine number of flights to be added upon calling this function.
    Flight newFlight; // Creates a class object of class Flight.

    string newAirLine;
    string newFlightDestination;
    int newFlightNumber;
    int newFlightPrice;
    int newFlightDuration;
    int newFlightDepartTime;

    // Prompts user to enter the desired number of flights to add.
    cout << "Please enter the amount of flights you wish to add to the database: ";
    cin >> newFlightAmount;

    cout << "\n\n";

    // For the amount of flights to add.
    for (int i = 0; i < newFlightAmount; i++) {

        // Retrieve information from user to add to the flight that is currently being added to the vector.
        cout << "Please enter the name of the airline: ";
        cin.ignore();
        getline(cin, newAirLine);

        newFlight.setAirline(newAirLine); // Set the airline for this flight object.
        airLinesVector.push_back(newAirLine); // Add this airline name to the airLinesVector.

        cout << "Please enter the flight destination: ";
        getline(cin, newFlightDestination);

        newFlight.setFlightDestination(newFlightDestination); // Set the destination for this flight object.
        destinationsVector.push_back(newFlightDestination); // Add this destination to the destinationsVector.

        cout << "Please enter the flight number: ";
        cin >> newFlightNumber;

        newFlight.setFlightNumber(newFlightNumber); // Set the flight number for this flight object.
        flightNumbersVector.push_back(newFlightNumber); // Add this flight number to the flightNumbersVector.

        cout << "Please enter the price of the new flight: ";
        cin >> newFlightPrice;

        newFlight.setFlightPrice(newFlightPrice); // Set the price for this flight object.
        pricesVector.push_back(newFlightPrice); // Add this price to the pricesVector.

        cout << "Please enter the total duration of the new flight: ";
        cin >> newFlightDuration;

        newFlight.setFlightDuration(newFlightDuration); // Set the duration for this flight object.
        durationsVector.push_back(newFlightDuration); // Add this duration to the durationsVector.

        cout << "Please enter the depart time of the new flight: ";
        cin >> newFlightDepartTime;

        newFlight.setDepartTime(newFlightDepartTime); // Set the time of departure for this flight object.
        departTimesVector.push_back(newFlightDepartTime); // Add this depart time to the departTimesVector.

        cout << "\n";

        flightsVector.push_back(newFlight); // Now that we have the information for a new flight, add to the flightsVector vector.
    }
}

void displayFlights() { // This will display all flights currently stored in the vector.
    if (flightsVector.size() == 0) {
        cout << "There are currently no flights in the databse" << endl;
        cout << "Please consider adding flights using the first menu option." << endl;
    }
    else {
        for (int i = 0; i < flightsVector.size(); i++) {
            cout << "Here is the information for Flight " << i + 1 << " : " << endl;
            cout << "Airline: " << flightsVector[i].getAirline() << endl;
            cout << "Destination: " << flightsVector[i].getFlightDestination() << endl;
            cout << "Flight Number: " << flightsVector[i].getFlightNumber() << endl;
            cout << "Price :" << flightsVector[i].getFlightNumber() << endl;
            cout << "Flight Duration: " << flightsVector[i].getFlightDuration() << endl;
            cout << "Depart Time: " << flightsVector[i].getDepartTime() << endl;
        }
    }
}

void searchByAirline() { // This function will show the user how many flights there are under a specified airline.
    string desiredAirline = "";
    cout << "Please enter the airline you are searching for: ";
    cin >> desiredAirline;

    cout << "\n";

    int airlineCount = count(airLinesVector.begin(), airLinesVector.end(), desiredAirline);
    cout << "There are " << airlineCount << " flights under your desired airline." << endl;

    cout << "\n\n";
}

void searchByFlightNumber() { // This function will check if there is a flight with a specified flight number for the user.
    int desiredFlightNumber = 0;
    cout << "Please enter the flight number you are searching for: ";
    cin >> desiredFlightNumber;

    cout << "\n";

    auto flightNumberIter = find(flightNumbersVector.begin(), flightNumbersVector.end(), desiredFlightNumber);
    if (flightNumberIter == flightNumbersVector.end()) {
        cout << "Sorry, it does not appear this flight number is in our system." << endl;
    }
    else {
        cout << "You are in luck, we found your flight number!" << endl;
    }

    cout << "\n\n";
}

void findLowestPrice() { // This function will find the lowest price of all flights.
    auto minPriceIter = min_element(pricesVector.begin(), pricesVector.end());
    cout << "The lowest priced flight is: " << *minPriceIter << endl;
}

void findHighestPrice() { // This function will find the highest price of all flights.
    auto maxPriceIter = max_element(pricesVector.begin(), pricesVector.end());
    cout << "The highest priced flight is: " << *maxPriceIter << endl;
}

void checkFlightDuration() { // This function will check if there is a flight with a duration desired by the customer.
    int desiredFlightDuration = 0;
    cout << "Please enter your desired flight duration: ";
    cin >> desiredFlightDuration;

    cout << "\n";

    list<int> durationsList(durationsVector.begin(), durationsVector.end());
    durationsList.sort();
    bool foundDuration = binary_search(durationsList.begin(), durationsList.end(), desiredFlightDuration);

    if (foundDuration == true) {
        cout << "It is your lucky day, we found a flight that matches your desired duration!" << endl;
    }
    else {
        cout << "Sorry for the inconvenience but we can not find a flight that matches your desired duration" << endl;
    }

    cout << "\n\n";
}

void removeByFlightNumber() {
    int flightNumberToDelete;
    cout << "Please enter the flight you would like to delete by flight number: ";
    cin >> flightNumberToDelete;

    cout << "\n";

    auto flightNumberIter = remove(flightNumbersVector.begin(), flightNumbersVector.end(), flightNumberToDelete);
    flightNumbersVector.erase(flightNumberIter, flightNumbersVector.end());

    for (auto n : flightNumbersVector) {
        cout << "Here is the new list of flights by flight number: " << flightNumbersVector[n] << endl;
    }
}

void removeByPrice() {
    int priceToDelete;
    cout << "Please enter the flight you would like to delete by price: ";
    cin >> priceToDelete;

    cout << "\n";

    auto priceIter = remove(pricesVector.begin(), pricesVector.end(), priceToDelete);
    pricesVector.erase(priceIter, pricesVector.end());

    for (auto p : pricesVector) {
        cout << "Here is the new list of flights by price: " << pricesVector[p];
    }
}

void removeByDuration() {
    int durationToDelete;
    cout << "Please enter the flight you would like to delete by duration: ";
    cin >> durationToDelete;

    cout << "\n";

    auto durationIter = remove(durationsVector.begin(), durationsVector.end(), durationToDelete);
    durationsVector.erase(durationIter, durationsVector.end());

    for (auto d : durationsVector) {
        cout << "Here is the new list of flights by duration: " << durationsVector[d];
    }
}

void removeByDepartTime() {
    int departTimeToDelete;
    cout << "Please enter the flight you would like to delete by time of departure: ";
    cin >> departTimeToDelete;

    cout << "\n";

    auto departTimeIter = remove(departTimesVector.begin(), departTimesVector.end(), departTimeToDelete);
    departTimesVector.erase(departTimeIter, departTimesVector.end());

    for (auto t : departTimesVector) {
        cout << "Here is the new list of flights by time of departure: " << departTimesVector[t];
    }
}

void flightRemoval() { // This function will allow the user to remove a flight from a vector of their choice.
    enum class removalMethods { byFlightNumber = 1, byFlightPrice, byFlightDuration, byFlightDepartTime };

    cout << "Please enter the criteria by which you would like to remove a flight from the system: " << endl;
    cout << "1) Remove by flight number." << endl;
    cout << "2) Remove by flight price." << endl;
    cout << "3) Remove by flight duration." << endl;
    cout << "4) Remove by time of departure." << endl;

    cout << "\n";

    int userChoice = 0;
    cin >> userChoice;

    cout << "\n";

    removalMethods method = static_cast<removalMethods>(userChoice);

    switch (method) {
    case removalMethods::byFlightNumber:
        removeByFlightNumber();
        break;

    case removalMethods::byFlightPrice:
        removeByPrice();
        break;

    case removalMethods::byFlightDuration:
        removeByDuration();
        break;

    case removalMethods::byFlightDepartTime:
        removeByDepartTime();
        break;
    }
}

void handleMenuSelection() { // This function will handle user input in regards to menu selection.
    enum class menuOptions { choiceOne = 1, choiceTwo, choiceThree, choiceFour, choiceFive, choiceSix, choiceSeven, choiceEight, choiceNine };

    cout << "Please enter your desired menu option: ";
    int userChoice = 0;
    cin >> userChoice;

    cout << "\n";

    menuOptions option = static_cast<menuOptions>(userChoice);

    switch (option) {
    case menuOptions::choiceOne:
        addNewFlights();
        break;

    case menuOptions::choiceTwo:
        displayFlights();
        break;

    case menuOptions::choiceThree:
        searchByAirline();
        break;

    case menuOptions::choiceFour:
        searchByFlightNumber();
        break;

    case menuOptions::choiceFive:
        findLowestPrice();
        break;

    case menuOptions::choiceSix:
        findHighestPrice();
        break;

    case menuOptions::choiceSeven:
        checkFlightDuration();
        break;

    case menuOptions::choiceEight:
        flightRemoval();
        break;

    case menuOptions::choiceNine:
        cout << "Thank you for flying with us, we hope to see you again in your future travels!" << endl;
        shouldExit = true; // Set global boolean shouldExit to true to break the main loop and terminate the program.
        break;
    }
}