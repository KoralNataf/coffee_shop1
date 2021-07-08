#ifndef __EMPLOYEE_H__
#define __EMPLOYEE_H__

#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
using namespace std;

#include "Person.h"
#include "Date.h"


class Employee : public Person {
private:
	double shiftSalary;
	Date hireDate;

	Employee(const Employee& other);
	
	const Employee& operator=(const Employee& other);
	const Employee& operator=(Employee&& other)noexcept(false);

public:
	friend class CoffeeShop;
	// ctor
	Employee(const char* name, const char* phoneNumber, double shiftSalary, const Date& hireDate);
	
	// operators
	bool operator<(const Employee& other) const; 
	bool operator>(const Employee& other) const;
	virtual bool operator==(const Person& other) const override;

	// getters
	double getShiftSalary() const { return shiftSalary; }
	const Date* getHireDate() const { return &hireDate; }

	// setters
	bool setShiftSalary(double shiftSalary) noexcept(false);
	bool setHireDate(Date& hireDate)noexcept(false);

	//clone
	Employee* clone()const  { return new Employee(*this); }
	// functions
	int getSeniority() const;
	virtual void toOs(ostream& os) const override;
	//friend ostream& operator<<(ostream& os, const Person& other);
};

#endif