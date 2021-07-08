#ifndef __COFFEE_H__
#define __COFFEE_H__

#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include "Product.h"

class Coffee : virtual public Product {
protected:
	bool withMilk;
	int sugarTeaspoons;
public:
	// ctor
	Coffee(const char* name, int calories, double cost, double price, bool withMilk = false, int sugarTeaspoons = 0);

	// operators
	const Coffee& operator+=(int sugarTeaspoons);

	// clone
	virtual Product* clone() const override { return new Coffee(*this); }

	// getters
	bool getWithMilk() const { return withMilk; }
	int getSugarTeaspoons() const { return sugarTeaspoons; }

	// functions
	bool addSugar(int sugarTeaspoons = 1);
	bool setMilk(bool isWithMilk);

	void toOs(ostream& os) const override;
//	friend ostream& operator<<(ostream& os, const Coffee& coffee);
};

#endif
