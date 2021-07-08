#include "Product.h"

Product::Product(const char* name, int calories, double cost, double price)
{
	setName(name);
	setCalories(calories);
	setCost(cost);
	setPrice(price);
}

Product::Product(const Product& other)
{
	*this = other;
}

Product::Product(Product&& other)
{
	*this =std::move(other);
}

const Product& Product:: operator=(const Product& other)
{
	if (this != &other)
	{
		setName(other.name);
		this->calories=other.calories;
		this->cost=other.cost;
		this->price=other.price;
	}
	return *this;
}

const Product& Product:: operator=(Product&& other)
{
	if (this != &other)
	{
		std::swap(this->name, other.name);
		delete other.name;
		this->calories = other.calories;
		this->cost = other.cost;
		this->price = other.price;
	}
	return *this;
}

Product::~Product()
{
	delete [] name;
}

bool Product::operator==(const Product& other) const
{
	if (strcmp(this->name, other.name) == 0 && calories == other.calories && cost == other.cost && price == other.price)
		return true;
	return false;
}

bool Product::setName(const char* name)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	return true;
	
}

bool Product::setCalories(int calories)
{
	if (calories <= 0)
		throw exception("Ilegal input: calories must be positive number!\n");
	this->calories = calories;
	return true;
}

bool Product::setCost(double cost)
{
	if (cost <= 0)
		throw exception("Ilegal input: cost must be positive number!\n");
	this->cost = cost;
	return true;
}

bool Product::setPrice(double price)
{
	if (price <= 0)
		throw exception("Ilegal input: price must be positive number!\n");
	this->price = price;
	return true;
}

ostream& operator<<(ostream& os, const Product& product)
{
	os << "Name: " << product.name << " , Calories: " << product.calories << " , Cost: " << product.cost << " , Price: " << product.price;
	product.toOs(os);
	os << endl;
	return os;
}