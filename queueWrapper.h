/*
        Programmer: Cole Clark
        date: 3/18/2021

            description: line simulation for PA5
*/

#pragma once

#include <cstdlib>
#include <ctime>

#include "queue.h"

using std::cin;

class QueueWrapper
{
public:

    //constructor
    QueueWrapper();

    //destructor
    ~QueueWrapper();

    //runs the app
    void runapp();

    //runs all test functions
    void runTests();

private:

    //tests for enqueue
    bool testEnqueueOne();

    bool testEnqueueEmpty();

    //tests for dequeue
    bool testDequeueOne();

    bool testDequeueTwo();

    //simulation test
    bool testSimulation();

    //simulation
    void simulation(int minutes);

    int time;

    int customerId;

    Queue normal;

    Queue express;

};