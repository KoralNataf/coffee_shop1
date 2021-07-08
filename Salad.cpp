#include "Salad.h"

Salad::Salad(const char* name, int calories, double cost, double price, eDressingType dressing)
	:Product(name, calories, cost, price), dressing(dressing)
{
}

bool Salad::addDressing(eDressingType dressing)
{
	this->dressing = dressing;
	return true;
}

void Salad::toOs(ostream& os) const
{
	if(dressing != Salad::eDressingType::enumTypeEnd)
		os << ", Dressing Type: " <<sDressingType[(int)this->dressing];
}