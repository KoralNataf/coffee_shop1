#ifndef __SHIFT_H__
#define __SHIFT_H__

#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

#include "Date.h"
class Order;
class Employee;
class Product;
const int SIZE = 5;

class Shift {
private:

	double clubDiscountPercent;
	Date shiftDate;

	int numEmployees, employeesMaxSize;
	Employee** employees;

	int dailyMenuSize, dailyMenuMaxSize;
	Product** dailyMenu;

	int numOrders, ordersMaxSize;
	Order** orders;
	
public:
	// ctor
	Shift(double clubDiscountPercent, const Date& shiftDate); 
	// copy ctor
	Shift(const Shift& other) = delete;
	// assignment operator
	const Shift& operator=(const Shift& other) = delete;
	// move assignment operator
	const Shift& operator=(Shift&& other) = delete;
	// dtor
	~Shift();

	// getters
	int getNumEmployees() const { return numEmployees; }
	int getDailyMenuSize() const { return dailyMenuSize; }
	int getNumOrders() const { return numOrders; }
	double getClubDiscountPercent() const { return clubDiscountPercent; }
	const Date* getShiftDate() const { return &shiftDate; }
	const Employee* const* getEmployees() const { return employees; }
	const Product* const* getDailyMenu() const { return dailyMenu; }
	const Order* const* getOrders() const { return orders; }

	// setters
	bool setClubDiscountPercent(double clubDiscountPercent)noexcept(false);

	// functions
	bool addProductToMenu(const Product& product);
	bool addEmployeeToShift(const Employee& employee);
	bool addOrder(const Order& order);
	bool checkIfExsistEmployee(const Employee& employee) const;
	bool checkIfExsistProduct(const Product& product) const;
	const Employee* getShiftManger() const;
	double getShiftProfit() const;
	friend ostream& operator<<(ostream& os, const Shift& shift);
};

#endif