#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"DLinkList.h"

typedef struct Teacher
{
	DLinkListNode node;
	int age;
	char *name;
} *Teacher;

int main()//_DLinkList
{
	//創建鍊錶
	DLinkList *list = DLinkList_Create();
	if (list == NULL)
	{
		printf("LinkList_Create Error...");
		return 0;
	}

	Teacher t1 = malloc(sizeof(struct Teacher)), t2 = malloc(sizeof(struct Teacher)), t3 = malloc(sizeof(struct Teacher)), t4 = malloc(sizeof(struct Teacher)), t5 = malloc(sizeof(struct Teacher));

	memset(t1, 0, sizeof(t1));
	memset(t2, 0, sizeof(t2));
	memset(t3, 0, sizeof(t3));
	memset(t4, 0, sizeof(t4));
	memset(t5, 0, sizeof(t5));

	t1->age = 1;
	t1->name = "hello";

	t2->age = 2;
	t2->name = "world32";

	t3->age = 3;
	t3->name = "world33";

	t4->age = 4;
	t4->name = "world34";

	t5->age = 5;
	t5->name = "world35";

	//向鍊錶pos位置插入數據
	DLinkList_Insert(list, (DLinkListNode*)t1, DLinkList_Length(list));
	DLinkList_Insert(list, (DLinkListNode*)t2, DLinkList_Length(list));
	DLinkList_Insert(list, (DLinkListNode*)t3, DLinkList_Length(list));
	DLinkList_Insert(list, (DLinkListNode*)t4, DLinkList_Length(list));
	DLinkList_Insert(list, (DLinkListNode*)t5, DLinkList_Length(list));

	//打印鍊錶的元素
	printf("鍊錶內容如下：\n");
	for (int i = 0; i < DLinkList_Length(list) * 2; i++)
	{
		Teacher temp = (Teacher)DLinkList_Get(list, i);
		if (temp == NULL)
		{
			printf("LinkList_Get Error...");
			return 0;
		}
		printf("teacher[%d] age:%d,name:%s;\n", i, temp->age, temp->name);
	}


	printf("鍊錶當前游標指向元素：\n");
	Teacher temp = (Teacher)DLinkList_Current(list);
	if (temp == NULL)
	{
		printf("DLinkList_Current Error...");
		return 0;
	}
	printf("teacher age:%d,name:%s;\n", temp->age, temp->name);

	printf("鍊錶當前游標往後移動元素：\n");
	DLinkList_Next(list);
	temp = (Teacher)DLinkList_Current(list);
	if (temp == NULL)
	{
		printf("DLinkList_Current Error...");
		return 0;
	}
	printf("teacher age:%d,name:%s;\n", temp->age, temp->name);

	printf("鍊錶當前游標往後移動元素：\n");
	DLinkList_Next(list);
	temp = (Teacher)DLinkList_Current(list);
	if (temp == NULL)
	{
		printf("DLinkList_Current Error...");
		return 0;
	}
	printf("teacher age:%d,name:%s;\n", temp->age, temp->name);

	printf("游標重置為鍊錶中的第一個元素：\n");
	DLinkList_Reset(list);
	temp = (Teacher)DLinkList_Current(list);
	if (temp == NULL)
	{
		printf("DLinkList_Current Error...");
		return 0;
	}
	printf("teacher age:%d,name:%s;\n", temp->age, temp->name);

	printf("鍊錶當前游標往前移動元素：\n");
	DLinkList_Next(list);
	temp = (Teacher)DLinkList_Current(list);
	if (temp == NULL)
	{
		printf("DLinkList_Current Error...");
		return 0;
	}
	printf("teacher age:%d,name:%s;\n", temp->age, temp->name);	


	printf("刪除鍊錶中的某個數據元素：\n"); 
	printf("teacher age:%d,name:%s;\n", temp->age, temp->name);
	temp = (Teacher)DLinkList_DeleteNode(list, (DLinkListNode *)(temp));
	if (temp == NULL)
	{
		printf("DLinkList_Current Error...");
		return 0;
	}
	printf("teacher age:%d,name:%s;\n", temp->age, temp->name);


	printf("鍊錶內容如下：\n");
	for (int i = 0; i < DLinkList_Length(list) * 2; i++)
	{
		temp = (Teacher)DLinkList_Get(list, i);
		if (temp == NULL)
		{
			printf("LinkList_Get Error...");
			return 0;
		}
		printf("teacher[%d] age:%d,name:%s;\n", i, temp->age, temp->name);
	}

	DLinkList_Destroy(list);

	printf("finished...\n");
	getchar();
	return 0;
}