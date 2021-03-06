#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkList.h"
#include "LinkStack.h"
#include "Transfer.h"



LinkList* transfer(char * str)
{
	LinkStack *stack =LinkStack_Create();
	LinkList *list = LinkList_Create();
	
	while (*str != '\0')
	{
		if (isNumber(*str))
		{
			ValueNode valueNode = malloc(sizeof(ValueNode));
			valueNode->item = (void *)(int)(*str);
			LinkList_Insert(list, (LinkListNode*)valueNode, LinkList_Length(list));
			output(*str);
		}
		else if (isOperator(*str))
		{
			while (isLevel(*str) <= isLevel((char)(int)LinkStack_Top(stack)))
			{
				ValueNode valueNode = malloc(sizeof(ValueNode));
				valueNode->item = (void *)(int)LinkStack_Top(stack);
				LinkList_Insert(list, (LinkListNode*)valueNode, LinkList_Length(list));
				output((char)(int)LinkStack_Pop(stack));
			}
			LinkStack_Push(stack, (void *)(int)(*str));
		}
		else if (isParLeft(*str))
		{
			LinkStack_Push(stack, (void *)(int)(*str));
		}
		else if (isParRight(*str))
		{
			while (!isParLeft((char)(int)LinkStack_Top(stack)))
			{
				ValueNode valueNode = malloc(sizeof(ValueNode));
				valueNode->item = (void *)(int)LinkStack_Top(stack);
				LinkList_Insert(list, (LinkListNode*)valueNode, LinkList_Length(list));
				output((char)(int)LinkStack_Pop(stack));
			}
			LinkStack_Pop(stack);
		}
		else
		{
			return NULL;
		}


		str++;
	}

	while (LinkStack_Top(stack))
	{
		ValueNode valueNode = malloc(sizeof(ValueNode));
		valueNode->item = (void *)(int)LinkStack_Top(stack);
		LinkList_Insert(list, (LinkListNode*)valueNode, LinkList_Length(list));
		output((char)(int)LinkStack_Pop(stack));
	}
	

	LinkStack_Destroy(stack);
	return list;
}
int isNumber(char ch)
{
	if (ch <= '9'&&ch >= '0')
	{
		return 1;
	}
	return 0;
}
int isOperator(char ch)
{
	if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
	{
		return 1;
	}
	return 0;
}
int isLevel(char ch)
{
	if (ch == '+' || ch == '-')
	{
		return 1;
	}
	else if (ch == '*' || ch == '/')
	{
		return 2;
	}
	else
	{
		return 0;
	}	
}
int output(char ch)
{
	printf("%c", ch);
	return 0;
}
int isParLeft(char ch)
{
	if (ch == '(')
	{
		return 1;
	}
	return 0;
}
int isParRight(char ch)
{
	if (ch == ')')
	{
		return 1;
	}
	return 0;
}
