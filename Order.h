#ifndef __ORDER_H__
#define __ORDER_H__

#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

class Product;
class Employee;
class Customer;
const int I_SIZE = 5;
class Order {
private:
	int numItems; // current items in array
	int itemsMaxSize; // current items array max size
	Product** items;

	const Employee& employee;
	const Customer& customer;

	Order(const Order& other);
	const Order& operator=(const Order& other)=delete;
	const Order& operator=(Order&& other)=delete;
public:
	friend class Shift;
	// ctor
	Order(const Employee& employee, const Customer& customer);		
	// dtor
	~Order();

	// operators
	Product* operator[](int index)noexcept(false);
	const Product* operator[](int index) const noexcept(false);
	Order operator+(const Order& order);

	// getters
	int getNumItems() const { return numItems; }
	Product** const getItems() const { return items; }
	const Employee& getEmployee() const { return employee; }
	const Customer& getCustomer() const { return customer; }

	// clone
	Order* clone() const { return new Order(*this); }

	// functions
	bool addItem(const Product& product);
	int getTotalCalories() const;
	double getOrderTotal() const;
	friend ostream& operator<<(ostream& os, const Order& order);
};

#endif
