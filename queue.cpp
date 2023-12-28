/*
        Programmer: Cole Clark
        date: 3/18/2021

            description: line simulation for PA5
*/

#include "queue.h"

//constructor
Queue::Queue()
{
    pHead = nullptr;
    pTail = nullptr;
}

//copy constructor
Queue::Queue(Queue& copy)
{
    pHead = copy.getpHead();
    pTail = copy.getpTail();
}

//destructor
Queue::~Queue()
{
    cout << "Inside Queue's destructor! freeing all items." << endl;

    while (!isEmpty())
    {
        dequeue();
    }
}

//getters
QueueNode* Queue::getpHead()
{
    return pHead;
}

QueueNode* Queue::getpTail()
{
    return pTail;
}

//setters
void Queue::setpHead(QueueNode* newpHead)
{
    pHead = newpHead;
}

void Queue::setpTail(QueueNode* newpTail)
{
    pTail = newpTail;
}

//adds an item to the list
void Queue::enqueue(Data& data)
{
    if (!isEmpty())
    {
        Data* newData = new Data(data);
        QueueNode* newNode = new QueueNode;

        newNode->setpData(newData);

        pTail->setpNext(newNode);
        setpTail(newNode);
    }
    else
    {
        Data* newData = new Data(data);
        QueueNode* newNode = new QueueNode;

        newNode->setpData(newData);

        setpTail(newNode);
        setpHead(newNode);
    }
}

//removes an item from the list
void Queue::dequeue()
{
    if (pHead != nullptr)
    {
        QueueNode* temp = pHead;

        setpHead(pHead->getpNext());
      
        delete temp->getpData();
        delete temp;

    }

    if (pHead == nullptr)
    {
        pTail = nullptr;
    }
}

//checks to see if the list is empty
bool Queue::isEmpty()
{
    if (pTail == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//prints the list to the screen
void Queue::printList()
{
    QueueNode* currentNode = pHead;

    for (int i = 0; currentNode != nullptr; ++i)
    {
        cout << i + 1 << ". Customer id: " << currentNode->getpData()->getCustomerNumber() << endl
            << "   Service time: " << currentNode->getpData()->getServiceTime() << endl
            << "   Total time: " << currentNode->getpData()->getTotalTime() << endl << endl;
        currentNode = currentNode->getpNext();
    }
}