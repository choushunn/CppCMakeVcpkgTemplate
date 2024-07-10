## Visual Studio 运行 CPP
CMakeLists.txt
include("C:/Programs/vcpkg/scripts/buildsystems/vcpkg.cmake")

CMakePresets.json 
"toolchainFile": "c:/programs/vcpkg/scripts/buildsystems/vcpkg.cmake"

## VSCODE 运行 CPP
### VSCODE 插件
- C/C++
- CMake
- CMake Tools
### VSCODE 配置
- launch.json   # 配置 VS Code 的调试行为
- settings.json # 用于保存 VS Code 的用户设置
- task.json     # 定义 VS Code 的任务runner,包括编译、构建、测试等常见的任务。
- vcpkg.json    # 管理 C++ 项目的依赖库,让 vcpkg 自动下载、构建和链接这些库。
- CMakePresets.json  # 配置 CMake 构建系统的行为,定义构建目标、配置参数、环境变量等。
- .clang-format # 
>
### VSCODE
- https://code.visualstudio.com/Download
### CMake
- https://cmake.org/documentation/
### VCPKG
- https://vcpkg.link/search
- https://github.com/microsoft/vcpkg
- https://vcpkg.io/en/index.html

## C++ 项目目录结构
### C++ 项目编译静态库/动态库
# 设置临时环境变量
export LD_LIBRARY_PATH=$(pwd)/lib:$LD_LIBRARY_PATH

## C++ 常用库简介
### OpenCV

### Qt

### Boost

### libevent