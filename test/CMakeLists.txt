file(GLOB TEST_FILES ./*_test.cpp)

foreach (path ${TEST_FILES})
#    获取文件的名字
    message(${path})
    get_filename_component(target_name ${path} NAME_WLE)
    add_executable(${target_name} ${path})
    target_link_libraries(${target_name} ${PROJECT_NAME})
endforeach ()


