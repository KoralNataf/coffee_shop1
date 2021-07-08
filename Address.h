#ifndef __ADDRESS_H__
#define __ADDRESS_H__

#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Address {
private:
	char* city;
	char* streetName;
	int streetNumber;
public:
	// ctor
	Address(const char* city, const char* streetName, int streetNumber)noexcept(false);
	// copy ctor
	Address(const Address& other);
	// move ctor
	Address(Address&& other)noexcept(false);
	// assignment operator
	const Address& operator=(const Address& other);
	// move assignment operator
	const Address& operator=(Address&& other)noexcept(false);
	// dtor
	~Address();

	// getters
	const char* getCity() const { return city; }
	const char* getStreetName() const { return streetName; }
	int getStreetNumber() const { return streetNumber; }
	
	//setters
	bool setStreetNum(int streetNum)noexcept(false);
	// functions
	friend ostream& operator<<(ostream& os, const Address& address);
};

#endif