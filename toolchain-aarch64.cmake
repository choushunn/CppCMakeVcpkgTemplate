# 设置目标系统架构
set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR aarch64)

# 指定交叉编译工具链的安装路径
set(TOOLCHAIN_PREFIX /opt/toolchain/aarch64-rockchip1031-linux-gnu)

# 设置 C 和 C++ 编译器
set(CMAKE_C_COMPILER ${TOOLCHAIN_PREFIX}/bin/aarch64-none-linux-gnu-gcc )
set(CMAKE_CXX_COMPILER ${TOOLCHAIN_PREFIX}/bin/aarch64-none-linux-gnu-g++ )

# 设置其他工具
set(CMAKE_FIND_ROOT_PATH ${TOOLCHAIN_PREFIX})
#set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
#set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
#set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

# 设置 sysroot 目录
#set(CMAKE_SYSROOT "${TOOLCHAIN_PREFIX}/aarch64-none-linux-gnu/sysroot")

# 配置 CMake 搜索路径
#list(APPEND CMAKE_PREFIX_PATH "${TOOLCHAIN_PREFIX}/aarch64-none-linux-gnu/sysroot/usr")

# 其他编译选项
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -lc -lm -lpthread -ldl")
