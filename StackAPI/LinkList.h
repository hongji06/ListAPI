#pragma once
//線性表的鍊式存儲
#ifndef _LinkList_H
#define _LinkList_H_H

typedef void LinkList;

typedef struct _tag_LinkListNode
{
	struct _tag_LinkListNode *next;
}LinkListNode;

//創建鍊錶
LinkList * LinkList_Create();

//銷毀鍊錶
void LinkList_Destroy(LinkList* list);

//清空鍊錶
void LinkList_Clear(LinkList* list);

//清空鍊錶,獲取鍊錶長度
int LinkList_Length(LinkList* list);

//向鍊錶pos位置插入數據
int LinkList_Insert(LinkList* list, LinkListNode * node, int pos);

//從鍊錶pos位置取得數據
LinkListNode* LinkList_Get(LinkList* list, int pos);

//從鍊錶pos位置刪除數據
LinkListNode* LinkList_Delte(LinkList* list, int pos);

#endif /* _List_H */
