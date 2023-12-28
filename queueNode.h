/*
        Programmer: Cole Clark
        date: 3/18/2021

            description: line simulation for PA5
*/

#pragma once

#include <iostream>

#include "data.h"

class QueueNode
{
public: // Member functions

    //constructor
    QueueNode();

    //copy constructor
    QueueNode(QueueNode& copy);

    //destructor
    ~QueueNode();

    //getters
    Data* getpData();

    QueueNode* getpNext();

    //setters
    void setpData(Data* newData);

    void setpNext(QueueNode* newpNext);


private:

    Data* pData;    // The memory for Data will need to be allocated on the heap as well!

    QueueNode* pNext;

};