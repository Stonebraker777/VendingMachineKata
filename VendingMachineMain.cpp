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
};

int _tmain(int argc, _TCHAR* argv[])
{
	VendingMachineTests Tests;
	Tests.WhenTotalInsertedIsZeroDisplays_INSERT_COIN();
	Tests.AcceptsNickelsDimesQuartersButRejectsPennies();
	Tests.UpdateAndDisplayTheTotalWithEachInsertedCoin();
	return 0;
}

