#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include "LinkList.h"
#include "LinkQueue.h"

typedef struct _tag_LinkQueue
{
	LinkListNode node;
	void * item;
}TLinkQueue;

LinkQueue * LinkQueue_Create()
{	
	return LinkList_Create();
}
void LinkQueue_Destroy(LinkQueue* queue)
{
	LinkQueue_Clear(queue);
	LinkList_Destroy(queue);
	return ;
}
void LinkQueue_Clear(LinkQueue* queue)
{
	while (LinkQueue_Length(queue) > 0)
	{
		LinkQueue_Retrieve(queue);
	}
	return ;
}
int LinkQueue_Append(LinkQueue* queue, void * item)
{
	int ret = 0;
	TLinkQueue *tmp = malloc(sizeof(TLinkQueue));
	memset(tmp, 0, sizeof(TLinkQueue));
	tmp->item = item;
	LinkListNode *node = (LinkListNode*)tmp;
	if (node == NULL)
	{
		return -1;
	}
	ret=LinkList_Insert(queue, node, 0);
	if (ret != 0)
	{
		return -2;
	}
	return 0;
}
void* LinkQueue_Retrieve(LinkQueue* queue)
{
	TLinkQueue *tmp = malloc(sizeof(TLinkQueue));
	memset(tmp, 0, sizeof(TLinkQueue));

	tmp=(TLinkQueue *)LinkList_Delete(queue, LinkQueue_Length(queue)-1);
	if (tmp == NULL)
	{
		return NULL;
	}

	return tmp->item;
}
void* LinkQueue_Header(LinkQueue* queue)
{
	TLinkQueue *tmp = malloc(sizeof(TLinkQueue));
	memset(tmp, 0, sizeof(TLinkQueue));

	tmp = (TLinkQueue *)LinkList_Get(queue, 0);
	if (tmp == NULL)
	{
		return NULL;
	}

	return tmp->item;
}
int LinkQueue_Length(LinkQueue* queue)
{	
	return LinkList_Length(queue);
}