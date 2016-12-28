#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Transfer.h"
#include "Scaner.h"
#include "comput.h"

int main_transferTest()//
{
	char str[100];// "3+(5-2)*2-2/3";

	printf("please input transfer:\n");
	scanf("%s", str);

	//浪块才腹琌で皌
	int i = scaner(str);
	if (i == 0)
	{
		printf("scaner ok\n");
	}
	else
	{
		printf("scaner error code:%d", i);
	}

	//い后锣传后
	LinkList *list = transfer(str);

	if (list != NULL)
	{
		printf("\ntransfer ok\n");
	}
	else
	{
		printf("\ntransfer error code:%d", i);
	}
	printf("list value:\n");
	for (int i = 0; i < LinkList_Length(list); i++)
	{
		ValueNode valueNode = (ValueNode)LinkList_Get(list, i);
		printf("%c", (char)valueNode->item);
	}
	printf("\n");

	//璸衡后笷Αず甧
	int ret = comput(list);
	printf("result:%d\n", ret);

	LinkList_Destroy(list);

	system("pause");

	return 0;
}