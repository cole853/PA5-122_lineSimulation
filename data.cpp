/*
        Programmer: Cole Clark
        date: 3/18/2021

            description: line simulation for PA5
*/

#include "data.h"

//constructor
Data::Data()
{
    this->customerNumber = 0;
    this->serviceTime = 0;
    this->totalTime = 0;
}

//copy constructor
Data::Data(Data& copy)
{
    this->customerNumber = copy.getCustomerNumber();
    this->serviceTime = copy.getServiceTime();
    this->totalTime = copy.getTotalTime();
}

//destructor
Data::~Data()
{
    cout << "Inside Data's destructor!" << endl;
}


//getters
int Data::getCustomerNumber()
{
    return customerNumber;
}

int Data::getServiceTime()
{
    return serviceTime;
}

int Data::getTotalTime()
{
    return totalTime;
}


//setters
void Data::setCustomerNumber(int newCustomerNumber)
{
    customerNumber = newCustomerNumber;
}

void Data::setServiceTime(int newServiceTime)
{
    serviceTime = newServiceTime;
}

void Data::setTotalTime(int newTotalTime)
{
    totalTime = newTotalTime;
}