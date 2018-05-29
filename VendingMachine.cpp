#include "VendingMachine.h"

bool VendingMachine::AcceptCoin(Coins InsertedCoin)
{
	switch (InsertedCoin)
	{
	case Coins::NICKEL:
		break;
	case Coins::DIME:
		break;
	case Coins::QUARTER:
		break;
	default:
		return false;
		break;
	}
	return true;
}
