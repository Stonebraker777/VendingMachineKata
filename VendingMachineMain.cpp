#include <assert.h>
#include "VendingMachine.h"

class VendingMachineTests
{
	VendingMachine VM;
public:
	void WhenTotalInsertedIsZeroDisplays_INSERT_COIN()
	{
		assert("INSERT COIN" == VM.UserDisplay());
	}
	void AcceptsNickelsDimesQuartersButRejectsPennies()
	{
		assert(true == VM.AcceptCoin(Coins::QUARTER));
		assert(false == VM.AcceptCoin(Coins::PENNY));
	}
	void UpdateAndDisplayTheTotalWithEachInsertedCoin()
	{
		assert("$0.25" == VM.UserDisplay());
		VM.AcceptCoin(Coins::DIME);
		assert("$0.35" == VM.UserDisplay());
	}
	void WhenReturnIsPressedTotalIsZeroAndDisplys_INSERT_COIN()
	{
		VM.ReturnCoins();
		assert("INSERT COIN" == VM.UserDisplay());
	}
	void WhenChipsItemIsSelectedWithEnoughMoneyInsertedDispensesProductandDisplays_THANK_YOU()
	{
		VM.AcceptCoin(Coins::QUARTER);
		VM.AcceptCoin(Coins::QUARTER);
		assert(true == VM.SelectProduct(Products::PRODUCT_CHIPS));
		assert("THANK YOU" == VM.UserDisplay());
	}
	void AfterDispensingAnItemWithExactMoneySetTotalBackToZeroDisplayIs_INSERT_COIN()
	{
		assert("INSERT COIN" == VM.UserDisplay());
	}
	void WhenAnItemIsSelectedWithoutEnoughMoneyInsertedDisplayIs_PRICEXXXThenDisplaysCurrentAmount()
	{
		VM.ReturnCoins();
		VM.AcceptCoin(Coins::QUARTER);
		VM.AcceptCoin(Coins::QUARTER);
		VM.SelectProduct(Products::PRODUCT_CANDY);
		assert("PRICE $0.65" == VM.UserDisplay());
		assert("$0.50" == VM.UserDisplay());
	}
	void VerifyMakeChangeMthodReturns2Quarters1DimeAnd1NickelFor65CentsChange()
	{
		VM.CoinChange = VM.MakeChange(65);
		assert(2 == VM.CoinChange.nQuarters);
		assert(1 == VM.CoinChange.nDimes);
		assert(1 == VM.CoinChange.nNickles);
	}
	void MakeChangeWhenItemSelectedIsLessThanTheTotalInserted()
	{
		VM.ReturnCoins();
		VM.AcceptCoin(Coins::QUARTER);
		VM.AcceptCoin(Coins::QUARTER);
		VM.AcceptCoin(Coins::QUARTER);
		VM.SelectProduct(Products::PRODUCT_CANDY);
		assert(1 == VM.CoinChange.nDimes);
	}
	void WhenItemSelectedIsSoldOutDisplayIs_SOLD_OUT()
	{
		VM.SetItemInventory(10, 0, 10);
		VM.AcceptCoin(Coins::QUARTER);
		VM.AcceptCoin(Coins::QUARTER);
		VM.SelectProduct(Products::PRODUCT_CHIPS);
		assert("SOLD OUT" == VM.UserDisplay());
	}
	void DisplayIsCurrentAmountInsertedAfter_SOLD_OUT()
	{
		VM.ReturnCoins();
		VM.SetItemInventory(10, 0, 10);
		VM.AcceptCoin(Coins::QUARTER);
		VM.AcceptCoin(Coins::QUARTER);
		VM.SelectProduct(Products::PRODUCT_CHIPS);
		VM.UserDisplay();
		assert("$0.50" == VM.UserDisplay());
	}
	void WhenUnableToMakeChangeDisplayIs_EXACT_CHANGE_ONLY_InsteadOf_INSERT_COIN()
	{
		VM.SetExactChangeOnlyFlag(true);
		VM.ReturnCoins();
		assert("EXACT CHANGE ONLY" == VM.UserDisplay());
	}
	void WhenUnableToMakeChangeMachineWillKeepAnythingOverItemPrice()
	{
		VM.ReturnCoins();
		VM.SetItemInventory(10, 10, 10);
		VM.AcceptCoin(Coins::QUARTER);
		VM.AcceptCoin(Coins::QUARTER);
		VM.AcceptCoin(Coins::QUARTER);
		VM.SelectProduct(Products::PRODUCT_CANDY);
		assert(0 == VM.CoinChange.nDimes);
		assert(0 == VM.CoinChange.nNickles);
	}
	void WhenUnableToMakeChangeMachineWillDispenseIfEnoughMoneyInsertedAndDisplay_THANK_YOU_Then_EXACT_CHANGE_ONLY()
	{
		VM.ReturnCoins();
		VM.AcceptCoin(Coins::QUARTER);
		VM.AcceptCoin(Coins::QUARTER);
		VM.AcceptCoin(Coins::QUARTER);
		VM.SelectProduct(Products::PRODUCT_CANDY);
		assert("THANK YOU" == VM.UserDisplay());
		assert("EXACT CHANGE ONLY" == VM.UserDisplay());
	}

};

int _tmain(int argc, _TCHAR* argv[])
{
	VendingMachineTests Tests;
	Tests.WhenTotalInsertedIsZeroDisplays_INSERT_COIN();
	Tests.AcceptsNickelsDimesQuartersButRejectsPennies();
	Tests.UpdateAndDisplayTheTotalWithEachInsertedCoin();
	Tests.WhenReturnIsPressedTotalIsZeroAndDisplys_INSERT_COIN();
	Tests.WhenChipsItemIsSelectedWithEnoughMoneyInsertedDispensesProductandDisplays_THANK_YOU();
	Tests.AfterDispensingAnItemWithExactMoneySetTotalBackToZeroDisplayIs_INSERT_COIN();
	Tests.WhenAnItemIsSelectedWithoutEnoughMoneyInsertedDisplayIs_PRICEXXXThenDisplaysCurrentAmount();
	Tests.VerifyMakeChangeMthodReturns2Quarters1DimeAnd1NickelFor65CentsChange();
	Tests.MakeChangeWhenItemSelectedIsLessThanTheTotalInserted();
	Tests.WhenItemSelectedIsSoldOutDisplayIs_SOLD_OUT();
	Tests.DisplayIsCurrentAmountInsertedAfter_SOLD_OUT();
	Tests.WhenUnableToMakeChangeDisplayIs_EXACT_CHANGE_ONLY_InsteadOf_INSERT_COIN();
	Tests.WhenUnableToMakeChangeMachineWillKeepAnythingOverItemPrice();
	Tests.WhenUnableToMakeChangeMachineWillDispenseIfEnoughMoneyInsertedAndDisplay_THANK_YOU_Then_EXACT_CHANGE_ONLY();
	return 0;
}

