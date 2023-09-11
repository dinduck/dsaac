#include <cursor.h>

struct Node {
  ElementType Element;
  Position Next;
};

struct Node CursorSpace[SpaceSize];
