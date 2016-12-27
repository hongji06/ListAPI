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
	//�Ы����
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

	//�V���pos��m���J�ƾ�
	DLinkList_Insert(list, (DLinkListNode*)t1, DLinkList_Length(list));
	DLinkList_Insert(list, (DLinkListNode*)t2, DLinkList_Length(list));
	DLinkList_Insert(list, (DLinkListNode*)t3, DLinkList_Length(list));
	DLinkList_Insert(list, (DLinkListNode*)t4, DLinkList_Length(list));
	DLinkList_Insert(list, (DLinkListNode*)t5, DLinkList_Length(list));

	//���L���������
	printf("������e�p�U�G\n");
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


	printf("�����e��Ы��V�����G\n");
	Teacher temp = (Teacher)DLinkList_Current(list);
	if (temp == NULL)
	{
		printf("DLinkList_Current Error...");
		return 0;
	}
	printf("teacher age:%d,name:%s;\n", temp->age, temp->name);

	printf("�����e��Щ��Ჾ�ʤ����G\n");
	DLinkList_Next(list);
	temp = (Teacher)DLinkList_Current(list);
	if (temp == NULL)
	{
		printf("DLinkList_Current Error...");
		return 0;
	}
	printf("teacher age:%d,name:%s;\n", temp->age, temp->name);

	printf("�����e��Щ��Ჾ�ʤ����G\n");
	DLinkList_Next(list);
	temp = (Teacher)DLinkList_Current(list);
	if (temp == NULL)
	{
		printf("DLinkList_Current Error...");
		return 0;
	}
	printf("teacher age:%d,name:%s;\n", temp->age, temp->name);

	printf("��Э��m����������Ĥ@�Ӥ����G\n");
	DLinkList_Reset(list);
	temp = (Teacher)DLinkList_Current(list);
	if (temp == NULL)
	{
		printf("DLinkList_Current Error...");
		return 0;
	}
	printf("teacher age:%d,name:%s;\n", temp->age, temp->name);

	printf("�����e��Щ��e���ʤ����G\n");
	DLinkList_Next(list);
	temp = (Teacher)DLinkList_Current(list);
	if (temp == NULL)
	{
		printf("DLinkList_Current Error...");
		return 0;
	}
	printf("teacher age:%d,name:%s;\n", temp->age, temp->name);	


	printf("�R����������Y�Ӽƾڤ����G\n"); 
	printf("teacher age:%d,name:%s;\n", temp->age, temp->name);
	temp = (Teacher)DLinkList_DeleteNode(list, (DLinkListNode *)(temp));
	if (temp == NULL)
	{
		printf("DLinkList_Current Error...");
		return 0;
	}
	printf("teacher age:%d,name:%s;\n", temp->age, temp->name);


	printf("������e�p�U�G\n");
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