#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"LinkList.h"

typedef struct Teacher
{
	LinkListNode node;
	int age;
	char *name;
} *Teacher;

int main_LinkList()
{
	//創建鍊錶
	LinkList *list = LinkList_Create();
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

	t1->age = 31;
	t1->name = "hello";

	t2->age = 32;
	t2->name = "world32";

	t3->age = 33;
	t3->name = "world33";

	t4->age = 34;
	t4->name = "world34";

	t5->age = 35;
	t5->name = "world35";

	//向鍊錶pos位置插入數據
	LinkList_Insert(list, (LinkListNode*)t1, 0);
	LinkList_Insert(list, (LinkListNode*)t2, 0);
	LinkList_Insert(list, (LinkListNode*)t3, 0);
	LinkList_Insert(list, (LinkListNode*)t4, 0);
	LinkList_Insert(list, (LinkListNode*)t5, 0);

	//打印鍊錶的元素
	printf("鍊錶內容如下：\n");
	for (int i = 0; i < LinkList_Length(list); i++)
	{
		Teacher temp = (Teacher)LinkList_Get(list, i);
		if (temp == NULL)
		{
			printf("LinkList_Get Error...");
			return 0;
		}
		printf("teacher[%d] age:%d,name:%s;\n", i, temp->age, temp->name);
	}

	//從鍊錶pos位置刪除數據
	printf("鍊錶刪除如下：\n");
	while (LinkList_Length(list)>1)
	{
		Teacher temp = (Teacher)LinkList_Delete(list, 0);

		if (temp == NULL)
		{
			printf("LinkList_Delte Error...\n");
			return 1;
		}
		printf("delete node：%d,%s;\n", temp->age, temp->name);
		free(temp);
	}

	//打印鍊錶的元素
	printf("鍊錶內容如下：\n");
	for (int i = 0; i < LinkList_Length(list); i++)
	{
		Teacher temp = (Teacher)LinkList_Get(list, i);
		if (temp == NULL)
		{
			printf("LinkList_Get Error...");
			return 0;
		}
		printf("teacher[%d] age:%d,name:%s;\n", i, temp->age, temp->name);
	}

	LinkList_Destroy(list);

	printf("finished...\n");
	getchar();
	return 0;
}