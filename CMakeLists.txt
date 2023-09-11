# 最低版本要求
cmake_minimum_required(VERSION 3.5)

# 项目名称
project(DSAAC)

# 导入src子目录， 类似 include
add_subdirectory(src)

# 导入 examples
add_subdirectory(examples)

# 导入测试
add_subdirectory(tests)
