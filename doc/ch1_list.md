# 链表
## 头文件预览

`list.h`
```C
#include <init.h>
#include <stdlib.h>
#ifndef _LINKED_LIST_H
struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

List MakeEmpty(List L);
int IsEmpty(List L);
int IsLast(Position P, List L);
Position find(ElementType X, List L);
void Delete(ElementType X, List L);
Position FindPrevious(ElementType X, List L);
void Insert(ElementType X, List L);
void DeleteList(List L);
Position Header(List L);
Position First(List L);
Position Advance(Position P);
ElementType Retrieve(Position P);

#endif
```

`list.c`
```C
#ifndef _INIT_H
#define _INIT_H
#define ElementType int

#endif // !_INIT__
```

## 实例化

判断链表是否为空
```C
int IsEmpty(List L) { return L->Next == NULL; }
```

传入链表头，当链表头没有指向任何数据就返回 `1`

-判断当前节点是否在链表尾部, L 参数没有使用， 在这里是为了说明是链表L的尾节点-
```C
int IsLast(Position P, List L) { return P->Next == NULL; }
```

代码依旧， 如果是在尾部的话， 那么就不应该有节点

**获取数据为 X 的前置节点** 
```C
Position FindPrevious(ElementType X, List L) {
  Position P;

  P = L;
  while (P->Next != NULL && P->Next->Element != X) {
    P = P->Next;
  }
  return P;
}
```

将链表头放置链表头中
- 当链表为空， 那么直接返回头节点
- 链表不为空，那么会看P指向的下一节点数据是否为 X, 如果是返回 P, ，否则继续迭代 P
- 根本没有数据 X, 那么就会返回尾节点

**删除数据为 X 的节点** 
```C
void Delete(ElementType X, List L) {
  Position P, TmpCell;

  P = FindPrevious(X, L);

  if (!IsLast(P, L)) {
    TmpCell = P->Next;
    P->Next = TmpCell->Next;
    free(TmpCell);
  }
}
```

先寻找前置节点
- 如果前置节点是链表最后的节点， 那么说明链表为空， 或者链表没有数据为 X 的节点
- 如果找到那么将前置节点指向后置节点， 并是否节点内存
