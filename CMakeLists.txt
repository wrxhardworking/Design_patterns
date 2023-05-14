cmake_minimum_required(VERSION 3.25)
project(designMode)
set(CMAKE_CXX_STANDARD 17)
#GLOB是一个文件名通配符扩展命令用于指定通配符搜索文件并将其列表保存到变量中
file(GLOB SRC ${PROJECT_SOURCE_DIR}/src/*.cpp ${PROJECT_SOURCE_DIR}/src/*.hpp)
#将SRC作为为库的源代码文件
add_library(${PROJECT_NAME} ${SRC})
#将目录添加到库的头文件搜索路径中
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/src)

#因此，这行代码的作用是定义一个名为 ENABLE_TEST 的选项，用于控制是否启用测试，
#并将其默认值设置为启用。在 CMakeLists.txt 文件中，开发人员可以使用 if(ENABLE_TEST)
#这样的语句来判断用户是否启用了测试。
option(ENABLE_TEST "enable test" ON)

if(ENABLE_TEST)
  add_subdirectory(${PROJECT_SOURCE_DIR}/test)
endif ()
