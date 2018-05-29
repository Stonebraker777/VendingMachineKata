#include "targetver.h"
#include <stdio.h>
#include <tchar.h>
#include <string>
#include <iostream>

using namespace std;

#define $PENNY		1
#define $NICKEL		5
#define $DIME		10
#define $QUARTER	25

enum Coins
{
	PENNY = 1,
	NICKEL,
	DIME,
	QUARTER
};

enum Products
{
	PRODUCT_COLA = 1,
	PRODUCT_CHIPS,
	PRODUCT_CANDY
};

class VendingMachine
{
private:
	unsigned int m_TotalMoneyInserted;
	unsigned int m_PriceOfCola;
	unsigned int m_PriceOfChips;
	unsigned int m_PriceOfCandy;

	bool m_ProductDispensedFlag;

public:
	VendingMachine()
	{
		m_TotalMoneyInserted = 0;
		m_PriceOfCola = 100;
		m_PriceOfChips = 50;
		m_PriceOfCandy = 65;

		m_ProductDispensedFlag = false;
	}
	bool AcceptCoin(Coins coin);
	string UserDisplay();
	void ReturnCoins();
	bool SelectProduct(Products Item);
};