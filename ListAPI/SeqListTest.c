#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include"seq_list.h"

typedef struct Teacher
{
	unsigned int age;
	char *name;
} *Teacher;

typedef struct Student
{
	unsigned int age;
	char *name;
	char *class;

} *Student;

int main1()
{
	//創建鍊錶
	SeqList *list = SeqList_Create(1);
	if (list == NULL)
	{
		printf("SeqList_Create Error...");
		return 0;
	}

	Teacher t1 = malloc(sizeof(struct Teacher)), t2 = malloc(sizeof(struct Teacher));
	Student s1 = malloc(sizeof(struct Student));

	memset(t1, 0, sizeof(t1));
	memset(t2, 0, sizeof(t2));
	memset(s1, 0, sizeof(s1));

	t1->age = 31;
	t1->name = "hello";

	t2->age = 32;
	t2->name = "world";

	s1->age = 7;
	s1->class = "class1";
	s1->name = "peqi";

	//向鍊錶pos位置插入數據
	SeqList_Insert(list, (SeqListNode*)t1, 0);
	SeqList_Insert(list, (SeqListNode*)t2, 0);
	SeqList_Insert(list, (SeqListNode*)s1, 0);

	//打印鍊錶的元素
	printf("鍊錶內容如下：\n");
	for (size_t i = 0; i < SeqList_Length(list); i++)
	{
		Teacher temp = (Teacher)SeqList_Get(list, i);
		if (temp == NULL)
		{
			printf("SeqList_Get Error...");
			return 0;
		}
		printf("teacher[%d] age:%d,name:%s;\n", i, temp->age, temp->name);
	}

	//從鍊錶pos位置刪除數據
	printf("鍊錶刪除如下：\n");
	while (SeqList_Length(list)>1)
	{
		Teacher temp = (Teacher)SeqList_Delte(list, 0);
		if (temp == NULL)
		{
			printf("SeqList_Delte Error...\n");
			return 0;
		}
		printf("delete node：%d,%s;\n", temp->age, temp->name);
	}

	//打印鍊錶的元素
	printf("鍊錶內容如下：\n");
	for (size_t i = 0; i < SeqList_Length(list); i++)
	{
		Teacher temp = (Teacher)SeqList_Get(list, i);
		if (temp == NULL)
		{
			printf("SeqList_Get Error...");
			return 0;
		}
		printf("teacher[%d] age:%d,name:%s;\n", i, temp->age, temp->name);
	}

	printf("finished...\n");
	getchar();
	return 0;
}