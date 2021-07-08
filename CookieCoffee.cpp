#include "CookieCoffee.h"

CookieCoffee::CookieCoffee(const Cookie& cookie, const Coffee& coffee, double discountPercent, bool groundCookie)
	:Product("CookieCoffee",cookie.getCalories()+coffee.getCalories(),
		cookie.getCost()+coffee.getCost(),cookie.getPrice()+coffee.getPrice()),
	Cookie(cookie), Coffee(coffee)
{
	this->groundCookie = groundCookie;
	setDiscountPercent(discountPercent);
}

bool CookieCoffee::setDiscountPercent(double discountPercent)
{
	if (discountPercent < 0 || discountPercent>1)
		throw exception("Ilegal input: discount must be between 0-1!\n");
	this->discountPercent = discountPercent;
	return true;
}

void CookieCoffee::toOs(ostream& os) const
{
	os << groundCookie ? ",with ground cookie " : ", without ground cookie";
}