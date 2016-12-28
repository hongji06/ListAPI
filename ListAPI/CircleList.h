//線性表的鍊式存儲
#ifndef _CircleList_H
#define _CircleList_H

typedef void CircleList;

typedef struct _tag_CircleListNode
{
	struct _tag_CircleListNode *next;
}CircleListNode;

//創建鍊錶
CircleList * CircleList_Create();

//銷毀鍊錶
void CircleList_Destroy(CircleList* list);

//清空鍊錶
void CircleList_Clear(CircleList* list);

//清空鍊錶,獲取鍊錶長度
int CircleList_Length(CircleList* list);

//向鍊錶pos位置插入數據
int CircleList_Insert(CircleList* list, CircleListNode * node, int pos);

//從鍊錶pos位置取得數據
CircleListNode* CircleList_Get(CircleList* list, int pos);

//從鍊錶pos位置刪除數據
CircleListNode* CircleList_Delete(CircleList* list, int pos);

//游標重置為鍊錶中的第一個元素
CircleListNode * CircleList_Reset(CircleList* list);

//獲取游標指向的數據元素
CircleListNode * CircleList_Current(CircleList* list);

//將游標指向下一個數據元素
CircleListNode * CircleList_Next(CircleList* list);

//刪除鍊錶中的某個數據元素
CircleListNode * CircleList_DeleteNode(CircleList* list, CircleListNode * node);
#endif /* _List_H */
