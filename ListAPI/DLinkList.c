#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include "DLinkList.h"

typedef struct _Head_LinkList
{
	DLinkListNode head;//���V���
	DLinkListNode* slider;//���
	int length;//�������
}HeadLinkList;


//�Ы����
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

//�P�����
void DLinkList_Destroy(DLinkList* list)
{
	if (list == NULL)
	{
		free(list);
		list = NULL;
	}
	return;
}

//�M�����
void DLinkList_Clear(DLinkList* list)
{
	HeadLinkList *headList = (HeadLinkList *)list;
	headList->length = 0;
	headList->head.next = NULL;
	headList->head.pre = NULL;
	headList->slider = NULL;
	return;
}

//����������
int DLinkList_Length(DLinkList* list)
{
	HeadLinkList *headList = (HeadLinkList *)list;
	return headList->length;
}


//�V���pos��m���J�ƾ�
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
	

	//�Ĥ@�����J���I
	if (headList->length == 0)
	{
		headList->slider = node;
	}

	headList->length++;

	//�Y�Y���kcurrent���M���V�Y��
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

//�q���pos��m���o�ƾ�
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

//�q���pos��m�R���ƾ�
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

	//�Y�R���Ĥ@�Ӥ���
	if (current == (DLinkListNode *)headList)
	{
		last = DLinkList_Get(headList, headList->length - 1);
	}

	ret = current->next;
	next = ret->next;

	current->next = next;
	next->pre = current;

	headList->length--;

	//�P�_����O�_����
	if (last != NULL)
	{
		headList->head.next = next;
		last->next = next;
		next->pre = last;
	}

	//�R�������������slider�ҫ��V����m
	if (headList->slider == ret)
	{
		headList->slider = next;
	}

	//�R��������������׬�0
	if (headList->length == 0)
	{
		headList->head.next = NULL;
		headList->slider = NULL;
	}
	return ret;
}

//��Э��m����������Ĥ@�Ӥ���
DLinkListNode * DLinkList_Reset(DLinkList* list)
{
	HeadLinkList *headList = (HeadLinkList *)list;
	headList->slider = headList->head.next;
	return headList->slider;
}

//�����Ы��V���ƾڤ���
DLinkListNode * DLinkList_Current(DLinkList* list)
{
	HeadLinkList *headList = (HeadLinkList *)list;
	return headList->slider;
}

//�N��Ы��V�U�@�Ӽƾڤ���
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

//�N��Ы��V�e�@�Ӽƾڤ���
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

//�R����������Y�Ӽƾڤ���
DLinkListNode * DLinkList_DeleteNode(DLinkList* list, DLinkListNode * node)
{
	HeadLinkList *headList = (HeadLinkList *)list;
	DLinkListNode *ret = NULL;
	int i = 0;

	if (headList != NULL)
	{
		DLinkListNode *current = (DLinkListNode *)list;
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
			DLinkList_Delete(headList, i);
		}
	}

	return ret;
}