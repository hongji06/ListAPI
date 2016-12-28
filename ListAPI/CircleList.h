//�u�ʪ��妡�s�x
#ifndef _CircleList_H
#define _CircleList_H

typedef void CircleList;

typedef struct _tag_CircleListNode
{
	struct _tag_CircleListNode *next;
}CircleListNode;

//�Ы����
CircleList * CircleList_Create();

//�P�����
void CircleList_Destroy(CircleList* list);

//�M�����
void CircleList_Clear(CircleList* list);

//�M�����,����������
int CircleList_Length(CircleList* list);

//�V���pos��m���J�ƾ�
int CircleList_Insert(CircleList* list, CircleListNode * node, int pos);

//�q���pos��m���o�ƾ�
CircleListNode* CircleList_Get(CircleList* list, int pos);

//�q���pos��m�R���ƾ�
CircleListNode* CircleList_Delete(CircleList* list, int pos);

//��Э��m����������Ĥ@�Ӥ���
CircleListNode * CircleList_Reset(CircleList* list);

//�����Ы��V���ƾڤ���
CircleListNode * CircleList_Current(CircleList* list);

//�N��Ы��V�U�@�Ӽƾڤ���
CircleListNode * CircleList_Next(CircleList* list);

//�R����������Y�Ӽƾڤ���
CircleListNode * CircleList_DeleteNode(CircleList* list, CircleListNode * node);
#endif /* _List_H */
