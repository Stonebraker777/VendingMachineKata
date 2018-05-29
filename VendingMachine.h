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

class VendingMachine
{
private:
	unsigned int m_TotalMoneyInserted;

public:
	VendingMachine()
	{
		m_TotalMoneyInserted = 0;
	}
	bool AcceptCoin(Coins coin);
	string UserDisplay();
	void ReturnCoins();
};