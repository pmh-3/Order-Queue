//Heitkemper, Peter
//pa1.cpp
//3/2/21
//Driver file for donutQueue class
#include "donut.h"


int main()
{
	//change input file with fileName. 
	//Place in local directory or include file path.
	string fileName = "orders.csv";
	string first,flavor,strQuant;
	DonutQueue d;

	cout << "Welcome! Processing the " << fileName << " file..." << endl;
	cout << endl;

	//reading in file
	ifstream file(fileName);
	if (!file.is_open()) {
		cout << "ERROR";
		return -1;
	}
	//first line discarded
	getline(file, first);
	//extract all data
	while (file.good())
	{
		getline(file, flavor, ',');
	
		getline(file, strQuant, '\n');
		//convert string to integer
		int quantity = stoi(strQuant);
		//cout << flavor << endl;
		//cout << quantity << endl;
		d.enqueue(flavor,quantity);
	}

	cout << "Printing orders:" << endl;
	d.printOrders();
	cout << endl;
	cout << endl;
	cout << "Printing array:" << endl;
	d.printArray();
	cout << endl;
	cout << "We have to make " << d.getQuantity("Sprinkles") 
		<< " Sprinkled donuts." << endl;
	cout << endl;
	cout << endl;
	cout << "Dequeue Twice" << endl;
	d.dequeue();
	d.dequeue();
	cout << endl;
	cout << endl;
	cout << "Printing updated orders:" << endl;
	d.printOrders();
	cout << endl;
	cout << endl;
	cout << "Printing updated array:" << endl;
	d.printArray();
	cout << endl;
	cout << endl;
	cout << "Enque order of 99 sprinkles:" << endl;
	d.enqueue("Sprinkles",99);
	cout << endl;
	cout << "We have to make " << d.getQuantity("Sprinkles") 
		<< " Sprinkled donuts." << endl;
	cout << endl;
	cout << "Printing updated orders" << endl;
	d.printOrders();
	cout << endl;
	cout << endl;
	cout << "Printing updated array" << endl;
	d.printArray();
	cout << endl;
	cout << endl;
	cout << "Goodbye!" << endl;
	cout << endl;
	cout << "Begin testing..." << endl;
	cout << endl;
	cout << endl;
//Begin Testing
//*********************************************************************
	//DonutQueue d2;
	//cout << "Calling copy assignment. " << endl;
	//d2 = d;

	cout << "Calling copy constructor. " << endl;
	DonutQueue d2 = d;

	d2.printOrders();
	d2.printArray();

	cout << "dequeue copy" << endl;
	d2.dequeue();
	cout << "printing copy" << endl;
	d2.printArray();
	cout << "printing original" << endl;
	d.printArray();
//**********************************************************************
//End Testing
	file.close();
	return 0;
}

