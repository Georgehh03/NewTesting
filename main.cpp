//Author: George Herrera Hurtado
//Date: 9/18/2023


#include <iostream>

using namespace std;


double GrowthRate(double BirthRate, double DeathRate)
{
    return BirthRate - DeathRate;
}

double EstPopulation(double StartingPopulation, double BirthRate, double DeathRate)
{
    return StartingPopulation + (BirthRate * StartingPopulation)
     / 100 - (DeathRate * StartingPopulation) / 100;
}


int main()
{
    double StartingPopulation, BirthRate, DeathRate, NumberYears;

    while (StartingPopulation<2)
    {
        cout << "Please enter a starting population equal or greater than 2: ";
        cin >> StartingPopulation;
    }

    while (BirthRate<1)
    {
        cout << "Enter the birth rate(CAN'T BE NEGATIVE): ";
        cin >> BirthRate;
    }

    while (DeathRate<1)
    {
        cout << "Enter the death rate(CAN'T BE NEGATIVE): ";
        cin >> DeathRate;
    }

    cout << "Enter number of years to project: ";
    cin >> NumberYears;


    double growthRate = GrowthRate(BirthRate, DeathRate);
    cout << "Population growth rate: " << growthRate << "%" << endl;



    for (int i = 1; i <= NumberYears; i++)
    {
        StartingPopulation = EstPopulation(StartingPopulation, BirthRate, DeathRate);
        cout << "Estimated population after year " << i << ": " << StartingPopulation << endl;
    }

    return 0;
}
