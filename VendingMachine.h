#include "targetver.h"
#include <stdio.h>
#include <tchar.h>

enum Coins
{
	PENNY = 1,
	NICKEL,
	DIME,
	QUARTER
};

class VendingMachine
{
public:
	bool AcceptCoin(Coins coin);
};