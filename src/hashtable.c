#include <hashtable.h>
#include <panic.h>

struct ListNode {
  ElementType Element;
  Position Next;
};

typedef Position List;

struct HashTbl {
  int TableSize;
  List *TheLists;
};

HashTable InitializeTable(int TableSize) {
  HashTable H;
  int i;

  if (TableSize < MinTableSize) {
    Error("TableSize is too small");
    return NULL;
  }

  H = malloc(sizeof(struct HashTbl));
  if (!H) {
    Panic("Out of space!!!");
  }

  H->TableSize = TableSize;

  H->TheLists = malloc(sizeof(List) * H->TableSize);

  if (!H->TheLists) {
    Panic("Out of spaces!!!");
  }
  for (i = 0; i < H->TableSize; i++) {
    H->TheLists[i] = malloc(sizeof(struct ListNode));
    if (!H->TheLists[i]) {
      Panic("Out of space!!!");
    } else {
      H->TheLists[i]->Next = NULL;
    }
  }
  return H;
}
