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
	return true;
}

string VendingMachine::UserDisplay()
{
	if (m_ProductDispensedFlag)
	{
		return "THANK YOU";
	}
	if (m_TotalMoneyInserted != 0)
	{
		char str[32] = { 0 };
		sprintf_s(str, "$%4.2f", (float)m_TotalMoneyInserted / 100);
		return (string)str;
	}
	return "INSERT COIN";
}

void VendingMachine::ReturnCoins()
{
	m_TotalMoneyInserted = 0;
}

bool VendingMachine::SelectProduct(Products Item)
{
	switch (Item)
	{
	case Products::PRODUCT_COLA:
		if (m_TotalMoneyInserted >= m_PriceOfCola)
		{
			m_ProductDispensedFlag = true;
		}
		break;
	case Products::PRODUCT_CHIPS:
		if (m_TotalMoneyInserted >= m_PriceOfChips)
		{
			m_ProductDispensedFlag = true;
		}
		break;
	case Products::PRODUCT_CANDY:
		if (m_TotalMoneyInserted >= m_PriceOfCandy)
		{
			m_ProductDispensedFlag = true;
		}
		break;
	default:
		m_ProductDispensedFlag = false;
		break;
	}
	return m_ProductDispensedFlag;
}