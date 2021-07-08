#include "Employee.h"

Employee::Employee(const char* name, const char* phoneNumber, double shiftSalary, const Date& hireDate)
	: Person(name,phoneNumber), shiftSalary(shiftSalary), hireDate(hireDate)
{
}

Employee::Employee(const Employee& other) : Person(other.name, other.phoneNumber), hireDate(other.hireDate)
{
	this->shiftSalary = other.shiftSalary;
}

const Employee& Employee:: operator=(const Employee& other)
{
	if (this != &other)
	{
		Person::operator=(other);
		this->shiftSalary = other.shiftSalary;
		this->hireDate = other.hireDate;
	}
	return *this;
}

const Employee& Employee::operator=(Employee&& other)
{
	if (this != &other)
	{
		Person::operator=(other);
		this->hireDate = other.hireDate;
		this->shiftSalary = other.shiftSalary;
	}
	return *this;
}

bool Employee::operator<(const Employee& other) const
{
	Date d = this->hireDate;
	Date d2 = other.hireDate;
	if (d.getYear() > d2.getYear())
		return true;
	else if (d.getYear() < d2.getYear())
		return false;
	else
		if (d.getMonth() > d2.getMonth())
			return true;
		else if (d.getMonth() < d2.getMonth())
			return false;
		else
			if (d.getDay() > d2.getDay())
				return true;
			else if (d.getDay() < d2.getDay())
				return false;
	return false;
}

bool Employee::operator>(const Employee& other) const
{
	Date d = this->hireDate;
	Date d2 = other.hireDate;
	if (!operator<(other) && !(d==d2))
		return true;
	return false;
}

bool Employee::operator==(const Person& other) const
{
	const Employee* temp = dynamic_cast<const Employee*>(&other);
	if (Person::operator==(other))
		if (shiftSalary == temp->shiftSalary)
			if (hireDate == temp->hireDate)
				return true;
	return false;
}

bool Employee::setShiftSalary(double shiftSalary)
{
	if (shiftSalary < 0)
		throw exception("Ilegal input: salary must be positive!\n");
	this->shiftSalary = shiftSalary;
	return true;
}

bool Employee::setHireDate(Date& hireDate)
{
	if (!hireDate.isValid(hireDate.getDay(), hireDate.getMonth(), hireDate.getYear()))
		throw exception("Ilegal date!\n");
	this->hireDate = hireDate;
	return true;
}

int Employee:: getSeniority() const
{
	time_t now = time(0);
	tm* ltm = localtime(&now);
	int curYear = 1900 + ltm->tm_year;
	int seniority = curYear - hireDate.getYear();
	if (seniority < 0)
		return 0;
	return seniority;
}

void Employee::toOs(ostream& os) const
{
	os << " ,shift salary: " << shiftSalary << " , hire date: " << hireDate;
}

