#include "Address.h"

Address::Address(const char* city, const char* streetName, int streetNumber) 
{
	this->city = new char[strlen(city) + 1];
	strcpy(this->city, city);

	this->streetName = new char[strlen(streetName) + 1];
	strcpy(this->streetName, streetName);

	setStreetNum(streetNumber);
}

Address::Address(const Address& other)
{
	*this = other;
}

Address:: Address(Address&& other)
{
	*this = std::move(other);
}

const Address& Address:: operator=(const Address& other) 
{
	if (this != &other)
	{
		this->streetNumber = other.streetNumber;
		delete[] city;
		delete[] streetName;
		city = strdup(other.city);
		streetName = strdup(other.streetName);
	}
	return *this;
}

const Address& Address::operator=(Address&& other)
{
	if (this != &other)
	{
		std::swap(city, other.city);
		std::swap(streetName, other.streetName);
		streetNumber = other.streetNumber;
	}
	return *this;
}

Address::~Address()
{
	delete[] city;
	delete[] streetName;
}

bool Address::setStreetNum(int streetNum)
{
	if (streetNum <= 0)							
		throw exception("Street Number must be positive number!\n");

	this->streetNumber = streetNum;
	return true;
}
ostream& operator<<(ostream& os, const Address& address)
{
	os << "City: " << address.city << ", Street: " 
		<< address.streetName << ", Number: " << address.streetNumber << endl;
	return os;
}