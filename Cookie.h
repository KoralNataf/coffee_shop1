#ifndef __COOKIE_H__
#define __COOKIE_H__

#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

#include "Product.h"

class Cookie: virtual public Product{
public:
	enum class eFlourType { WHITE, WHOLE, GLUTEN_FREE, enumTypeEnd };
protected:
	
	eFlourType flour;

public:
	// ctor
	Cookie(const char* name, int calories, double cost, double price, eFlourType flour = eFlourType::WHITE);

	// clone
	virtual Product* clone() const override { return new Cookie(*this); }

	// getters
	eFlourType getFlourType() const { return flour; }

	// functions
	void toOs(ostream& os) const override;
//	friend ostream& operator<<(ostream& os, const Cookie& cookie);
};

static const char* sFlourType[] = { "White", "Whole", "Gluten Free" };

#endif