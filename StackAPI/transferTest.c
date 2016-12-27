#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Transfer.h"

int main()
{
	char *str = "3+(5-2)*2";//352-2*+
	int i = transfer(str);
	if (i == 0)
	{
		printf("\nok\n");
	}
	else
	{
		printf("error code:%d", i);
	}
	system("pause");
	return 0;
}