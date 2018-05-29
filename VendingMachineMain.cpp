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
};

int _tmain(int argc, _TCHAR* argv[])
{
	VendingMachineTests Tests;
	Tests.AcceptsNickelsDimesQuartersButRejectsPennies();
	return 0;
}

