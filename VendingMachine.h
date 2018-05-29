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

typedef struct ChangeType
{
	unsigned int nNickles = 0;
	unsigned int nDimes = 0;
	unsigned int nQuarters = 0;
};

enum Products
{
	PRODUCT_COLA = 1,
	PRODUCT_CHIPS,
	PRODUCT_CANDY
};

enum VMState
{
	STATE_INSERT_COIN = 0,
	STATE_ACCEPTING_COINS,
	STATE_VENDING,
	STATE_INSUFFICIENT_MONEY,
	STATE_SOLD_OUT,
};

class VendingMachine
{
private:
	VMState m_VendingMachineState;

	unsigned int m_TotalMoneyInserted;
	unsigned int m_PriceOfCola;
	unsigned int m_PriceOfChips;
	unsigned int m_PriceOfCandy;
	unsigned int m_PriceOfSelectItem;

	unsigned int m_NumberOfColaItems;
	unsigned int m_NumberOfChipsItems;
	unsigned int m_NumberOfCandyItems;

public:
	ChangeType CoinChange;
	VendingMachine()
	{
		m_VendingMachineState = VMState::STATE_INSERT_COIN;
		m_TotalMoneyInserted = 0;
		m_PriceOfCola = 100;
		m_PriceOfChips = 50;
		m_PriceOfCandy = 65;

		m_NumberOfColaItems = 10;
		m_NumberOfChipsItems = 10;
		m_NumberOfCandyItems = 10;
	}
	void SetItemInventory(unsigned int nCola, unsigned int nChips, unsigned int nCandy);
	bool AcceptCoin(Coins coin);
	string UserDisplay();
	void ReturnCoins();
	bool SelectProduct(Products Item);
	ChangeType MakeChange(unsigned int Change);
};