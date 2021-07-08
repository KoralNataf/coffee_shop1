#include "Cookie.h"

Cookie::Cookie(const char* name, int calories, double cost, double price, eFlourType flour)
	:Product(name,calories,cost,price), flour(flour)
{
}

void Cookie::toOs(ostream& os) const
{
	os << ", Flour Type: " <<sFlourType[(int)this->flour];
}