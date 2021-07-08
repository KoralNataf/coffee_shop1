#include "Customer.h"

Customer::Customer(const char* name, const char* phoneNumber, bool clubMember):Person(name,phoneNumber),clubMember(clubMember)
{
}

Customer::Customer(const Customer& other):Person(other)
{
	*this = other;
}

const Customer& Customer:: operator=(const Customer& other)
{
	if (this != &other)
	{
		Person::operator=(other);
		this->clubMember=other.clubMember;
	}
	return *this;
}

const Customer& Customer:: operator=(Customer&& other)
{
	if (this != &other)
	{
		Person::operator=(other);
		setClubMember(other.clubMember);
	}
	return *this;
}

bool Customer::setClubMember(bool clubMember) {
	this->clubMember = clubMember;
	return true;
}

void Customer::toOs(ostream& os) const
{
	os << clubMember ? ", is a club member." : ", not a club member.";
}

