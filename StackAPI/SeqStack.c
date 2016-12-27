#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include "SeqStack.h"
#include "seq_list.h"

//create stack
SeqStack * SeqStack_Create(int capacity)
{
	return SeqList_Create(capacity);
}

//destroy stack
void SeqStack_Destroy(SeqStack* stack)
{
	SeqList_Destroy(stack);
}

//clear stack
void SeqStack_Clear(SeqStack* stack)
{
	SeqList_Clear(stack);
}

//push
int SeqStack_Push(SeqStack* stack, void * item)
{
	return SeqList_Insert(stack, item, SeqList_Length(stack));
}

//pop
void* SeqStack_Pop(SeqStack* stack)
{
	return SeqList_Delte(stack, SeqList_Length(stack) - 1);
}

//top
void* SeqStack_Top(SeqStack* stack)
{
	return SeqList_Get(stack, SeqList_Length(stack) - 1);
}

//get size of stack
int SeqStack_Size(SeqStack* stack)
{
	return SeqList_Length(stack);
}

//get Capacity of stack
int SeqStack_Capacity(SeqStack* stack)
{
	return SeqList_Capacity(stack);
}