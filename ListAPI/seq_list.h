//絬┦絬┦纗
#ifndef _SeqList_H
#define _SeqList_H

typedef void SeqList;
typedef void SeqListNode;
typedef struct _Head_SeqList
{
	unsigned int length;//铃况
	unsigned int capacity;//铃况程
	unsigned int ** node;//铃况
}HeadSeqList;
//承铃况
SeqList * SeqList_Create(int capacity);

//綪反铃况
void SeqList_Destroy(SeqList* list);

//睲铃况
void SeqList_Clear(SeqList* list);

//睲铃况,莉铃况
unsigned int SeqList_Length(SeqList* list);

//莉铃况程
unsigned int SeqList_Capacity(SeqList* list);

//铃况pos竚础计沮
int SeqList_Insert(SeqList* list, SeqListNode * node, int pos);

//眖铃况pos竚眔计沮
SeqListNode* SeqList_Get(SeqList* list, int pos);

//眖铃况pos竚埃计沮
SeqListNode* SeqList_Delete(SeqList* list, int pos);

//铃况糤
SeqList * SeqListNode_Add(SeqList* list, int pos);

#endif /* _List_H */