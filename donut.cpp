//Peter Heitkemper
//donut.cpp
//3/2/21

#include "donut.h"

DonutQueue::DonutQueue()
{
	int front = 0;
	int size = 0;
	int id = 1;
	Order cqueue[MAX_SIZE];
}

DonutQueue::~DonutQueue() 
{
	id = 0;
};

DonutQueue::DonutQueue(const DonutQueue& source)
{
	front = source.front;
	size = source.size;
	id = source.id;
	//copy over each object in array
	for (int i = 0; i < MAX_SIZE; i++) {
		cqueue[i] = source.cqueue[i];
	}
}

DonutQueue& DonutQueue::operator=(const DonutQueue& q) 
{
	front = q.front;
	size = q.size;
	id = q.id;
	for (int i = 0; i <MAX_SIZE; i++) {
		cqueue[i] = q.cqueue[i];
	}
	return *this;
}

DonutQueue::Order::Order(string flavor, int quantity) :
	flavor{ flavor }, quantity{ quantity }, orderNum{ 0 }{}

DonutQueue::Order::Order() 
{
	flavor = "";
	quantity = 0;
	orderNum = 0;
}

DonutQueue::Order::~Order() {};

void DonutQueue::enqueue(string flavor, int quantity) 
{						
	if (size+1 > MAX_SIZE) {
		cout << "Queue is full. " << endl;
	} else {
		//add new order
		Order x(flavor, quantity);
		x.setOrderNum(id);
		//add order to back of queue
		cqueue[((front + size) % MAX_SIZE)] = x;
		//increment order id and size of elements in array
		id++;
		size++;
	}
}

int DonutQueue::dequeue() 
{
	if (size == 0){
		cout << "Queue is empty"<< endl;
		return -1;
	} else {
		//store and return order number
		int order = cqueue[front].getOrderNum();
		//set quanitity of donuts in invalid order to 0
		cqueue[front].setQuant(0);
		//calculate new front
		front = (front + 1) % MAX_SIZE;
		size--;
		return order;
	}
}

int DonutQueue::getSize() 
{
	return size;
}

int DonutQueue::getQuantity(string flavor)
{
	int totalQuant = 0;
	//cycle through elements in array and update total quantity
	//if flavor matches
	for (int i = 0; i < MAX_SIZE; i++) {
		//do nothing if array index is empty
		if (cqueue[i].getQuant() == 0) { 
		}	else if (cqueue[i].getFlavor() == flavor) {
			totalQuant = totalQuant + cqueue[i].getQuant();
		}	else {}//do nothing
	}
	return totalQuant;
}


void DonutQueue::printOrders() 
{
	if (front == -1) {
		cout << "No orders are in queue." << endl;
	} else {
		for (int i = 0; i < MAX_SIZE; i++) {
			//do nothing if array index is empty
			if (cqueue[i].getQuant() == 0) { 
			} else {
				cout << "Order #" << cqueue[i].getOrderNum() << " " <<
				cqueue[i].getFlavor() << " x " << cqueue[i].getQuant() << endl;
			}
		}

	}
}

void DonutQueue::printArray() 
{
	if (front == -1){
		cout << "Array is empty."<<endl;
		return;
	} else {
		//cycle through each element in array
		for (int i = 0; i < MAX_SIZE; i++){
			if (cqueue[i].getQuant() == 0) {
				cout << "arr[" << i << "] = no order" << endl;
			} else {
				cout << "arr[" << i << "] = Order #" 
				<< cqueue[i].getOrderNum() << endl;
			}
		}
	}
}

