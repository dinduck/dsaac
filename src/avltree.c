#include <avltree.h>
#include <panic.h>
#include <stdlib.h>

struct AvlNode {
  ElementType Element;
  AvlTree Left;
  AvlTree Right;
  int Heigh;
};

/* Height Begin */
static int Heigh(Position P) {
  if (!P)
    return -1;
  else
    return P->Heigh;
}
/* Height End */

/* Max Begin */
int Max(int x, int y) { return x > y ? x : y; }

/* Code for Rota Begin */
static Position SingleRotateWithLeft(Position K2) {
  Position K1;

  K1 = K2->Left;
  K2->Left = K1->Right;
  K1->Right = K2;

  K2->Heigh = Max(Heigh(K2->Left), Heigh(K2->Right)) + 1;
  K1->Heigh = Max(Heigh(K1->Left), Heigh(K1->Right)) + 1;

  return K1; /* new root */
}
static Position DoubleRotateWithLeft(Position K3) {
  /* Rotate between K1 and K2 */
  K3->Left = SingleRotateWithLeft(K3->Left);

  /* Rotate between K3 and K2 */
  return SingleRotateWithLeft(K3);
}

AvlTree MakeEmpty(AvlTree T) {
  if (T != NULL) {
    MakeEmpty(T->Left);
    MakeEmpty(T->Right);
    free(T);
  }
  return NULL;
}
Position Find(ElementType X, AvlTree T) {
  if (T == NULL)
    return NULL;
  if (X < T->Element)
    return Find(X, T->Left);
  else if (X > T->Element)
    return Find(X, T->Right);
  else
    return T;
}
Position FindMin(AvlTree T) {
  if (T == NULL)
    return NULL;
  else if (T->Left == NULL)
    return T;
  else
    return FindMin(T->Left);
}
Position FindMax(AvlTree T) {
  if (T != NULL) {
    while (T->Right != NULL) {
      T = T->Right;
    }
  }
  return T;
}
AvlTree Insert(ElementType X, AvlTree T) {
  if (T == NULL) {
    T = malloc(sizeof(struct AvlNode));

    if (T == NULL) {
      Panic("Out of space!!!");
    } else {
      T->Element = X;
      T->Heigh = 0;
      T->Left = T->Right = NULL;
    }
  } else if (X < T->Element) {
    T->Left = Insert(X, T->Left);
    if (Heigh(T->Left) - Heigh(T->Right) == 2) {
      if (X < T->Left->Element)
        T = SingleRotateWithLeft(T);
      else
        T = DoubleRotateWithLeft(T);
    }
  } else if (X > T->Element) {
    T->Right = Insert(X, T->Right);
    if (Heigh(T->Right) - Heigh(T->Left) == 2) {
      if (X > T->Right->Element)
        T = SingleRotateWithLeft(T);
      else
        T = DoubleRotateWithLeft(T);
    }
  }

  T->Heigh = Max(Heigh(T->Left), Heigh(T->Right)) + 1;
  return T;
}
AvlTree Delete(ElementType X, AvlTree T);
ElementType Retrieve(Position P);
