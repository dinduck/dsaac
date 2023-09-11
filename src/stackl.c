#include "panic.h"
#include <stackl.h>
#include <stdlib.h>

struct Node {
  ElementType Element;
  PtrToNode Next;
};

int IsEmpty(Stack S) { return S->Next == NULL; }

Stack CreateStack() {
  Stack S;

  S = malloc(sizeof(struct Node));
  if (!S) {
    exit(1);
  }
  S->Next = NULL;
  MakeEmpty(S);
  return S;
}

void MakeEmpty(Stack S) {
  if (!S) {
    exit(1);
  } else {
    while (!IsEmpty(S)) {
      Pop(S);
    }
  }
}

void Push(ElementType X, Stack S) {
  PtrToNode TmpCell;

  TmpCell = malloc(sizeof(struct Node));
  if (!TmpCell) {
    exit(1);
  } else {
    TmpCell->Element = X;
    TmpCell->Next = S->Next;
    S->Next = TmpCell;
  }
}

ElementType Top(Stack S) {
  if (!IsEmpty(S)) {
    return S->Next->Element;
  }
  return 0;
}

void Pop(Stack S) {
  PtrToNode FirstCell;

  if (IsEmpty(S)) {
    Error("Stack is empty");
  } else {
    FirstCell = S->Next;
    S->Next = S->Next->Next;
    free(FirstCell);
  }
}
