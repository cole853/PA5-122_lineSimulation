# PA5-122_lineSimulation
Simulation of two lines using linked lists for CPTS 122 programming assignment 5. Completed on 3/18/2021.

This program simulates two lines of people. One line is express where people take shorter times and the other is normal where people take longer times. The user can enter a time in minutes for the simulation to run.

# Nine Files Are Required:

data.h: contains the Data class where customer information is stored.

data.cpp: contains the definitions of Data class functions.

queueNode.h: contains the QueueNode class which has a pointer to a data object and a pointer to the next node.

queueNode.cpp: contains the definitions of QueueNode class functions.

queue.h: contains the Queue class with QueueNode head and tail pointers.

queue.cpp: contains the definitions of Queue class functions.

queueWrapper.h: contains the QueueWrapper class with normal and express queues, test functions, and the simulation function.

queueWrapper.cpp: contains the definitions of QueueWrapper class functions.

main.cpp: contains the main function for the simulation where QueueWrapper.runapp() is called.

# Possible Improvements

The program could be improved by making the output clearer and removing print statements in destructor functions. The lines are both printed every 10 minutes in the simulation with information about when people enter or leave a line in between.
