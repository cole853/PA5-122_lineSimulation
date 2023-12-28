/*
        Programmer: Cole Clark
        date: 3/18/2021

            description: line simulation for PA5
*/

#include "queueNode.h"

//constructor
QueueNode::QueueNode()
{
    this->pData = nullptr;
    this->pNext = nullptr;
}

//copy constructor
QueueNode::QueueNode(QueueNode& copy)
{
    pData = copy.getpData();
    pNext = copy.getpNext();
}

//destructor
QueueNode::~QueueNode()
{
    cout << "Inside QueueNode's destructor!" << endl;
}

//getters
Data* QueueNode::getpData()
{
    return pData;
}

QueueNode* QueueNode::getpNext()
{
    return pNext;
}

//setters
void QueueNode::setpData(Data* newData)
{
    pData = newData;
}

void QueueNode::setpNext(QueueNode* newpNext)
{
    pNext = newpNext;
}