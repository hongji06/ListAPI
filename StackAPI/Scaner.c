#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkStack.h"
#include "Scaner.h"

int scaner(char * str)
{
	//create stack
	LinkStack *stack = LinkStack_Create();

	while (*str != '\0') {
		if (isLeft(*str))
		{
			LinkStack_Push(stack, str);
		}
		else if (isRight(*str))
		{
			char tmpRight = *str, tmpLeft = 0;
			tmpLeft = *(char *)LinkStack_Pop(stack);
			if (!isMatch(tmpRight, tmpLeft))
			{
				return -1;
			}
		}
		str++;
	}

	if (LinkStack_Size(stack) != 0)
	{
		return -2;
	}

	LinkStack_Destroy(stack);
	return 0;
}

int isLeft(char ch)
{
	int ret = 0;
	switch (ch)
	{
	case '<':
	case '(':
	case '{':
	case '[':
	case '\'':
	case '\"':
		ret = 1;
		break;
	default:
		ret = 0;
		break;
	}
	return ret;
}

int isRight(char ch)
{
	int ret = 0;
	switch (ch)
	{
	case '>':
	case ')':
	case '}':
	case ']':
	case '\'':
	case '\"':
		ret = 1;
		break;
	default:
		ret = 0;
		break;
	}

	return ret;
}

int isMatch(char right, char left)
{
	int ret = 0;
	switch (left)
	{
	case '<':
		ret = (right == '>');
		break;
	case '(':
		ret = (right == ')');
		break;
	case '[':
		ret = (right == ']');
		break;
	case '{':
		ret = (right == '}');
		break;
	case '\'':
		ret = (right == '\'');
		break;
	case '\"':
		ret = (right == '\"');
		break;
	default:
		ret = 0;
		break;
	}

	return ret;
}