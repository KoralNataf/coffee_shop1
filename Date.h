#ifndef __DATE_H__
#define __DATE_H__

#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Date {
private:
	int day, month, year;
public:
	// ctor
	Date(int day, int month, int year)noexcept(false);
	Date(const Date& other);

	//operators
	const Date& operator=(const Date& other);
	bool operator==(const Date& other) const;

	// getters
	int getDay() const { return day; }
	int getMonth() const { return month; }
	int getYear() const { return year; }

	// functions
	int getMonthDays(int month, int year);
	bool isLeapYear(int year);
	bool isValid(int day, int month, int year);
	friend ostream& operator<<(ostream& os, const Date& date);
};

#endif