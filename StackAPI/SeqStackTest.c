#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include"SeqStack.h"

typedef struct Teacher
{
	unsigned int age;
	char *name;
} *Teacher;

int main_SeqStackTest()
{

	Teacher t1 = malloc(sizeof(struct Teacher)), t2 = malloc(sizeof(struct Teacher)), t3 = malloc(sizeof(struct Teacher)), t4 = malloc(sizeof(struct Teacher)), t5 = malloc(sizeof(struct Teacher));

	memset(t1, 0, sizeof(t1));
	memset(t2, 0, sizeof(t2));
	memset(t3, 0, sizeof(t3));
	memset(t4, 0, sizeof(t4));
	memset(t5, 0, sizeof(t5));

	t1->age = 1;
	t2->age = 2;
	t3->age = 3;
	t4->age = 4;
	t5->age = 5;
	t1->name = "name1";
	t2->name = "name12";
	t3->name = "name13";
	t4->name = "name14";
	t5->name = "name15";

	//create stack
	SeqStack * stack = SeqStack_Create(2);
	if (stack == NULL)
	{
		printf("create seq stack err");
	}

	SeqStack_Push(stack, (SeqStack)t1);
	SeqStack_Push(stack, (SeqStack)t2);
	SeqStack_Push(stack, (SeqStack)t3);


	printf("stack size is :%d\n", SeqStack_Size(stack));

	Teacher tempTeacher = (Teacher)SeqStack_Top(stack);
	printf("top of stack is :%d,%s\n", tempTeacher->age, tempTeacher->name);

	tempTeacher = (Teacher)SeqStack_Pop(stack);
	printf("Pop of stack is :%d,%s\n", tempTeacher->age, tempTeacher->name);

	tempTeacher = (Teacher)SeqStack_Top(stack);
	printf("top of stack is :%d,%s\n", tempTeacher->age, tempTeacher->name);

	printf("stack size is :%d\n", SeqStack_Size(stack));

	//destroy stack
	SeqStack_Destroy(stack);

	getchar();

	return 0;
}