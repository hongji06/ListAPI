#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include "seq_list.h"

//�Ы����
SeqList* SeqList_Create(int capacity)
{
	HeadSeqList *tlist = malloc(sizeof(HeadSeqList));
	if (tlist == NULL)
	{
		printf("malloc TListList err");
		return NULL;
	}

	memset(tlist, 0, sizeof(HeadSeqList));

	tlist->node = malloc(sizeof(unsigned int **)*capacity);
	if (tlist->node == NULL)
	{
		printf("malloc TListList->node err");
		return NULL;
	}
	tlist->capacity = capacity;
	tlist->length = 0;

	return tlist;
}

//�P�����
void SeqList_Destroy(SeqList* list)
{
	HeadSeqList *tmpList = list;
	if (tmpList == NULL)
	{
		return;
	}
	if (tmpList->node != NULL)
	{
		free(tmpList->node);
	}
	free(tmpList);

	return;
}

//�M�����
void SeqList_Clear(SeqList* list)
{
	HeadSeqList *tmpList = list;
	if (tmpList == NULL)
	{
		return;
	}
	tmpList->length = 0;
	return;
}

//����������
unsigned int SeqList_Length(SeqList* list)
{
	HeadSeqList *tmpList = list;
	if (tmpList == NULL)
	{
		return 0;
	}
	return tmpList->length;
}

//�������̤j����
unsigned int SeqList_Capacity(SeqList* list)
{
	HeadSeqList *tmpList = list;
	unsigned int ret = 0;
	if (tmpList == NULL)
	{
		return 0;
	}
	ret = tmpList->capacity;
	return ret;
}

//�V���pos��m���J�ƾ�
int SeqList_Insert(SeqList* list, SeqListNode * node, int pos)
{
	HeadSeqList *tempList = (HeadSeqList *)list;
	if (tempList->capacity < (unsigned)pos || pos < 0 || node == NULL || tempList == NULL)
	{
		printf("SeqList_Insert err -1");
		return -1;
	}
	//������ץH�ζW�X�Ϊ̹F��F�̤j���סA����A�[�J����
	if (tempList->length >= tempList->capacity)
	{
		tempList = (HeadSeqList *)SeqListNode_Add(list, 1);
		//printf("SeqList had max,system will add memory;link length:%d,link capacity:%d\n", tempList->length, tempList->capacity);
	}
	//���J����m�j��������סA���O���F��̤j����
	if ((unsigned)pos > tempList->length)
	{
		pos = tempList->length;
	}
	for (size_t i = tempList->length; i > (unsigned)pos; i--)
	{
		tempList->node[i] = tempList->node[i - 1];
	}

	tempList->node[pos] = node;
	tempList->length++;
	return 0;
}

//�q���pos��m���o�ƾ�
SeqListNode* SeqList_Get(SeqList* list, int pos)
{
	HeadSeqList *tempList = (HeadSeqList *)list;
	if (tempList->capacity < (unsigned)pos || pos < 0 || tempList == NULL)
	{
		printf("SeqList_Get err -1");
		return NULL;
	}

	//���o����m�j��������סA���O���F��̤j����
	if ((unsigned)pos > tempList->length)
	{
		pos = tempList->length;
	}
	//tempList->node[pos];
	return (SeqListNode *)tempList->node[pos];
}

//�q���pos��m�R���ƾ�
SeqListNode* SeqList_Delete(SeqList* list, int pos)
{
	HeadSeqList *tempList = (HeadSeqList *)list;
	if (tempList->capacity < (unsigned)pos || pos < 0 || tempList == NULL)
	{
		printf("SeqList_Delte err -1");
		return NULL;
	}

	//�R������m�j��������סA���O���F��̤j����
	if ((unsigned)pos > tempList->length)
	{
		pos = tempList->length;
	}

	SeqListNode* tempSeqListNode = (SeqListNode*)tempList->node[pos];

	for (size_t i = (unsigned)pos; i < tempList->length; i++)
	{
		tempList->node[i] = tempList->node[i + 1];
	}
	tempList->length--;

	return tempSeqListNode;
}

//������׼W�[
SeqList * SeqListNode_Add(SeqList* list, int pos)
{
	HeadSeqList *tlist = (HeadSeqList *)list;
	if (tlist == NULL)
	{
		printf("list is null err");
		return NULL;
	}
	//tlist->node�a�}�[��
	tlist->node = realloc(tlist->node, sizeof(tlist->node)*(tlist->capacity + pos));
	if (tlist->node == NULL)
	{
		printf("realloc TListList->node err");
		return NULL;
	}
	tlist->capacity = tlist->capacity + pos;
	return (SeqList *)tlist;
}