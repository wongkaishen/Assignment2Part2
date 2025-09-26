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
    
    // Pause before closing
    cout << "\nPress Enter to exit...";
    cin.ignore();
    cin.get();
    
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

double calculateBaseFare(int service, double distance) {
    double baseFare, perKmRate;
    
    // Service-specific pricing structure
    switch(service) {
        case 1: // GrabCar
            baseFare = 3.00;
            perKmRate = 1.50;
            break;
        case 2: // GrabBike
            baseFare = 2.00;
            perKmRate = 0.80;
            break;
        case 3: // GrabShare
            baseFare = 2.50;
            perKmRate = 1.20;
            break;
        case 4: // GrabCar Premium
            baseFare = 5.00;
            perKmRate = 2.20;
            break;
        default:
            baseFare = 3.00;
            perKmRate = 1.50;
    }
    
    // Calculate total base fare
    double totalFare = baseFare + (distance * perKmRate);
    
    // Apply distance-based discounts for longer trips
    if (distance > 20) {
        totalFare *= 0.95; // 5% discount for trips over 20km
    } else if (distance > 10) {
        totalFare *= 0.97; // 3% discount for trips over 10km
    }
    
    return totalFare;
}

double applyPeakSurcharge(double baseFare, int timeChoice) {
    double surgeMultiplier;
    
    switch(timeChoice) {
        case 1: // Off-peak
            surgeMultiplier = 1.0;
            break;
        case 2: // Peak hours
            surgeMultiplier = 1.5;
            break;
        case 3: // Late night
            surgeMultiplier = 2.0;
            break;
        default:
            surgeMultiplier = 1.0;
    }
    
    return baseFare * surgeMultiplier;
}

void displayFareBreakdown(int service, double distance, int timeChoice, double baseFare, double finalFare) {
    string serviceName, timeName;
    
    // Safe service name selection
    switch(service) {
        case 1: serviceName = "GrabCar"; break;
        case 2: serviceName = "GrabBike"; break;
        case 3: serviceName = "GrabShare"; break;
        case 4: serviceName = "GrabCar Premium"; break;
        default: serviceName = "Unknown"; break;
    }
    
    // Safe time name selection
    switch(timeChoice) {
        case 1: timeName = "Off-Peak"; break;
        case 2: timeName = "Peak Hours"; break;
        case 3: timeName = "Late Night"; break;
        default: timeName = "Unknown"; break;
    }
    
    cout << "\n========================================" << endl;
    cout << "         FARE BREAKDOWN" << endl;
    cout << "========================================" << endl;
    cout << fixed << setprecision(2);
    cout << "Service Type    : " << serviceName << endl;
    cout << "Distance        : " << distance << " km" << endl;
    cout << "Time Period     : " << timeName << endl;
    cout << "----------------------------------------" << endl;
    cout << "Base Fare       : RM " << baseFare << endl;
    
    if (timeChoice > 1) {
        double surgeAmount = finalFare - baseFare;
        cout << "Surge Charge    : RM " << surgeAmount << endl;
    }
    
    cout << "========================================" << endl;
    cout << "TOTAL FARE      : RM " << finalFare << endl;
    cout << "========================================" << endl;
    
      // Calculate estimated arrival time based on distance and time period
    int baseTime, travelMultiplier;
    
    switch(timeChoice) {
        case 1: // Off-peak - faster travel
            baseTime = 3;
            travelMultiplier = 2;
            break;
        case 2: // Peak hours - slower due to traffic
            baseTime = 8;
            travelMultiplier = 3;
            break;
        case 3: // Late night - fewer drivers available
            baseTime = 12;
            travelMultiplier = 2;
            break;
        default:
            baseTime = 3;
            travelMultiplier = 2;
    }
    
    int arrivalTime = (int)(distance * travelMultiplier) + baseTime;
    if (arrivalTime > 45) arrivalTime = 45; // Cap at 45 minutes
    
    // Additional information
    cout << "\nThank you for choosing Grab!" << endl;
    cout << "Estimated arrival: " << arrivalTime << " minutes" << endl;
}