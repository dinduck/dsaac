#ifndef _STACKA_H
#define MinStackSize 16
#define EmptyTOS 0
struct StackRecord;
typedef struct StackRecord *Stack;
typedef int ElementType;

int IsEmpty(Stack S);
int IsFull(Stack S);
Stack CreateStack(int MaxElements);
void DisposeStack(Stack S);
void MakeEmpty(Stack S);
void Push(ElementType X, Stack S);
ElementType Top(Stack S);
void Pop(Stack);
ElementType TopAndPop(Stack S);

#endif // DEBUG
