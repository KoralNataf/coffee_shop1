#ifndef __COFFEESHOP_H__
#define __COFFEESHOP_H__

#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include "Address.h"

const int NUMBER = 10;

class Customer;
class Employee;
class Shift;
class Product;
class Date;

class CoffeeShop {
private:
	char* name;
	Address address;

	int numCustomers, customersMaxSize;
	Customer** customers;

	int numEmployees, employeesMaxSize;
	Employee** employees;

	int numShifts, shiftsMaxSize;
	Shift** shifts;

	int numProducts, productsMaxSize;
	Product** products;
	
public:
	// ctor
	CoffeeShop(const char* name, const Address& address);
	// copy ctor
	CoffeeShop(const CoffeeShop& other) = delete;
	CoffeeShop(CoffeeShop&& other)noexcept(false);
	// move ctor
	CoffeeShop(const char* name, Address&& address);
	// assignment operator
	const CoffeeShop& operator=(const CoffeeShop& other) = delete;
	// move assignment operator
	const CoffeeShop& operator=(CoffeeShop&& other) = delete;
	// dtor
	~CoffeeShop();

	// getters
	const char* getName() const { return name; }
	int getNumCustomers() const { return numCustomers; }
	int getNumEmployees() const { return numEmployees; }
	int getNumShifts() const { return numShifts; }
	int getNumProducts() const { return numProducts; }
	const Address* getAddress() const { return &address; }
	const Customer* const* getCustomers() const { return customers; }
	const Employee* const* getEmployees() const { return employees; }
	const Shift* const* getShifts() const { return shifts; }
	const Product* const* getProducts() const { return products; }

	// setters
	bool setName(const char* name);
	bool setAddress(const Address& address)noexcept(false);
	
	// functions
	bool addNewEmployee(const Employee& employee);
	bool addNewEmployee(Employee&& employee);	
	bool addNewProduct(const Product& product);
	bool addNewCustomer(const Customer& customer);
	bool addNewCustomer(Customer&& customer);
	bool openShift(double clubDiscountPercent, const Date& date);
	Shift* getCurrentShift() ;
	Shift* getShiftByChoice() noexcept(false);
	Shift* getShiftByDate() noexcept(false);
	bool checkIfExsistEmployee(const Employee& employee) const;
	bool checkIfExsistProduct(const Product& product) const;
	bool checkIfExsistCustomer(const Customer& customer) const;
	
	friend ostream& operator<<(ostream& os, const CoffeeShop& coffeeShop);
};

#endif