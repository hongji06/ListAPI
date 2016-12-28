//棧的線性存儲
#ifndef _SeqStack_H
#define _SeqStack_H
typedef void SeqStack;

//create stack
SeqStack * SeqStack_Create(int capacity);

//destroy stack
void SeqStack_Destroy(SeqStack* stack);

//clear stack
void SeqStack_Clear(SeqStack* stack);

//push
int SeqStack_Push(SeqStack* stack, void * item);

//pop
void* SeqStack_Pop(SeqStack* stack);

//top
void* SeqStack_Top(SeqStack* stack);

//get size of stack
int SeqStack_Size(SeqStack* stack);

//get capacity of stack
int SeqStack_Capacity(SeqStack* stack);

#endif /* _List_H */