#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include "LinkList.h"

typedef struct _Head_LinkList
{
	LinkListNode head;//指向鍊錶
	int length;//鍊錶長度
}HeadLinkList;


//創建鍊錶
LinkList * LinkList_Create()
{
	HeadLinkList * headList = malloc(sizeof(HeadLinkList));
	memset(headList, 0, sizeof(HeadLinkList));
	headList->length = 0;
	headList->head.next = NULL;
	return (LinkList *)headList;
}

//銷毀鍊錶
void LinkList_Destroy(LinkList* list)
{
	if (list == NULL)
	{
		free(list);
		list = NULL;
	}	
	return;
}

//清空鍊錶
void LinkList_Clear(LinkList* list)
{
	HeadLinkList *headList = (HeadLinkList *)list;
	headList->length = 0;
	headList->head.next = NULL;
	return;
}

//獲取鍊錶長度
int LinkList_Length(LinkList* list)
{
	HeadLinkList *headList = (HeadLinkList *)list;
	return headList->length;
}


//向鍊錶pos位置插入數據
int LinkList_Insert(LinkList* list, LinkListNode * node, int pos)
{
	if (list == NULL || node == NULL || pos < 0 || pos>LinkList_Length(list))
	{
		printf("LinkList_Insert err -1");
		return -1;
	}

	LinkListNode *current = NULL;
	HeadLinkList *headList = (HeadLinkList *)list;

	current = &headList->head;

	for (int i = 0; i < pos && (current->next != NULL); i++)
	{
		current = current->next;
	}

	node->next = current->next;
	current->next = node;

	headList->length++;

	return 0;
}

//從鍊錶pos位置取得數據
LinkListNode* LinkList_Get(LinkList* list, int pos)
{
	if (list == NULL || pos < 0 || pos>LinkList_Length(list))
	{
		printf("LinkList_Get err -1");
		return NULL;
	}

	LinkListNode *current = NULL;
	HeadLinkList *headList = (HeadLinkList *)list;

	current = &(headList->head);

	for (int i = 0; i < pos; i++)
	{
		current = current->next;
	}

	return current->next;
}

//從鍊錶pos位置刪除數據
LinkListNode* LinkList_Delete(LinkList* list, int pos)
{
	if (list == NULL || pos < 0 || pos>LinkList_Length(list))
	{
		printf("LinkList_Delte err -1");
		return NULL;
	}


	LinkListNode *ret = NULL;
	HeadLinkList *headList = (HeadLinkList *)list;
	LinkListNode *current = &(headList->head);

	for (int i = 0; i < pos; i++)
	{
		current = current->next;
	}

	ret = current->next;
	if (ret != NULL)
	{
		current->next = ret->next;
	}	

	headList->length--;

	return ret;
}
