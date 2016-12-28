//�u�ʪ��u�ʦs�x
#ifndef _SeqList_H
#define _SeqList_H

typedef void SeqList;
typedef void SeqListNode;
typedef struct _Head_SeqList
{
	unsigned int length;//�������
	unsigned int capacity;//����̤j����
	unsigned int ** node;//���V���
}HeadSeqList;
//�Ы����
SeqList * SeqList_Create(int capacity);

//�P�����
void SeqList_Destroy(SeqList* list);

//�M�����
void SeqList_Clear(SeqList* list);

//�M�����,����������
unsigned int SeqList_Length(SeqList* list);

//�������̤j����
unsigned int SeqList_Capacity(SeqList* list);

//�V���pos��m���J�ƾ�
int SeqList_Insert(SeqList* list, SeqListNode * node, int pos);

//�q���pos��m���o�ƾ�
SeqListNode* SeqList_Get(SeqList* list, int pos);

//�q���pos��m�R���ƾ�
SeqListNode* SeqList_Delete(SeqList* list, int pos);

//������׼W�[
SeqList * SeqListNode_Add(SeqList* list, int pos);

#endif /* _List_H */