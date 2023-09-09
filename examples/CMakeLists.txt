# 链接 ds 库
link_libraries(ds)

# 头文件目录设定
include_directories(${DSAAC_SOURCE_DIR}/include)



# 添加执行文件
add_executable(lists lists.c)
