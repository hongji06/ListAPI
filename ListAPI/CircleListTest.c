#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"CircleList.h"

typedef struct Teacher
{
	CircleListNode node;
	int age;
	char *name;
} *Teacher;

int main_CircleList()
{
	//創建鍊錶
	CircleList *list = CircleList_Create();
	if (list == NULL)
	{
		printf("CircleList_Create Error...");
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
	CircleList_Insert(list, (CircleListNode*)t1, 0);
	CircleList_Insert(list, (CircleListNode*)t2, 0);
	CircleList_Insert(list, (CircleListNode*)t3, 0);
	CircleList_Insert(list, (CircleListNode*)t4, 0);
	CircleList_Insert(list, (CircleListNode*)t5, 0);

	//打印鍊錶的元素
	printf("鍊錶內容如下：\n");
	for (int i = 0; i < CircleList_Length(list) * 2; i++)
	{
		Teacher temp = (Teacher)CircleList_Get(list, i);
		if (temp == NULL)
		{
			printf("LinkList_Get Error...");
			return 0;
		}
		printf("teacher[%d] age:%d,name:%s;\n", i, temp->age, temp->name);
	}

	//從鍊錶pos位置刪除數據
	printf("鍊錶刪除如下：\n");
	while (CircleList_Length(list) > 1)
	{
		Teacher temp = (Teacher)CircleList_Delete(list, 0);

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
	for (int i = 0; i < CircleList_Length(list); i++)
	{
		Teacher temp = (Teacher)CircleList_Get(list, i);
		if (temp == NULL)
		{
			printf("LinkList_Get Error...");
			return 0;
		}
		printf("teacher[%d] age:%d,name:%s;\n", i, temp->age, temp->name);
	}

	CircleList_Destroy(list);

	printf("finished...\n");
	getchar();
	return 0;
}