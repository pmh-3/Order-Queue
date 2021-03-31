//Heitkemper, Peter
//donut.h
//3/2/21


//**********************************************************************
//DESCRIPTION: This program reads in donut orders from a CSV file
//and stores each order in a queue immplemented with a circular array.
//There are functions to add, delete, get the quantity of a flavor, 
//and print the Queue or the array.

//ASSUMPTION:The input file must have flavor and quantity seperated
//by commas.This circular array is of size 7.Flavor must match exactly
//inorder for the program to update total quantity.
//***********************************************************************

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//Max size of circular array.
#define MAX_SIZE  7

class DonutQueue {

public:
	//Default Constuctor
	DonutQueue();
	//Destructor
	~DonutQueue();
	//Copy constructor
	DonutQueue(const DonutQueue& q);
	//Copy Assignment
	DonutQueue& operator = (const DonutQueue& q);

	// description: adds an order to back of queue.
	// preconditions: Input types must match. 
	// postconditions: Cannot add an order if queue is full
	void enqueue(string flavor, int quantity);

	// description: Deletes the front order from queue.
	// preconditions: Cannot delete an order if queue is empty.
	// postconditions: Returns order number, elements in array decrease.
	int dequeue();

	// description: Returns the number of elements in queue.
	// preconditions: none
	// postconditions: returns between 0 and MAX_SIZE
	int getSize();

	// description: finds all orders of the flavor and returns
	//the total quantity.
	// preconditions: flavor name must match exactly.
	// postconditions: does not alter queue.
	int getQuantity(string flavor);

	// description: prints all orders on the list starting 
	//from the earliest to 
	//the most recent order.
	// preconditions: none.
	// postconditions: does not alter queue
	void printOrders();

	// description: prints the order number at each index of the array, 
	//including the empty cells.
	//the most recent order.
	// preconditions: none.
	// postconditions: does not alter queue
	void printArray();


private:
	class Order {
	public:
		//Default constructor
		Order();
		//Parameterized Constructor
		Order(string flavor, int quantity);
		//destructor
		~Order();

		//Getters and Setters
		int getOrderNum() { return orderNum; }
		void setOrderNum(int id) { orderNum = id; }

		string getFlavor() { return flavor; }

		int getQuant() { return quantity; }
		void setQuant(int quant) { quantity = quant; }

	private:
		string flavor;
		int quantity;
		//holds order id specfic to order
		int orderNum;
	};

	//Circular array index variables
	int front = 0;
	int size = 0;
	//# of orders starting form 1 and incrementing for each inputted order
	int id = 1;
	Order cqueue[MAX_SIZE];
};

