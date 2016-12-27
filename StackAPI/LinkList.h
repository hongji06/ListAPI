#pragma once
//�u�ʪ��妡�s�x
#ifndef _LinkList_H
#define _LinkList_H_H

typedef void LinkList;

typedef struct _tag_LinkListNode
{
	struct _tag_LinkListNode *next;
}LinkListNode;

//�Ы����
LinkList * LinkList_Create();

//�P�����
void LinkList_Destroy(LinkList* list);

//�M�����
void LinkList_Clear(LinkList* list);

//�M�����,����������
int LinkList_Length(LinkList* list);

//�V���pos��m���J�ƾ�
int LinkList_Insert(LinkList* list, LinkListNode * node, int pos);

//�q���pos��m���o�ƾ�
LinkListNode* LinkList_Get(LinkList* list, int pos);

//�q���pos��m�R���ƾ�
LinkListNode* LinkList_Delte(LinkList* list, int pos);

#endif /* _List_H */
