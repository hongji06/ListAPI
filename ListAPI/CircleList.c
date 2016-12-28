#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include "CircleList.h"

typedef struct _Head_CircleList
{
	CircleListNode header;//指向鍊錶
	CircleListNode* slider;//游標
	int length;//鍊錶長度
}HeadCircleList;


//創建鍊錶
CircleList * CircleList_Create()
{
	HeadCircleList * headList = malloc(sizeof(HeadCircleList));
	memset(headList, 0, sizeof(HeadCircleList));
	headList->length = 0;
	headList->header.next = NULL;
	headList->slider = NULL;
	return headList;
}

//銷毀鍊錶
void CircleList_Destroy(CircleList* list)
{
	if (list != NULL)
	{
		free(list);
		list = NULL;
	}
	
	return;
}

//清空鍊錶
void CircleList_Clear(CircleList* list)
{
	HeadCircleList *headList = (HeadCircleList *)list;
	headList->length = 0;
	headList->header.next = NULL;
	headList->slider = NULL;
	return;
}

//獲取鍊錶長度
int CircleList_Length(CircleList* list)
{
	HeadCircleList *headList = (HeadCircleList *)list;
	return headList->length;
}


//向鍊錶pos位置插入數據
int CircleList_Insert(CircleList* list, CircleListNode * node, int pos)
{
	if (list == NULL || node == NULL || pos < 0 || pos>CircleList_Length(list))
	{
		printf("LinkList_Insert err -1");
		return -1;
	}

	CircleListNode *current = NULL;
	HeadCircleList *headList = (HeadCircleList *)list;

	current = &headList->header;

	for (int i = 0; i < pos && (current->next != NULL); i++)
	{
		current = current->next;
	}

	node->next = current->next;
	current->next = node;

	//第一次插入結點
	if (headList->length == 0)
	{
		headList->slider = node;
	}

	headList->length++;

	//若頭插法current仍然指向頭部
	if (current == (CircleListNode *)headList)
	{
		CircleListNode* last = CircleList_Get(headList, headList->length-1);
		last->next = current->next;
	}

	return 0;
}

//從鍊錶pos位置取得數據
CircleListNode* CircleList_Get(CircleList* list, int pos)
{
	if (list == NULL || pos < 0)
	{
		printf("LinkList_Get err -1");
		return NULL;
	}

	CircleListNode *current = NULL;
	HeadCircleList *headList = (HeadCircleList *)list;

	current = &(headList->header);

	for (int i = 0; i < pos; i++)
	{
		current = current->next;
	}

	return current->next;
}

//從鍊錶pos位置刪除數據
CircleListNode* CircleList_Delete(CircleList* list, int pos)
{
	if (list == NULL || pos < 0 || pos>CircleList_Length(list))
	{
		printf("LinkList_Delte err -1");
		return NULL;
	}


	CircleListNode *ret = NULL;
	HeadCircleList *headList = (HeadCircleList *)list;
	CircleListNode *current = (CircleListNode *)list;
	CircleListNode *last = NULL;

	for (int i = 0; i < pos; i++)
	{
		current = current->next;
	}

	//若刪除第一個元素
	if (current == (CircleListNode *)headList)
	{
		last = CircleList_Get(headList, headList->length - 1);
	}

	ret = current->next;
	current->next = ret->next;

	headList->length--;

	//判斷鍊錶是否為空
	if (last != NULL)
	{
		headList->header.next = ret->next;
		last->next = ret->next;
	}
	
	//刪除的元素為游標slider所指向的位置
	if (headList->slider == ret)
	{
		headList->slider = ret->next;
	}

	//刪除元素後鍊錶長度為0
	if (headList->length == 0)
	{
		headList->header.next = NULL;
		headList->slider = NULL;
	}
	return ret;
}

//游標重置為鍊錶中的第一個元素
CircleListNode * CircleList_Reset(CircleList* list)
{
	HeadCircleList *headList = (HeadCircleList *)list;
	headList->slider = headList->header.next;
	return headList->slider;
}

//獲取游標指向的數據元素
CircleListNode * CircleList_Current(CircleList* list)
{
	HeadCircleList *headList = (HeadCircleList *)list;
	return headList->slider;
}

//將游標指向下一個數據元素
CircleListNode * CircleList_Next(CircleList* list)
{
	HeadCircleList *headList = (HeadCircleList *)list;
	CircleListNode *ret = NULL;

	if ((headList != NULL)&&(headList->slider!=NULL))
	{
		ret = headList->slider;
		headList->slider = ret->next;
	}
	return ret;
}

//刪除鍊錶中的某個數據元素
CircleListNode * CircleList_DeleteNode(CircleList* list, CircleListNode * node)
{
	HeadCircleList *headList = (HeadCircleList *)list;
	CircleListNode *ret = NULL;
	int i = 0;

	if (headList != NULL)
	{
		CircleListNode *current = (CircleListNode *)list;
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
			CircleList_Delete(headList, i);
		}
	}

	return ret;
}