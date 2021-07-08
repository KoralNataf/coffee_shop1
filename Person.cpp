#include "Person.h"

Person:: Person(const char* name, const char* phoneNumber)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);

	setPhoneNumber(phoneNumber);
}

Person::Person(const Person& other)
{
	*this = other;
}

const Person& Person::operator=(const Person& other)
{
	if (this != &other)
	{
		this->name = new char[strlen(other.name) + 1];
		strcpy(this->name, other.name);
		this->phoneNumber = new char[strlen(other.phoneNumber) + 1];
		strcpy(this->phoneNumber, other.phoneNumber);
	}
	return *this;
}

const Person& Person:: operator=(Person&& other)
{
	if (this != &other)
	{
		std::swap(name, other.name);
		std::swap(phoneNumber, other.phoneNumber);
	}
	return *this;
}

Person::~Person()
{
	delete[] name;
	delete[] phoneNumber;
}

bool Person::operator==(const Person& other) const
{
	if (strcmp(name, other.name) == 0 && strcmp(phoneNumber, other.phoneNumber) == 0)
		return true;
	return false;
}

bool Person::setPhoneNumber(const char* phoneNumber)
{
	if (strlen(phoneNumber) != PHONE_SIZE)
		throw exception("Ilegal input: phone must be 10 digits!\n");
	for (int i = 0; i < PHONE_SIZE; i++)
		if (phoneNumber[i] < '0' || phoneNumber[i]>'9')
			throw exception("Ilegal input: phone must be only digits!\n");
	this->phoneNumber = new char[PHONE_SIZE+1];
	strcpy(this->phoneNumber, phoneNumber);
	return true;
}

void Person::toOs(ostream& os) const
{
}

ostream& operator<<(ostream& os, const Person& person)
{
	os << "Name: " << person.name << ", Phone number: " << person.phoneNumber;
	person.toOs(os);
	os << endl;
	return os;
}
