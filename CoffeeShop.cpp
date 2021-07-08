#include "CoffeeShop.h"
#include "functions.h"
#include "Customer.h"
#include "Employee.h"
#include "Shift.h"
#include "Product.h"
#include "Date.h"
#include <ctime>

CoffeeShop::CoffeeShop(const char* name, const Address& address):address(address)
{
	setName(name);

	numCustomers = 0;
	customersMaxSize = NUMBER;
	customers = new Customer * [customersMaxSize];

	numEmployees = 0;
	employeesMaxSize = NUMBER;
	employees = new Employee * [employeesMaxSize];

	numShifts = 0;
	shiftsMaxSize = NUMBER;
	shifts = new Shift * [shiftsMaxSize];

	numProducts = 0;
	productsMaxSize = NUMBER;
	products = new Product * [productsMaxSize];
}

CoffeeShop::CoffeeShop(CoffeeShop&& other):address(other.address)
{
	std::swap(this->name, other.name);
	delete[] other.name;

	this->numCustomers = other.numCustomers;
	this->customersMaxSize = other.customersMaxSize;
	this->customers = other.customers;
	other.customers = nullptr;
	delete[] other.customers;

	this->numEmployees = other.numEmployees;
	this->employeesMaxSize = other.employeesMaxSize;
	this->employees = other.employees;
	other.employees = nullptr;
	delete[] other.employees;

	this->numShifts = other.numShifts;
	this->shiftsMaxSize = other.shiftsMaxSize;
	this->shifts = other.shifts;
	other.shifts = nullptr;
	delete[] other.shifts;

	this->numProducts = other.numProducts;
	this->productsMaxSize = other.productsMaxSize;
	this->products = other.products;
	other.products = nullptr;
	delete[] other.products;
}

CoffeeShop::CoffeeShop(const char* name, Address&& address):address(address)
{
	setName(name);

	numCustomers = 0;
	customersMaxSize = NUMBER;
	customers = new Customer * [customersMaxSize];

	numEmployees = 0;
	employeesMaxSize = NUMBER;
	employees = new Employee * [employeesMaxSize];

	numShifts = 0;
	shiftsMaxSize = NUMBER;
	shifts = new Shift * [shiftsMaxSize];

	numProducts = 0;
	productsMaxSize = NUMBER;
	products = new Product * [productsMaxSize];
}

CoffeeShop::~CoffeeShop()
{
	delete[] name;
	for (int i = 0; i < numCustomers; i++)
		delete customers[i];
	delete[] customers;

	for (int i = 0; i < numEmployees; i++)
		delete employees[i];
	delete[] employees;

	for (int i = 0; i < numShifts; i++)
		delete shifts[i];
	delete[] shifts;

	for (int i = 0; i < numProducts; i++)
		delete products[i];
	delete[] products;
}

bool CoffeeShop::setName(const char* name)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	return true;
}

bool CoffeeShop::setAddress(const Address& address)
{
	if (address.getStreetNumber() < 0)
		throw exception("Ilegal input: street number must be positive!\n");
	this->address = address;
	return  true;
}

bool CoffeeShop::addNewEmployee(const Employee& employee)
{
	if (checkIfExsistEmployee(employee))
	{
		cout << "Employee already exsist!\n";
		return false;
	}

	if (numEmployees == employeesMaxSize)
	{
		employeesMaxSize *= 2;
		 Employee** temp = new  Employee * [employeesMaxSize];
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

	employees[numEmployees++] = employee.clone();
	return true;
}

bool CoffeeShop::addNewEmployee(Employee&& employee)
{
	if (checkIfExsistEmployee(employee))
	{
		cout << "Employee already exsist!\n";
		return false;
	}

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
	employees[numEmployees++] = new Employee(std::move(employee));
	return true;
}

bool CoffeeShop::addNewProduct(const Product& product)
{
	if (checkIfExsistProduct(product))
	{
		cout << "Product already exsist!\n";
		return false;
	}

	if (numProducts == productsMaxSize)
	{
		productsMaxSize *= 2;
		Product** temp = new Product * [productsMaxSize];
		if (!temp)
			return false;

		for (int i = 0; i < numProducts; i++)
		{
			temp[i] = products[i];
			products[i] = nullptr;
		}
		delete[] products;
		products = temp;
	}

	products[numProducts++] = product.clone();
	
	return true;
}

bool CoffeeShop::addNewCustomer(const Customer& customer)
{
	if (checkIfExsistCustomer(customer))
	{
		cout << "Customer already exsist!\n";
		return false;
	}

	if (numCustomers == customersMaxSize)
	{
		customersMaxSize *= 2;
		Customer** temp = new Customer * [customersMaxSize];
		if (!temp)
			return false;

		for (int i = 0; i < numCustomers; i++)
		{
			temp[i] = customers[i];
			customers[i] = nullptr;
		}
		delete[] customers;
		customers = temp;
	}

	customers[numCustomers++] = new Customer(customer);
	return true;
}

bool CoffeeShop::addNewCustomer(Customer&& customer)
{
	if (checkIfExsistCustomer(customer))
	{
		cout << "Customer already exsist!\n";
		return false;
	}

	if (numCustomers == customersMaxSize)
	{
		customersMaxSize *= 2;
		Customer** temp = new Customer * [customersMaxSize];
		if (!temp)
			return false;

		for (int i = 0; i < numCustomers; i++)
		{
			temp[i] = customers[i];
			customers[i] = nullptr;
		}
		delete[] customers;
		customers = temp;
	}

	customers[numCustomers++] = new Customer(std::move(customer));
	return true;
}

bool CoffeeShop::openShift(double clubDiscountPercent, const Date& date)
{
	if (numShifts + 1 > shiftsMaxSize)
	{
		shiftsMaxSize *= 2;
		Shift** temp = new Shift * [shiftsMaxSize];
		if (!temp)
			return false;

		for (int i = 0; i < numShifts; i++)
		{
			temp[i] = shifts[i];
			shifts[i] = nullptr;
		}
		delete[] shifts;
		shifts = temp;
	}

	shifts[numShifts++] = new Shift(clubDiscountPercent, date);
	return true;

}

Shift* CoffeeShop::getCurrentShift() 
{
	time_t now = time(0);
	tm* dateStruct = localtime(&now);
	Date today(dateStruct->tm_mday, dateStruct->tm_mon + 1, dateStruct->tm_year + 1900);
	
	for (int i = 0; i < numShifts; i++)
		if (today == *shifts[i]->getShiftDate())
			return shifts[i];

	cout << "Shist Not Exsist!\nOpen New Shift:\n";

	double discount;
	cout << "Enter club discount: ";
	while (!(cin >> discount) || discount < 0 || discount>100)
	{
		cleanBuffer();
		cout << "ilegal input discount, try again: ";
	}
	discount = discount / 100;

	if (openShift(discount, today))
		return shifts[numShifts - 1];

	return nullptr;
}

Shift* CoffeeShop::getShiftByChoice()
{
	int choice;
	cout << "Choose option:\n1.get current shift.\n2.get shift by date.\nyour option: ";
	while (!(cin >> choice) || (choice != 1 && choice != 2))
	{
		cleanBuffer();
		cout << "Ilegal input choice!\ntry again: ";
	}


	switch (choice)
	{
	case 1:
		return getCurrentShift();
	case 2:
		return getShiftByDate();
	default:
		return nullptr;
	}
}

Shift* CoffeeShop::getShiftByDate() 
{
	int day, month, year;
	cout << "Enter Date details: " << endl;
	cout << "day: ";
	if (!(cin >> day))
		cleanBuffer();

	cout << "month: ";
	if (!(cin >> month))
		cleanBuffer();

	cout << "year: ";
	if (!(cin >> year))
		cleanBuffer();

	Date date(day, month, year);
	for (int i = 0; i < numShifts; i++)
		if (date == *shifts[i]->getShiftDate())
			return shifts[i];

	cout << "Shist Not Exsist!\nOpen New Shift:\n";
	
	double discount;
	cout<<"Enter club discount: "; 
	while (!(cin >> discount) || discount < 0 || discount>100)
	{
		cleanBuffer();
		cout << "ilegal input discount, try again: ";
	}
	discount = discount / 100;

	if (openShift(discount, date))
		return shifts[numShifts - 1];

	return nullptr;
}

bool CoffeeShop::checkIfExsistEmployee(const Employee& employee) const
{
	for (int i = 0; i < numEmployees; i++)
		if (employee == *employees[i])
			return true;
	return false;
}

bool CoffeeShop::checkIfExsistProduct(const Product& product) const
{
	for (int i = 0; i < numProducts; i++)
		if (product == *products[i])
			return true;
	return false;
}

bool CoffeeShop::checkIfExsistCustomer(const Customer& customer) const
{
	for (int i = 0; i < numCustomers; i++)
		if (customer == *customers[i])
			return true;
	return false;
}

ostream& operator<<(ostream& os, const CoffeeShop& coffeeShop)
{
	os << "\n\n*****COFFEE SHOP*****\n" << "Name: " << coffeeShop.name << " , Address: " << coffeeShop.address
		<< "\nCUSTOMERS:\n";
	int i;
	for (i = 0; i < coffeeShop.numCustomers; i++)
		os << *coffeeShop.customers[i];
	if (i == 0)
		cout << "Customers list is empty!\n";

	os << "\nEMPLOYEES:\n";
	for (i = 0; i < coffeeShop.numEmployees; i++)
		os << *coffeeShop.employees[i];
	if (i == 0)
		cout << "Employees list is empty!\n";
	os << "\nSHIFTS:\n";
	for (i = 0; i < coffeeShop.numShifts; i++)
		os << *coffeeShop.shifts[i];
	if (i == 0)
		cout << "Shifts list is empty!\n";
	os << "\nPRODUCTS:\n";
	for (i = 0; i < coffeeShop.numProducts; i++)
		os << *coffeeShop.products[i];
	if (i == 0)
		cout << "Products list is empty!";

	return os;
}
