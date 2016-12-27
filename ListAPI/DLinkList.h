#pragma once
//�u�ʪ��妡�s�x
#ifndef _DLinkList_H
#define _DLinkList_H

typedef void DLinkList;

typedef struct _tag_DLinkListNode
{
	struct _tag_DLinkListNode *next;
	struct _tag_DLinkListNode *pre;
}DLinkListNode;

//�Ы����
DLinkList * DLinkList_Create();

//�P�����
void DLinkList_Destroy(DLinkList* list);

//�M�����
void DLinkList_Clear(DLinkList* list);

//�M�����,����������
int DLinkList_Length(DLinkList* list);

//�V���pos��m���J�ƾ�
int DLinkList_Insert(DLinkList* list, DLinkListNode * node, int pos);

//�q���pos��m���o�ƾ�
DLinkListNode* DLinkList_Get(DLinkList* list, int pos);

//�q���pos��m�R���ƾ�
DLinkListNode* DLinkList_Delte(DLinkList* list, int pos);

//�R����������Y�Ӽƾڤ���
DLinkListNode * DLinkList_DeleteNode(DLinkList* list, DLinkListNode * node);


//��Э��m����������Ĥ@�Ӥ���
DLinkListNode * DLinkList_Reset(DLinkList* list);

//�����Ы��V���ƾڤ���
DLinkListNode * DLinkList_Current(DLinkList* list);

//�N��Ы��V�U�@�Ӽƾڤ���
DLinkListNode * DLinkList_Next(DLinkList* list);

//�N��Ы��V�W�@�Ӽƾڤ���
DLinkListNode * DLinkList_Pre(DLinkList* list);

#endif /* _List_H */

