#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include "DLinkList.h"

typedef struct _Head_LinkList
{
	DLinkListNode head;//指向鍊錶
	DLinkListNode* slider;//游標
	int length;//鍊錶長度
}HeadLinkList;


//創建鍊錶
DLinkList * DLinkList_Create()
{
	HeadLinkList * headList = malloc(sizeof(HeadLinkList));
	memset(headList, 0, sizeof(HeadLinkList));
	headList->length = 0;
	headList->head.next = NULL;
	headList->head.pre = NULL;
	headList->slider = NULL;
	return headList;
}

//銷毀鍊錶
void DLinkList_Destroy(DLinkList* list)
{
	if (list == NULL)
	{
		free(list);
		list = NULL;
	}
	return;
}

//清空鍊錶
void DLinkList_Clear(DLinkList* list)
{
	HeadLinkList *headList = (HeadLinkList *)list;
	headList->length = 0;
	headList->head.next = NULL;
	headList->head.pre = NULL;
	headList->slider = NULL;
	return;
}

//獲取鍊錶長度
int DLinkList_Length(DLinkList* list)
{
	HeadLinkList *headList = (HeadLinkList *)list;
	return headList->length;
}


//向鍊錶pos位置插入數據
int DLinkList_Insert(DLinkList* list, DLinkListNode * node, int pos)
{
	if (list == NULL || node == NULL || pos < 0)
	{
		printf("DLinkList_Insert err -1");
		return -1;
	}

	DLinkListNode *current = NULL;
	DLinkListNode *next = NULL;
	HeadLinkList *headList = (HeadLinkList *)list;

	current = &headList->head;

	for (int i = 0; i < pos && (current->next != NULL); i++)
	{
		current = current->next;
	}
	next = current->next;


	node->next = next;
	node->pre = current;
	current->next = node;

	if (next != NULL)
	{
		next->pre = node;
	}
	

	//第一次插入結點
	if (headList->length == 0)
	{
		headList->slider = node;
	}

	headList->length++;

	//若頭插法current仍然指向頭部
	if (current == (DLinkListNode *)headList)
	{
		DLinkListNode* last = DLinkList_Get(headList, headList->length - 1);
		if (last != NULL)
		{
			last->next = current->next;
		}		
		current->pre = last;
	}
	return 0;
}

//從鍊錶pos位置取得數據
DLinkListNode* DLinkList_Get(DLinkList* list, int pos)
{
	if (list == NULL || pos < 0)
	{
		printf("LinkList_Get err -1");
		return NULL;
	}

	DLinkListNode *current = NULL;
	HeadLinkList *headList = (HeadLinkList *)list;

	current = &(headList->head);

	for (int i = 0; i < pos; i++)
	{
		current = current->next;
	}

	return current->next;
}

//從鍊錶pos位置刪除數據
DLinkListNode* DLinkList_Delete(DLinkList* list, int pos)
{
	if (list == NULL || pos < 0 )
	{
		printf("LinkList_Delte err -1");
		return NULL;
	}


	DLinkListNode *ret = NULL;
	HeadLinkList *headList = (HeadLinkList *)list;
	DLinkListNode *current = (DLinkListNode *)list;
	DLinkListNode *last = NULL;
	DLinkListNode *next = NULL;

	for (int i = 0; i < pos; i++)
	{
		current = current->next;
	}

	//若刪除第一個元素
	if (current == (DLinkListNode *)headList)
	{
		last = DLinkList_Get(headList, headList->length - 1);
	}

	ret = current->next;
	next = ret->next;

	current->next = next;
	next->pre = current;

	headList->length--;

	//判斷鍊錶是否為空
	if (last != NULL)
	{
		headList->head.next = next;
		last->next = next;
		next->pre = last;
	}

	//刪除的元素為游標slider所指向的位置
	if (headList->slider == ret)
	{
		headList->slider = next;
	}

	//刪除元素後鍊錶長度為0
	if (headList->length == 0)
	{
		headList->head.next = NULL;
		headList->slider = NULL;
	}
	return ret;
}

//游標重置為鍊錶中的第一個元素
DLinkListNode * DLinkList_Reset(DLinkList* list)
{
	HeadLinkList *headList = (HeadLinkList *)list;
	headList->slider = headList->head.next;
	return headList->slider;
}

//獲取游標指向的數據元素
DLinkListNode * DLinkList_Current(DLinkList* list)
{
	HeadLinkList *headList = (HeadLinkList *)list;
	return headList->slider;
}

//將游標指向下一個數據元素
DLinkListNode * DLinkList_Next(DLinkList* list)
{
	HeadLinkList *headList = (HeadLinkList *)list;
	DLinkListNode *ret = NULL;

	if ((headList != NULL) && (headList->slider != NULL))
	{
		ret = headList->slider;
		headList->slider = ret->next;
	}
	return ret;
}

//將游標指向前一個數據元素
DLinkListNode * DLinkList_Pre(DLinkList* list)
{
	HeadLinkList *headList = (HeadLinkList *)list;
	DLinkListNode *ret = NULL;

	if ((headList != NULL) && (headList->slider != NULL))
	{
		ret = headList->slider;
		headList->slider = ret->pre;
	}
	return ret;
}

//刪除鍊錶中的某個數據元素
DLinkListNode * DLinkList_DeleteNode(DLinkList* list, DLinkListNode * node)
{
	HeadLinkList *headList = (HeadLinkList *)list;
	DLinkListNode *ret = NULL;
	int i = 0;

	if (headList != NULL)
	{
		DLinkListNode *current = (DLinkListNode *)list;
		//查找node在鍊錶的位置i
		for (i = 0; i < headList->length; i++)
		{
			if (current->next == node)
			{
				ret = current->next;
				break;
			}
			current = current->next;
		}

		if (ret != NULL)
		{
			DLinkList_Delete(headList, i);
		}
	}

	return ret;
}