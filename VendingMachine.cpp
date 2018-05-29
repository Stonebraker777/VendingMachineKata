#include "VendingMachine.h"

bool VendingMachine::AcceptCoin(Coins InsertedCoin)
{
	switch (InsertedCoin)
	{
	case Coins::NICKEL:
		m_TotalMoneyInserted += $NICKEL;
		break;
	case Coins::DIME:
		m_TotalMoneyInserted += $DIME;
		break;
	case Coins::QUARTER:
		m_TotalMoneyInserted += $QUARTER;
		break;
	default:
		return false;
		break;
	}
	m_VendingMachineState = VMState::STATE_ACCEPTING_COINS;
	return true;
}

string VendingMachine::UserDisplay()
{
	char str[32] = { 0 };
	string DisplayString;
	switch (m_VendingMachineState)
	{
	case VMState::STATE_ACCEPTING_COINS:
		sprintf_s(str, "$%4.2f", (float)m_TotalMoneyInserted / 100);
		DisplayString = str;
		break;
	case VMState::STATE_VENDING:
		DisplayString = "THANK YOU";
		m_VendingMachineState = VMState::STATE_INSERT_COIN;
		break;
	case VMState::STATE_INSUFFICIENT_MONEY:
		sprintf_s(str, "PRICE $%4.2f", (float)m_PriceOfSelectItem / 100);
		DisplayString = str;
		m_VendingMachineState = VMState::STATE_ACCEPTING_COINS;
		break;
	default:
		DisplayString = "INSERT COIN";
		break;
	}
	return DisplayString;
}

void VendingMachine::ReturnCoins()
{
	m_TotalMoneyInserted = 0;
	m_VendingMachineState = VMState::STATE_INSERT_COIN;
}

bool VendingMachine::SelectProduct(Products Item)
{
	bool ProductDispensedFlag = false;
	switch (Item)
	{
	case Products::PRODUCT_COLA:
		m_PriceOfSelectItem = m_PriceOfCola;
		if (m_TotalMoneyInserted >= m_PriceOfCola)
		{
			ProductDispensedFlag = true;
		}
		break;
	case Products::PRODUCT_CHIPS:
		m_PriceOfSelectItem = m_PriceOfChips;
		if (m_TotalMoneyInserted >= m_PriceOfChips)
		{
			ProductDispensedFlag = true;
		}
		break;
	case Products::PRODUCT_CANDY:
		m_PriceOfSelectItem = m_PriceOfCandy;
		if (m_TotalMoneyInserted >= m_PriceOfCandy)
		{
			ProductDispensedFlag = true;
		}
		break;
	default:
		break;
	}
	if (ProductDispensedFlag)
	{
		m_VendingMachineState = VMState::STATE_VENDING;
	}
	else
	{
		m_VendingMachineState = VMState::STATE_INSUFFICIENT_MONEY;
	}
	return ProductDispensedFlag;
}

ChangeType VendingMachine::MakeChange(unsigned int Change)
{
	ChangeType CoinChange;

	CoinChange.nQuarters = Change / $QUARTER;
	Change %= $QUARTER;

	CoinChange.nDimes = Change / $DIME;
	Change %= $DIME;

	CoinChange.nNickles = Change / $NICKEL;
	Change %= $NICKEL;

	return CoinChange;
}