#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

// Function declarations
void displayWelcome();
void displayServices();
int getServiceChoice();
double getDistance();
int getTimeChoice();
double calculateBaseFare(int service, double distance);
double applyPeakSurcharge(double baseFare, int timeChoice);
void displayFareBreakdown(int service, double distance, int timeChoice, double baseFare, double finalFare);

int main() {
    displayWelcome();
    
    // Get user inputs
    int serviceChoice = getServiceChoice();
    double distance = getDistance();
    int timeChoice = getTimeChoice();
    
    // Calculate fare
    double baseFare = calculateBaseFare(serviceChoice, distance);
    double finalFare = applyPeakSurcharge(baseFare, timeChoice);
    
    // Display results
    displayFareBreakdown(serviceChoice, distance, timeChoice, baseFare, finalFare);
    
    return 0;
}

void displayWelcome() {
    cout << "========================================" << endl;
    cout << "    GRAB FARE CALCULATOR v2.0" << endl;
    cout << "========================================" << endl;
    cout << "Calculate your ride fare instantly!" << endl;
    cout << "----------------------------------------" << endl;
}

void displayServices() {
    cout << "\nAvailable Grab Services:" << endl;
    cout << "1. GrabCar (RM 1.50/km + RM 3.00 base)" << endl;
    cout << "2. GrabBike (RM 0.80/km + RM 2.00 base)" << endl;
    cout << "3. GrabShare (RM 1.20/km + RM 2.50 base)" << endl;
    cout << "4. GrabCar Premium (RM 2.20/km + RM 5.00 base)" << endl;
}

int getServiceChoice() {
    int choice;
    bool validInput = false;
    
    while (!validInput) {
        displayServices();
        cout << "\nSelect service (1-4): ";
        
        if (cin >> choice) {
            if (choice >= 1 && choice <= 4) {
                validInput = true;
            } else {
                cout << "Error: Please enter a number between 1-4." << endl;
            }
        } else {
            cout << "Error: Invalid input. Please enter a number." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }
    return choice;
}

double getDistance() {
    double distance;
    bool validInput = false;
    
    while (!validInput) {
        cout << "\nEnter distance (km): ";
        
        if (cin >> distance) {
            if (distance > 0 && distance <= 100) {
                validInput = true;
            } else {
                cout << "Error: Distance must be between 0.1-100 km." << endl;
            }
        } else {
            cout << "Error: Please enter a valid number." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }
    return distance;
}

int getTimeChoice() {
    int choice;
    bool validInput = false;
    
    while (!validInput) {
        cout << "\nTime of Day:" << endl;
        cout << "1. Off-Peak (6AM-7AM, 10AM-4PM, 8PM-12AM)" << endl;
        cout << "2. Peak Hours (7AM-10AM, 4PM-8PM) - 1.5x surge" << endl;
        cout << "3. Late Night (12AM-6AM) - 2.0x surge" << endl;
        cout << "Select time (1-3): ";
        
        if (cin >> choice) {
            if (choice >= 1 && choice <= 3) {
                validInput = true;
            } else {
                cout << "Error: Please enter 1, 2, or 3." << endl;
            }
        } else {
            cout << "Error: Invalid input. Please enter a number." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }
    return choice;
}