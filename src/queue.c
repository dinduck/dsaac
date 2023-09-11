#include <panic.h>
#include <queue.h>
#include <stdlib.h>
#include <string.h>
struct QueueRecord {
  int Capacity;
  int Front;
  int Rear;
  int Size;
  ElementType *Array;
};

static int Succ(int Value, Queue Q) {
  if (++Value == Q->Capacity) {
    Value = 0;
  }
  return Value;
}

int Isempty(Queue Q) { return Q->Size == 0; }
int IsFull(Queue Q) { return Q->Size == Q->Capacity; }
Queue CreateQueue(int MaxElements) {
  Queue TmpCell = malloc(sizeof(struct QueueRecord));
  memset(TmpCell, 0, sizeof(struct QueueRecord));
  TmpCell->Capacity = MaxElements;
  return TmpCell;
}
void DisposQueue(Queue Q) { free(Q); }
void MakeEmpty(Queue Q) {
  Q->Size = 0;
  Q->Front = 0;
  Q->Rear = 0;
}
void Enqueue(ElementType X, Queue Q) {
  if (IsFull(Q)) {
    Error("Full Queue");
  } else {
    Q->Size++;
    Q->Rear = Succ(Q->Rear, Q);
    Q->Array[Q->Rear] = X;
  }
}
ElementType Front(Queue Q);
void Dequeue(Queue Q) {
  ElementType TmpCell;
  if (IsFull(Q)) {
    Error("Full Queue");
  } else {
    TmpCell = Q->Array[Q->Front];
    Q->Size++;
    Q->Front = Succ(Q->Front, Q);
  }
}
ElementType FrontAndDequeue(Queue Q);
