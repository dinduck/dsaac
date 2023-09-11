#include <list.h>
#include <stdlib.h>

// 实例化
struct Node {
  ElementType Element;
  Position Next;
};

/*
 * @brief 判断链表是否为空
 */
int IsEmpty(List L) { return L->Next == NULL; }
/*
 * @brief 判断当前位置是否是链表的末尾
 */
int IsLast(Position P, List L) { return P->Next == NULL; }

/*
 * @brief 找到数据为 X 的节点, 没有返回NULL
 */
Position find(ElementType X, List L) {
  Position P;

  P = L->Next;
  while (P != NULL && P->Element != X)
    P = P->Next;
  return P;
}

/*
 * @brief 找到储存数据 X 节点的前置节点
 */
Position FindPrevious(ElementType X, List L) {
  Position P;

  P = L;
  while (P->Next != NULL && P->Next->Element != X) {
    P = P->Next;
  }
  return P;
}

/*
 * @brief 删除数据为 X 的节点
 */
void Delete(ElementType X, List L) {
  Position P, TmpCell;

  P = FindPrevious(X, L);

  if (!IsLast(P, L)) {
    TmpCell = P->Next;
    P->Next = TmpCell->Next;
    free(TmpCell);
  }
}

void Insert(ElementType X, List L, Position P) {
  Position TmpCell;

  TmpCell = malloc(sizeof(struct Node));
  if (!TmpCell) {
    exit(1);
  }

  TmpCell->Element = X;
  TmpCell->Next = P->Next;
  P->Next = TmpCell;
}

List DeleteList(List L) {
  if (L != NULL) {
    DeleteList(L->Next);
    free(L);
  }
  return NULL;
}
