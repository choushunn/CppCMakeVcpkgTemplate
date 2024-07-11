project(sublibrary)

############################################################
# Create static library
############################################################
# 创建静态库目标,名称为 sublibrary-static
add_library(${PROJECT_NAME}-static  STATIC src/sublib1.cpp)
# 为静态库目标设置别名 sub::lib-static
add_library(sub::lib-static ALIAS ${PROJECT_NAME}-static)
# 设置静态库的公共头文件搜索路径
target_include_directories(${PROJECT_NAME}-static
    PUBLIC ${PROJECT_SOURCE_DIR}/include
)
# 设置静态库的输出名称为 sublibrary
set_target_properties(${PROJECT_NAME}-static
    PROPERTIES
        OUTPUT_NAME ${PROJECT_NAME} 
)

############################################################
# Create dynamic library
############################################################
# 创建动态库目标,名称为 sublibrary-shared
add_library(${PROJECT_NAME}-shared SHARED src/sublib1.cpp)
# 为动态库目标设置别名 sub::lib-shared
add_library(sub::lib-shared ALIAS ${PROJECT_NAME}-shared)
# 设置动态库的私有头文件搜索路径
target_include_directories(${PROJECT_NAME}-shared 
    PRIVATE ${PROJECT_SOURCE_DIR}/include
)
# 设置动态库的公共头文件和输出名称
set_target_properties(${PROJECT_NAME}-shared 
    PROPERTIES
        PUBLIC_HEADER ${PROJECT_SOURCE_DIR}/include/sublib1.h
        OUTPUT_NAME ${PROJECT_NAME} 
)