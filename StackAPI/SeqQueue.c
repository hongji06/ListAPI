#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include "seq_list.h"
#include "SeqQueue.h"

SeqQueue * SeqQueue_Create(int capacity)
{
	return SeqList_Create(capacity);
}
void SeqQueue_Destroy(SeqQueue* queue)
{
	SeqList_Destroy(queue);
	return;
}
void SeqQueue_Clear(SeqQueue* queue)
{
	SeqList_Clear(queue);
	return ;
}
int SeqQueue_Append(SeqQueue* queue, void * item)
{
	return SeqList_Insert(queue, item, 0);
}
void* SeqQueue_Retrieve(SeqQueue* queue)
{
	SeqQueue *temp = NULL;
	temp =	(SeqQueue *)SeqList_Delte(queue, SeqQueue_Length(queue)-1);
	return temp;
}
void* SeqQueue_Header(SeqQueue* queue)
{
	SeqQueue *temp = NULL;
	temp = (SeqQueue *)SeqList_Get(queue, 0);
	return temp;
}
int SeqQueue_Length(SeqQueue* queue)
{
	return SeqList_Length(queue);
}
int SeqQueue_Capacity(SeqQueue* queue)
{
	return (int)SeqList_Capacity(queue);
}