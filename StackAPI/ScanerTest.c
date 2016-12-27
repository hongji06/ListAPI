#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Scaner.h"

int main_ScanerTest()
{
	char *str = "int main() { int i; i=i+1; return 0;}";
	int i = scaner(str);
	if (i == 0)
	{
		printf("ok\n");
	}
	else
	{
		printf("error code:%d", i);
	}
	system("pause");
	return 0;
}