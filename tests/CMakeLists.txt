include_directories(${DSAAC_SOURCE_DIR}/include)



# 链表测试
add_executable(test_list test_list.c)
target_link_libraries(test_list list)


