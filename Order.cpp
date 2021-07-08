#include "Order.h"
#include "Product.h"
#include "Employee.h"
#include "Customer.h"


Order::Order(const Order& other): employee(other.employee), customer(other.customer),
		numItems(other.numItems),itemsMaxSize(other.itemsMaxSize)
{
	items = new Product*[itemsMaxSize];
	for (int i = 0; i < numItems; i++)
		items[i] = other.items[i]->clone();
}

Order::Order(const Employee& employee, const Customer& customer) :employee(employee), customer(customer)
{
	numItems = 0;
	itemsMaxSize = I_SIZE;
	items = new Product * [itemsMaxSize];
}

Order::~Order()
{
	for (int i = 0; i < numItems; i++)
		delete items[i];
	delete[] items;
}

Product* Order::operator[](int index)
{
	if (index < 0 || index >= itemsMaxSize)
		throw exception("ilegal input: operator[]- index out of bounds\n");
	return items[index];
}

const Product* Order::operator[](int index) const
{
	if (index < 0 || index >= itemsMaxSize)
		throw exception("ilegal input: operator[]- index out of bounds\n");
	return items[index];
}

Order Order:: operator+(const Order& order)
{
	for (int i = 0; i < order.numItems; i++)
		if (!addItem(*order.items[i]))
		{
			cout << "failed adding product!" << endl;
			return order;
		}
			
	return *this;
}

bool Order::addItem(const Product& product)
{
	if (numItems + 1 > itemsMaxSize)
	{
		itemsMaxSize = numItems*2;
		Product** newItems = new Product * [itemsMaxSize];
		if (!newItems)
			return false;

		for (int i = 0; i < this->numItems; i++)
		{
			newItems[i] = this->items[i];
			this->items[i] = nullptr;
		}
		delete[] items;
		items = newItems;
	}
		items[numItems++] = product.clone();
		return true;
}

int Order:: getTotalCalories() const
{
	int sum = 0;
	for (int i = 0; i < numItems; i++)
		sum += items[i]->getCalories();
	return sum;
}

double Order::getOrderTotal() const
{
	double sum = 0;
	for (int i = 0; i < numItems; i++)
		sum += items[i]->getPrice();
	return sum;
}

ostream& operator<<(ostream& os, const Order& order)
{
	os<<"\tNumber Of Products: " <<order.numItems << "\n\tProducts In Order:\n";
	if (order.numItems != 0)
	{
		for (int i = 0; i < order.numItems; i++)
			os << "\t" << *order[i];
		os << "\tTotal price : " << order.getOrderTotal()<<endl;
	}
	else
		os << "Product list is empty!\n";
	os <<"\tCustomer In Order:\n"<<"\t"<<order.customer;
	os << "\tEmployee In Order:\n"<<"\t" << order.employee;
	os << endl;
	return os;
}