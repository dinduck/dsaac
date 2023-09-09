# 添加库
add_library(ds SHARED 
  list.c)

# 头文件目录 DSAAC 我们项目的主名称是 dsaac 这里大写 表示 dsaac 项目源文件路径
target_include_directories(ds PUBLIC ${DSAAC_SOURCE_DIR}/include)

