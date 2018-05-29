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
		if (m_TotalMoneyInserted >= m_PriceOfCola)
		{
			ProductDispensedFlag = true;
		}
		break;
	case Products::PRODUCT_CHIPS:
		if (m_TotalMoneyInserted >= m_PriceOfChips)
		{
			ProductDispensedFlag = true;
		}
		break;
	case Products::PRODUCT_CANDY:
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
	return ProductDispensedFlag;
}