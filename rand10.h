#include"head.h"

int rand10()
{
	do
	{
		int row = rand7();
		int col = rand7();
		int idx = col + (row - 1) * 7;
	}
	while (idx > 40);
	return 1 + idx % 10;
}
