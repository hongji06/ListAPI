//´ÌªºÁå¦¡¦sÀx
#ifndef _LinkStack_H
#define _LinkStack_H
typedef void* LinkStack;

//create stack
LinkStack * LinkStack_Create();

//destroy stack
void LinkStack_Destroy(LinkStack* stack);

//clear stack
void LinkStack_Clear(LinkStack* stack);

//push
int LinkStack_Push(LinkStack* stack, void * item);

//pop
void* LinkStack_Pop(LinkStack* stack);

//top
void* LinkStack_Top(LinkStack* stack);

//get size of stack
int LinkStack_Size(LinkStack* stack);

#endif /* _List_H */
