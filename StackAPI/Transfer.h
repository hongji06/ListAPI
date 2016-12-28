//棧的經典應用，中綴表達式轉後綴表達式
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