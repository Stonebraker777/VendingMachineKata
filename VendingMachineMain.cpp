#include <assert.h>
#include "VendingMachine.h"

class VendingMachineTests
{
	VendingMachine VM;
public:
	void AcceptsNickelsDimesQuartersButRejectsPennies()
	{
		assert(true == VM.AcceptCoin(Coins::QUARTER));
		assert(false == VM.AcceptCoin(Coins::PENNY));
	}
	void WhenTotalInsertedIsZeroDisplays_INSERT_COIN()
	{
		assert("INSERT COIN" == VM.UserDisplay());
	}

};

int _tmain(int argc, _TCHAR* argv[])
{
	VendingMachineTests Tests;
	Tests.AcceptsNickelsDimesQuartersButRejectsPennies();
	Tests.WhenTotalInsertedIsZeroDisplays_INSERT_COIN();
	return 0;
}

