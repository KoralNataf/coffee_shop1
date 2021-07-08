#include "Date.h"

Date::Date(int day, int month, int year)
{
	if (!isValid(day, month, year))
		throw exception("Ilegal date!\n");
	this->day = day;
	this->month = month;
	this->year = year;
}

Date::Date(const Date& other)
{
	*this = other;
}

const Date& Date::operator=(const Date& other)
{
	if (this != &other)
	{
		this->day = other.day;
		this->month = other.month;
		this->year = other.year;
	}
	return *this;
}


bool Date:: operator==(const Date& other)const
{
	if (this->year == other.year && this->month == other.month && this->day == other.day)
		return true;
	return false;
}

int Date::getMonthDays(int month, int year)
{
	switch (month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		return 31;
	case 4:
	case 6:
	case 9:
	case 11:
		return 30;
	case 2:
		return isLeapYear(year) ? 29 : 28;
	default:
		return -1;
	}
}

//	return true if the year is a leap year, otherwise return false
bool Date::isLeapYear(int year)
{
	if (year % 4 == 0)
	{
		if (year % 100 == 0)
		{
			if (year % 400 == 0)
				return true;
			return false;
		}
		return true;
	}
	return false;
}

// return true if the date is a real valid date
bool Date::isValid(int day, int month, int year)
{
	if (day <= 0 || getMonthDays(month, year) < day)	//	also validate that month is between 1 to 12
		return false;

	if (year < 1900)
		return false;

	return true;
}


ostream& operator<<(ostream& os, const Date& date)
{
	os << date.day << "/" << date.month << "/" << date.year;
	return os;
}