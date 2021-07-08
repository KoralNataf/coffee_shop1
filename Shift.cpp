#include "Shift.h"
#include "Product.h"
#include "Employee.h"
#include "Order.h"
Shift:: Shift(double clubDiscountPercent, const Date& shiftDate):shiftDate(shiftDate)
{
	numEmployees = 0;
	employeesMaxSize = SIZE;
	employees = new Employee * [employeesMaxSize];
	dailyMenuSize = 0;
	dailyMenuMaxSize = SIZE;
	dailyMenu = new Product * [dailyMenuMaxSize];
	numOrders = 0;
	ordersMaxSize = SIZE;
	orders = new Order * [ordersMaxSize];
	setClubDiscountPercent(clubDiscountPercent);
}

Shift::~Shift()
{
	for (int i = 0; i < numEmployees; i++)
		delete employees[i];
	delete[] employees;

	for (int i = 0; i < dailyMenuSize; i++)
		delete dailyMenu[i];
	delete[] dailyMenu;

	for (int i = 0; i < numOrders; i++)
		delete orders[i];
	delete[] orders;
}

bool Shift::setClubDiscountPercent(double clubDiscountPercent)
{
	if (clubDiscountPercent < 0 || clubDiscountPercent>1)
		throw exception("Ilegal input: discount must be between 0-1!\n");
	this->clubDiscountPercent = clubDiscountPercent;
	return true;
}

bool Shift::addProductToMenu(const Product& product)
{
	if (checkIfExsistProduct(product))
		return false;
	
	if (dailyMenuSize == dailyMenuMaxSize)
	{
		dailyMenuMaxSize *= 2;
		Product** temp = new Product * [dailyMenuMaxSize];
		if (!temp)
			return false;
		
		for (int i = 0; i < dailyMenuSize; i++)
		{
			temp[i] = dailyMenu[i];
			dailyMenu[i] = nullptr;
		}
		delete[] dailyMenu;
		dailyMenu = temp;
	}

	dailyMenu[dailyMenuSize++] = product.clone();
	
	return true;
}

bool Shift::addEmployeeToShift(const Employee& employee)
{
	if (checkIfExsistEmployee(employee))
		return false;

	if (numEmployees == employeesMaxSize)
	{
		employeesMaxSize *= 2;
		 Employee** temp = new Employee * [employeesMaxSize];
		if (!temp)
			return false;

		for (int i = 0; i < numEmployees; i++)
		{
			temp[i] = employees[i];
			employees[i] = nullptr;
		}
		delete[] employees;
		employees = temp;
	}

	employees[numEmployees++] =employee.clone();

	return true;
}

bool Shift::addOrder(const Order& order)
{
	if (numOrders == ordersMaxSize)
	{
		ordersMaxSize *= 2;
		Order** temp = new Order * [ordersMaxSize];
		if (!temp)
			return false;

		for (int i = 0; i < numOrders; i++)
		{
			temp[i] = orders[i];
			orders[i] = nullptr;
		}
		delete[] orders;
		orders = temp;
	}

	orders[numOrders++] = order.clone();
	return true;
}

bool Shift::checkIfExsistEmployee(const Employee& employee) const
{
	for (int i = 0; i < numEmployees; i++)
		if (employee == *employees[i])
			return true;
	return false;
}

bool Shift::checkIfExsistProduct(const Product& product) const
{
	for (int i = 0; i < dailyMenuSize; i++)
		if (product == *dailyMenu[i])
			return true;
	return false;
}

const Employee* Shift::getShiftManger() const
{
	if (numEmployees == 0)
		return nullptr;
	Employee* senior = employees[0];
	for (int i = 0; i < numEmployees; i++)
		if (employees[i]->getSeniority() > senior->getSeniority())
			senior = employees[i];
	return senior;
}

double Shift::getShiftProfit() const
{
	double sum = 0;
	for (int i = 0; i < numOrders; i++)
		sum += orders[i]->getOrderTotal();
	return sum;
}

ostream& operator<<(ostream& os, const Shift& shift)
{
	os << "***SHIFT " << shift.shiftDate << "***\n\tEMPLOYTEES IN SHIFT:\n";
	if (shift.numEmployees != 0)
	{
		for (int i = 0; i < shift.numEmployees; i++)
			os << "\t" << *shift.employees[i];
		os << "\tManager: " << *shift.getShiftManger();
	}
	else
		cout << "\tEmployees List Is Empty!\n";

	os << "\tDAILY MENU:\n";
	if(shift.dailyMenuSize!=0)
		for (int i = 0; i < shift.dailyMenuSize; i++)
			os << "\t" << *shift.dailyMenu[i];
	else
		cout << "\tProducts List Is Empty!\n";
	
	os << "\tSHIFT OEDERS:\n";
	if(shift.numOrders!=0)
		for (int i = 0; i < shift.numOrders; i++)
		{
			os << "\tORDER NUMBER "<<i+1<<" DETAILS:\n" << *shift.orders[i];
		}
			
	else
		cout << "\nOrders List Is Empty!\n";

	return os;
}