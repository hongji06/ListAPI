#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include "CircleList.h"

typedef struct _Head_CircleList
{
	CircleListNode header;//���V���
	CircleListNode* slider;//���
	int length;//�������
}HeadCircleList;


//�Ы����
CircleList * CircleList_Create()
{
	HeadCircleList * headList = malloc(sizeof(HeadCircleList));
	memset(headList, 0, sizeof(HeadCircleList));
	headList->length = 0;
	headList->header.next = NULL;
	headList->slider = NULL;
	return headList;
}

//�P�����
void CircleList_Destroy(CircleList* list)
{
	if (list != NULL)
	{
		free(list);
		list = NULL;
	}
	
	return;
}

//�M�����
void CircleList_Clear(CircleList* list)
{
	HeadCircleList *headList = (HeadCircleList *)list;
	headList->length = 0;
	headList->header.next = NULL;
	headList->slider = NULL;
	return;
}

//����������
int CircleList_Length(CircleList* list)
{
	HeadCircleList *headList = (HeadCircleList *)list;
	return headList->length;
}


//�V���pos��m���J�ƾ�
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

	//�Ĥ@�����J���I
	if (headList->length == 0)
	{
		headList->slider = node;
	}

	headList->length++;

	//�Y�Y���kcurrent���M���V�Y��
	if (current == (CircleListNode *)headList)
	{
		CircleListNode* last = CircleList_Get(headList, headList->length-1);
		last->next = current->next;
	}

	return 0;
}

//�q���pos��m���o�ƾ�
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

//�q���pos��m�R���ƾ�
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

	//�Y�R���Ĥ@�Ӥ���
	if (current == (CircleListNode *)headList)
	{
		last = CircleList_Get(headList, headList->length - 1);
	}

	ret = current->next;
	current->next = ret->next;

	headList->length--;

	//�P�_����O�_����
	if (last != NULL)
	{
		headList->header.next = ret->next;
		last->next = ret->next;
	}
	
	//�R�������������slider�ҫ��V����m
	if (headList->slider == ret)
	{
		headList->slider = ret->next;
	}

	//�R��������������׬�0
	if (headList->length == 0)
	{
		headList->header.next = NULL;
		headList->slider = NULL;
	}
	return ret;
}

//��Э��m����������Ĥ@�Ӥ���
CircleListNode * CircleList_Reset(CircleList* list)
{
	HeadCircleList *headList = (HeadCircleList *)list;
	headList->slider = headList->header.next;
	return headList->slider;
}

//�����Ы��V���ƾڤ���
CircleListNode * CircleList_Current(CircleList* list)
{
	HeadCircleList *headList = (HeadCircleList *)list;
	return headList->slider;
}

//�N��Ы��V�U�@�Ӽƾڤ���
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

//�R����������Y�Ӽƾڤ���
CircleListNode * CircleList_DeleteNode(CircleList* list, CircleListNode * node)
{
	HeadCircleList *headList = (HeadCircleList *)list;
	CircleListNode *ret = NULL;
	int i = 0;

	if (headList != NULL)
	{
		CircleListNode *current = (CircleListNode *)list;
		//�d��node�b�������mi
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