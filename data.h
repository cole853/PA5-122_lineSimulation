/*
        Programmer: Cole Clark
        date: 3/18/2021

            description: line simulation for PA5
*/

#pragma once

#include <iostream>

using std::cout;
using std::endl;

class Data
{
public: // Member functions

    //constructor
    Data();

    //copy constructor
    Data(Data& copy);

    //destructor
    ~Data();


    //getters
    int getCustomerNumber();

    int getServiceTime();

    int getTotalTime();


    //setters
    void setCustomerNumber(int newCustomerNumber);

    void setServiceTime(int newServiceTime);

    void setTotalTime(int newTotalTime);

private:

    int customerNumber; // Unique identifier; starts at 1; after 24 hours should be reset to 1

    int serviceTime;   // Random time; varies between express and normal lanes; units in minutes

    int totalTime;     // totalTime = serviceTime + sum of serviceTimes of customers in line before this customer; units in minutes
}; // This memory needs to be allocated on the heap!