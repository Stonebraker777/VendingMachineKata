#include "targetver.h"
#include <stdio.h>
#include <tchar.h>
#include <string>

using namespace std;

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
	string UserDisplay();
};