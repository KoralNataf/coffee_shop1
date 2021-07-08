#ifndef __CUSTOMER_H__
#define __CUSTOMER_H__

#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

#include "Person.h"

class Customer : public Person {
private:
	bool clubMember;

	Customer(const Customer& other);

	const Customer& operator=(const Customer& other);
	const Customer& operator=(Customer&& other)noexcept(false);

public:
	friend class CoffeeShop;
	// ctor
	Customer(const char* name, const char* phoneNumber, bool clubMember = false);
	
	// getters
	bool isClubMember() const { return clubMember; }

	// setters
	bool setClubMember(bool clubMember);

	// functions
	virtual void toOs(ostream& os) const override;
};

#endif