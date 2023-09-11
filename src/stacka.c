#include "panic.h"
#include <stacka.h>
#include <stdlib.h>

struct StackRecord {
  int Capacity;
  int TopOfStack;
  ElementType *Array;
};

int IsEmpty(Stack S) { return S->TopOfStack == EmptyTOS; }
int IsFull(Stack S) { return S->TopOfStack == S->Capacity; }
Stack CreateStack(int MaxElements) {
  Stack S;

  if (MaxElements < MinStackSize)
    Error("Stack size is too small");

  S = malloc(sizeof(struct StackRecord));
  if (!S) {
    Panic("Out of space!!!");
  }
  S->Capacity = MaxElements;
  MakeEmpty(S);

  return S;
}
void DisposeStack(Stack S) {
  if (S) {
    free(S->Array);
    free(S);
  }
}
void MakeEmpty(Stack S) { S->TopOfStack = EmptyTOS; }
// 和书本不同， 选择 TopOfStack 为新节点的索引
void Push(ElementType X, Stack S) {
  if (IsFull(S)) {
    Error("Full Stack");
  } else {
    S->Array[S->TopOfStack++] = X;
  }
}
ElementType Top(Stack S) {
  if (!IsEmpty(S))
    return S->Array[S->TopOfStack - 1];
  Error("Empty stack");
  return 0;
}

void Pop(Stack S) {
  if (IsEmpty(S))
    Error("Empty stack");
  else
    S->TopOfStack--;
}
ElementType TopAndPop(Stack S) {
  if (!IsEmpty(S))
    return S->Array[S->TopOfStack--];
  Error("Empty stack");
  return 0;
}
