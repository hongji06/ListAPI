//�̪��g�����ΡA�����F�������F��
#include "LinkList.h"
LinkList* transfer(char * str);
int isNumber(char ch);
int isOperator(char ch);
int isLevel(char ch);
int output(char ch);
int isParLeft(char ch);
int isParRight(char ch);

typedef struct ValueNode
{
	LinkListNode *node;
	void  *item;
}*ValueNode;