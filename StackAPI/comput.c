#include<stdio.h>
#include "comput.h"
#include "Transfer.h"
#include "LinkStack.h"

int comput(LinkList *list)
{
	int ret = 0;
	LinkStack *stack = LinkStack_Create();

	for (int i = 0; i < LinkList_Length(list); i++)
	{
		ValueNode valueNode = (ValueNode)LinkList_Get(list, i);
		char ch = (char)valueNode->item;

		if (isNumber(ch))
		{
			LinkStack_Push(stack, (void *)(int)(ch-48));
		}
		else if (isOperator(ch))
		{
			int operLeft = 0, operRight = 0, result = 0;
			operRight = (int)LinkStack_Pop(stack);
			operLeft = (int)LinkStack_Pop(stack);
			result = getResult(operLeft, ch, operRight);
			LinkStack_Push(stack, (void *)result);

		}
		else
		{
			printf("�Ÿ����~%c\n", ch);
		}

	}
	if (LinkStack_Size(stack) == 1) {
		ret = (int)LinkStack_Pop(stack);
	}
	else
	{
		printf("�̫�ާ@����٦�����@�ӭ�\n");
	}
	

	LinkStack_Destroy(stack);

	return ret;
}


int getResult(int operLeft, int oper, int operRight)
{
	int ret = 0;
	if ((char)oper == '+')
	{
		ret = operLeft + operRight;
	}
	else if ((char)oper == '-')
	{
		ret = operLeft - operRight;
	}
	else if ((char)oper == '*')
	{
		ret = operLeft * operRight;
	}
	else if ((char)oper == '/')
	{
		ret = operLeft / operRight;
	}
	else
	{
		printf("�X�{���i�ާ@���Ÿ�%c\n",oper);
	}
	return ret;
}