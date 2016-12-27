#pragma once
//線性表的鍊式存儲
#ifndef _DLinkList_H
#define _DLinkList_H

typedef void DLinkList;

typedef struct _tag_DLinkListNode
{
	struct _tag_DLinkListNode *next;
	struct _tag_DLinkListNode *pre;
}DLinkListNode;

//創建鍊錶
DLinkList * DLinkList_Create();

//銷毀鍊錶
void DLinkList_Destroy(DLinkList* list);

//清空鍊錶
void DLinkList_Clear(DLinkList* list);

//清空鍊錶,獲取鍊錶長度
int DLinkList_Length(DLinkList* list);

//向鍊錶pos位置插入數據
int DLinkList_Insert(DLinkList* list, DLinkListNode * node, int pos);

//從鍊錶pos位置取得數據
DLinkListNode* DLinkList_Get(DLinkList* list, int pos);

//從鍊錶pos位置刪除數據
DLinkListNode* DLinkList_Delte(DLinkList* list, int pos);

//刪除鍊錶中的某個數據元素
DLinkListNode * DLinkList_DeleteNode(DLinkList* list, DLinkListNode * node);


//游標重置為鍊錶中的第一個元素
DLinkListNode * DLinkList_Reset(DLinkList* list);

//獲取游標指向的數據元素
DLinkListNode * DLinkList_Current(DLinkList* list);

//將游標指向下一個數據元素
DLinkListNode * DLinkList_Next(DLinkList* list);

//將游標指向上一個數據元素
DLinkListNode * DLinkList_Pre(DLinkList* list);

#endif /* _List_H */

