# 头文件目录设定
include_directories(${DSAAC_SOURCE_DIR}/include)



# 链表测试
add_executable(test_list lists.c)
target_link_libraries(test_list list)

# 游标链表
add_executable(test_cursor cursor.c)
target_link_libraries(test_cursor cursor)
