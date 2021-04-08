# 版本要求
cmake_minimum_required(VERSION 3.7.2)

# 项目名称
project(example)

# 将所有匹配到的源文件组成列表，存储在 SOURCE_FILES 变量
file(GLOB SOURCE_FILES "./*.h" "./*.cc")
# 项目添加动态链接库
add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES} ${CMAKE_JS_SRC})
# 目标包含头文件目录
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_JS_INC})
target_include_directories(${PROJECT_NAME} PRIVATE "../node_modules/nan")
# 目标链接其他库的目录
target_link_libraries(${PROJECT_NAME} ${CMAKE_JS_LIB})
# 目标设置前/后缀
set_target_properties(${PROJECT_NAME} PROPERTIES PREFIX "" SUFFIX ".node")