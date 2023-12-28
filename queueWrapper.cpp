/*
        Programmer: Cole Clark
        date: 3/18/2021

            description: line simulation for PA5
*/

#include "queueWrapper.h"


//constructor
QueueWrapper::QueueWrapper()
{
   
}

//destructor
QueueWrapper::~QueueWrapper()
{
    cout << "Inside QueueWrapper's destructor!" << endl;
}

//runs the app
void QueueWrapper::runapp()
{
    int response = 0;

    do
    {
        system("cls");
        cout << "Enter the number of minutes for the simulation to run: " << endl;
        cin >> response;

    } while (response < 1);

    system("cls");

    simulation(response);
}


//tests for enqueue
bool QueueWrapper::testEnqueueOne()
{
    Queue test;
    Data temp;
    Data temp2;

    temp.setCustomerNumber(1);
    temp2.setCustomerNumber(2);

    test.enqueue(temp);
    test.enqueue(temp2);

    if (test.getpHead()->getpData()->getCustomerNumber() == 1 && test.getpTail()->getpData()->getCustomerNumber() == 2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool QueueWrapper::testEnqueueEmpty()
{
    Queue test; 
    Data temp;

    temp.setCustomerNumber(1);

    test.enqueue(temp);

    if (test.getpHead() == test.getpTail() && test.getpHead()->getpData()->getCustomerNumber() == 1)
    {

        return true;
    }
    else
    {
        return false;
    }
}

//tests for dequeue
bool QueueWrapper::testDequeueOne()
{
    Queue test;
    Data temp;

    temp.setCustomerNumber(1);

    test.enqueue(temp);
    test.dequeue();

    if (test.getpHead() == nullptr && test.getpTail() == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool QueueWrapper::testDequeueTwo()
{
    Queue test;
    Data temp;
    Data temp2;

    temp.setCustomerNumber(1);
    temp2.setCustomerNumber(2);

    test.enqueue(temp);
    test.enqueue(temp2);

    test.dequeue();

    if (test.getpHead()->getpData()->getCustomerNumber() == 2 && test.getpTail() == test.getpHead())
    {
        return true;
    }
    else
    {
        return false;
    }
}

//simulation test
bool QueueWrapper::testSimulation()
{
    simulation(1440);

    if (time == 0 && customerId == 0)
    {
        return true;
    }
    else
    {
        return false;
    }

    while (!normal.isEmpty())
    {
        normal.dequeue();
    }

    while (!express.isEmpty())
    {
        express.dequeue();
    }
}

//simulation
void QueueWrapper::simulation(int minutes)
{
    int expressArrival = 0;
    int normalArrival = 0;
    int serviceTime = 0;
    int totalTime = 0;
    int expressLeave = 0;
    int normalLeave = 0;
    QueueNode* current = nullptr;
    Data temp;

    for (int i = 0; i != minutes; ++i)
    {

        if (!express.isEmpty())
        {
            ++expressLeave;
        }
        if (!normal.isEmpty())
        {
            ++normalLeave;
        }

        if (time == 0)
        {

            expressArrival = (rand() % 5 + 1) + time;
            normalArrival = (rand() % 6 + 3) + time;

        }

        if (expressArrival == time)
        {
            ++customerId;
            cout << "Customer " << customerId << " arrived in the express lane at " << time << " minutes." << endl;

            temp.setCustomerNumber(customerId);
            serviceTime = rand() % 5 + 1;
            temp.setServiceTime(serviceTime);

            current = express.getpHead();
            while (current != nullptr)
            {
                totalTime += current->getpData()->getServiceTime();
                current = current->getpNext();
            }

            totalTime += serviceTime;

            totalTime = totalTime - expressLeave;

            temp.setTotalTime(totalTime);
            totalTime = 0;

            express.enqueue(temp);

            expressArrival = (rand() % 5 + 1) + time;
        }

        if (normalArrival == time)
        {
            ++customerId;
            cout << "Customer " << customerId << " arrived in the normal lane at " << time << " minutes." << endl;

            temp.setCustomerNumber(customerId);
            serviceTime = rand() % 6 + 3;
            temp.setServiceTime(serviceTime);

            current = normal.getpHead();
            while (current != nullptr)
            {
                totalTime += current->getpData()->getServiceTime();
                current = current->getpNext();
            }

            totalTime += serviceTime;

            totalTime = totalTime - normalLeave;

            temp.setTotalTime(totalTime);
            totalTime = 0;

            normal.enqueue(temp);

            normalArrival = (rand() % 6 + 3) + time;
        }

        if (!express.isEmpty() && express.getpHead()->getpData()->getServiceTime() == expressLeave)
        {
            cout << "Customer " << express.getpHead()->getpData()->getCustomerNumber() << " is leaving the express lane after waiting " << express.getpHead()->getpData()->getTotalTime() << " minutes" << endl;

            express.dequeue();

            expressLeave = 0;
        }

        if (!normal.isEmpty() && normal.getpHead()->getpData()->getServiceTime() == normalLeave)
        {
            cout << "Customer " << normal.getpHead()->getpData()->getCustomerNumber() << " is leaving the normal lane after waiting " << normal.getpHead()->getpData()->getTotalTime() << " minutes" << endl;

            normal.dequeue();

            normalLeave = 0;
        }

        if (time % 10 == 0)
        {
            cout << endl << "Express Line (front)" << endl << endl;
            express.printList();

            cout << endl << "Normal Line (front)" << endl << endl;
            normal.printList();
            cout << endl;
        }

        ++time;
        if (time == 1440)
        {
            time = 0;
            customerId = 0;
        }
    }
}

//runs all test functions
void QueueWrapper::runTests()
{
    bool check;

    check = this->testEnqueueEmpty();

    if (check == false)
    {
        system("cls");
        cout << "enqueue() failed when queue was empty." << endl << endl;
        system("pause");
    }
    else
    {

        check = testEnqueueOne();

        if (check == false)
        {
            system("cls");
            cout << "enqueue() failed when queue had one node." << endl << endl;
            system("pause");
        }
        else
        {

            check = testDequeueOne();

            if (check == false)
            {
                system("cls");
                cout << "dequeue() failed when queue had one node." << endl << endl;
                system("pause");
            }
            else
            {

                check = testDequeueTwo();

                if (check == false)
                {
                    system("cls");
                    cout << "dequeue() failed when queue had two nodes." << endl << endl;
                    system("pause");
                }
                else
                {
                    check = testSimulation();

                    if (check == false)
                    {
                        system("cls");
                        cout << "simulation() failed." << endl << endl;
                        system("pause");
                    }
                    else
                    {
                        system("cls");
                        cout << "all functions tested successfully!" << endl << endl;
                        system("pause");
                    }
                }
            }
        }
    }
}