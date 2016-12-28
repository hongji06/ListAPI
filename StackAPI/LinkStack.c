#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkStack.h"
#include "LinkList.h"

typedef struct _tag_LinkStackNode
{
	LinkListNode node;
	void * item;
}TLinkStackNode;

//create stack
LinkStack * LinkStack_Create()
{
	return LinkList_Create();
}

//destroy stack
void LinkStack_Destroy(LinkStack* stack)
{
	LinkStack_Clear(stack);
	LinkList_Destroy(stack);
	return;
}

//clear stack
void LinkStack_Clear(LinkStack* stack)
{
	if (stack == NULL)
	{
		return;
	}

	while (LinkStack_Size(stack) > 0)
	{
		LinkStack_Pop(stack);
	}
	return;
}

//push
int LinkStack_Push(LinkStack* stack, void * item)
{
	TLinkStackNode* tmp = malloc(sizeof(TLinkStackNode));
	int ret = 0;
	if (tmp == NULL)
	{
		return -1;
	}
	memset(tmp, 0, sizeof(TLinkStackNode));

	tmp->item = item;

	ret = LinkList_Insert(stack, (LinkListNode *)tmp, 0);
	if (ret != 0)
	{
		if (tmp != NULL)
		{
			free(tmp);
		}
		printf("LinkStack_Push err:%d\n", ret);
	}
	return ret;
}

//pop
void* LinkStack_Pop(LinkStack* stack)
{
	TLinkStackNode *tmp = (TLinkStackNode *)stack;
	void * item = NULL;

	tmp = (TLinkStackNode *)LinkList_Delete(stack, 0);
	if (tmp == NULL)
	{
		return NULL;
	}
	item = tmp->item;
	free(tmp);
	return item;
}

//top
void* LinkStack_Top(LinkStack* stack)
{
	TLinkStackNode *tmp = (TLinkStackNode *)stack;
	tmp = (TLinkStackNode *)LinkList_Get(stack, 0);
	if (tmp == NULL)
	{
		return NULL;
	}
	return tmp->item;
}

//get size of stack
int LinkStack_Size(LinkStack* stack)
{
	return LinkList_Length(stack);
}