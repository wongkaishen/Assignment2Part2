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