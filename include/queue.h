#ifndef _QUEUE_H
#define _QUEUE_H

struct QueueRecord;
typedef struct QueueRecord *Queue;
typedef int ElementType;

int Isempty(Queue Q);
int IsFull(Queue Q);
Queue CreateQueue(int MaxElements);
void DisposQueue(Queue Q);
void MakeEmpty(Queue Q);
void Enqueue(ElementType X, Queue Q);
ElementType Front(Queue Q);
void Dequeue(Queue Q);
ElementType FrontAndDequeue(Queue Q);

#endif // !DEBUG
