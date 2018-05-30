#include "VendingMachine.h"

void VendingMachine::SetItemInventory(unsigned int nCola, unsigned int nChips, unsigned int nCandy)
{
	m_NumberOfColaItems = nCola;
	m_NumberOfChipsItems = nChips;
	m_NumberOfCandyItems = nCandy;
}

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
	case VMState::STATE_SOLD_OUT:
		DisplayString = "SOLD OUT";
		m_VendingMachineState = VMState::STATE_ACCEPTING_COINS;
		break;
	case VMState::STATE_INSERT_COIN:
	default:
		if (m_ExactChangeOnlyFlag)
		{
			DisplayString = "EXACT CHANGE ONLY";
		}
		else
		{
			DisplayString = "INSERT COIN";
		}
		break;
	}
	return DisplayString;
}

void VendingMachine::ReturnCoins()
{
	m_TotalMoneyInserted = 0;
	CoinChange.nQuarters = 0;
	CoinChange.nDimes = 0;
	CoinChange.nNickles = 0;
	m_VendingMachineState = VMState::STATE_INSERT_COIN;
}

void VendingMachine::SetExactChangeOnlyFlag(bool flag)
{
	m_ExactChangeOnlyFlag = true;
}

bool VendingMachine::SelectProduct(Products Item)
{
	bool ProductDispensedFlag = false;
	switch (Item)
	{
	case Products::PRODUCT_COLA:
		if (m_NumberOfColaItems == 0)
		{
			m_VendingMachineState = VMState::STATE_SOLD_OUT;
			return false;
		}
		m_PriceOfSelectItem = m_PriceOfCola;
		if (m_TotalMoneyInserted >= m_PriceOfCola)
		{
			ProductDispensedFlag = true;
		}
		break;
	case Products::PRODUCT_CHIPS:
		if (m_NumberOfChipsItems == 0)
		{
			m_VendingMachineState = VMState::STATE_SOLD_OUT;
			return false;
		}
		m_PriceOfSelectItem = m_PriceOfChips;
		if (m_TotalMoneyInserted >= m_PriceOfChips)
		{
			ProductDispensedFlag = true;
		}
		break;
	case Products::PRODUCT_CANDY:
		if (m_NumberOfCandyItems == 0)
		{
			m_VendingMachineState = VMState::STATE_SOLD_OUT;
			return false;
		}
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
		CoinChange = MakeChange(m_TotalMoneyInserted - m_PriceOfSelectItem);
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
	if (m_ExactChangeOnlyFlag)
	{
		CoinChange.nQuarters = 0;
		CoinChange.nDimes = 0;
		CoinChange.nNickles = 0;
		m_TotalMoneyInserted = 0;
	}
	else
	{
		CoinChange.nQuarters = Change / $QUARTER;
		Change %= $QUARTER;

		CoinChange.nDimes = Change / $DIME;
		Change %= $DIME;

		CoinChange.nNickles = Change / $NICKEL;
		Change %= $NICKEL;
	}

	return CoinChange;
}