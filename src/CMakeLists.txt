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

# 队列
add_library(queue STATIC queue.c)

# 树
add_library(tree STATIC tree.c)

# 二叉树
add_library(binarytree STATIC binarytree.c)

# 二叉搜索树
add_library(adtree STATIC adtree.c)

# 二叉平衡树
add_library(avltree STATIC avltree.c)

# 分离链接散列
add_library(hashsep STATIC hashtable.c)
