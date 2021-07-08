#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS
#include "functions.h"
#include "CoffeeShop.h"

int main()
{
	while (true)
	{
		try
		{
			CoffeeShop shop = initCoffeeShop();

			menu(shop);
			break;

		}
		catch (exception & e)
		{
			cleanBuffer();
			cout << e.what() << "try again: ";
			
		}
	}
	
	return 0;
}