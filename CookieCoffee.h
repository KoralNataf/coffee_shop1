#ifndef __COOKIECOFFEE_H__
#define __COOKIECOFFEE_H__

#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include "Coffee.h"
#include "Cookie.h"


class CookieCoffee: public Cookie, public Coffee{
private:
	bool groundCookie;
	double discountPercent;

public:
	// ctor
	CookieCoffee(const Cookie& cookie, const Coffee& coffee, double discountPercent = 0, bool groundCookie = false);
	
	// clone
	virtual Product* clone() const override { return new CookieCoffee(*this); }

	// getters
	bool isGroundCookie() const { return groundCookie; }
	double getDiscountPercent() const { return discountPercent; }

	// setters
	bool setDiscountPercent(double discountPercent)noexcept(false);

	// functions
	virtual void toOs(ostream& os) const override;
//	friend ostream& operator<<(ostream& os, const CookieCoffee& cookieCoffee);
};

#endif
