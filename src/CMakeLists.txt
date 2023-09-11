include_directories(${DSAAC_SOURCE_DIR}/include)

# 链表库
add_library(list STATIC
  list.c)

# 游标链表
add_library(cursor STATIC cursor.c)

# 栈 By 链表 
add_library(stackl STATIC stackl.c)

# 栈 By 数组
add_library(stacka STATIC stacka.c)


