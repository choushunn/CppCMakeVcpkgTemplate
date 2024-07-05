# 指定最低要求的 CMake 版本
cmake_minimum_required(VERSION 3.5)

# 定义项目名称和版本
project(vcpkg_demo VERSION 0.1.0)

# 设置编译器标准为 C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


# 获取 ./src 目录下所有 cpp 文件
file(GLOB TARGET_SRC "./src/*.cpp" )

# 打印 VCPKG_INSTALLED_DIR 变量的值
message(STATUS ${VCPKG_INSTALLED_DIR})

# 设置 OpenCV_DIR 变量为 OpenCV 的安装路径
set(OpenCV_DIR "${VCPKG_INSTALLED_DIR}/x64-windows/share/opencv4")

# 查找并要求使用 OpenCV 包
find_package(OpenCV REQUIRED)

# 查找并要求使用配置好的 spdlog 包
find_package(spdlog CONFIG REQUIRED)

# 创建与项目名称相同的可执行目标
add_executable(${PROJECT_NAME} 
               ${TARGET_SRC})

# 将 spdlog 库以头文件形式链接到可执行目标
target_link_libraries(${PROJECT_NAME} PRIVATE spdlog::spdlog_header_only)

# 将 OpenCV 库链接到可执行目标
target_link_libraries(${PROJECT_NAME} PRIVATE ${OpenCV_LIBS})
# 设置输出目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# 添加编译定义
add_definitions(-DPROJECT_VERSION="${PROJECT_VERSION}")

# 添加安装目标
install(TARGETS ${PROJECT_NAME}
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib)

# # 启用单元测试
# enable_testing()
# add_subdirectory(tests)


# 设置 CPack 项目名称和版本
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

# 包含 CPack 模块以启用打包
include(CPack)