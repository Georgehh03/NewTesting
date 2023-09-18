#include <iostream>
using namespace std;

// Function to calculate the population growth rate
double GrowthRate(double birthRate, double deathRate) {
    return birthRate - deathRate;
}

// Function to calculate the estimated population for the next year
double EstimatedPopulation(double currentPopulation, double birthRate, double deathRate) {
    return currentPopulation + (birthRate * currentPopulation) / 100 - (deathRate * currentPopulation) / 100;
}

int main() {
    double startingPopulation, birthRate, deathRate;
    int numYears;

    // Prompt the user for input with validation
    do {
        cout << "Enter the starting population (greater than or equal to 2): ";
        cin >> startingPopulation;

        if (startingPopulation < 2) {
            cout << "Starting population must be greater than or equal to 2. Please re-enter." << endl;
        }
    } while (startingPopulation < 2);

    do {
        cout << "Enter the birth rate (>= 0): ";
        cin >> birthRate;

        if (birthRate < 0) {
            cout << "Birth rate cannot be negative. Please re-enter." << endl;
        }
    } while (birthRate < 0);

    do {
        cout << "Enter the death rate (>= 0): ";
        cin >> deathRate;

        if (deathRate < 0) {
            cout << "Death rate cannot be negative. Please re-enter." << endl;
        }
    } while (deathRate < 0);

    cout << "Enter the number of years to project: ";
    cin >> numYears;

    // Calculate and display population growth rate
    double growthRate = GrowthRate(birthRate, deathRate);
    cout << "Population growth rate: " << growthRate << "%" << endl;

    // Calculate and display estimated population for each year
    for (int i = 1; i <= numYears; i++) {
        startingPopulation = EstimatedPopulation(startingPopulation, birthRate, deathRate);
        cout << "Estimated population after year " << i << ": " << startingPopulation << endl;
    }

    return 0;
}
