#include "Coffee.h"

Coffee::Coffee(const char* name, int calories, double cost, double price, bool withMilk, int sugarSpoons)
	:Product(name,calories,cost,price), withMilk(withMilk), sugarTeaspoons(sugarSpoons)
{
}

const Coffee& Coffee::operator+=(int sugarTeaspoons)
{
	this->addSugar(sugarTeaspoons);
	return *this;
}

bool Coffee::addSugar(int sugarTeaspoons)
{
	this->sugarTeaspoons += sugarTeaspoons;
	return true;
}

bool Coffee::setMilk(bool isWithMilk)
{
	this->withMilk = isWithMilk;
	return true;
}

void Coffee::toOs(ostream& os) const
{
	os << withMilk ? ", with milk " : ", without milk ";
	os<< ",number of sugar teaspoons: " << sugarTeaspoons;
}