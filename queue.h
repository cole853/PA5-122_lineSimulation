/*
        Programmer: Cole Clark
        date: 3/18/2021

            description: line simulation for PA5
*/

#pragma once

#include <iostream>

#include "queueNode.h"

class Queue
{
public: // Member functions

    //constructor
    Queue();

    //copy constructor
    Queue(Queue& copy);

    //destructor
    ~Queue();

    //getters
    QueueNode* getpHead();

    QueueNode* getpTail();

    //setters
    void setpHead(QueueNode* newpHead);

    void setpTail(QueueNode* newpTail);

    //adds an item to the list
    void enqueue(Data &data);

    //removes an item from the list
    void dequeue();

    //checks to see if the list is empty
    bool isEmpty();

    //prints the list to the screen
    void printList();

private:

    QueueNode* pHead;

    QueueNode* pTail;

};