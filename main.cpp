/*
        Programmer: Cole Clark
        date: 3/18/2021

            description: line simulation for PA5
*/

#include "QueueWrapper.h"

int main(void)
{
    srand((unsigned int) time(NULL));

    QueueWrapper app;
    QueueWrapper test;

    test.runTests();
    app.runapp();



    return 0;
}