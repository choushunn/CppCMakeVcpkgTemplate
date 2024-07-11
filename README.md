[TOC]
## 编译运行 CPP 项目

### 常用工具

Visual Studio

- https://visualstudio.microsoft.com/

VSCODE

- https://code.visualstudio.com/Download

CMake

- https://cmake.org/documentation/

VCPKG

- https://vcpkg.link/search
- https://github.com/microsoft/vcpkg
- https://vcpkg.io/en/index.html

make

- https://www.gnu.org/software/make/

ninja

- https://ninja-build.org/

### Visual Studio 配置

方式一：

```cmake
# 添加到 CMakeLists.txt 文件中
include("C:/Programs/vcpkg/scripts/buildsystems/vcpkg.cmake")
```

方式二：

```json
// 添加到 CMakePresets.json 文件中
"toolchainFile": "c:/programs/vcpkg/scripts/buildsystems/vcpkg.cmake"
```

### VSCODE  配置
#### VSCODE 插件
- C/C++
- CMake
- CMake Tools
#### VSCODE 配置
- launch.json   # 配置 VS Code 的调试行为
- settings.json # 用于保存 VS Code 的用户设置
- task.json     # 定义 VS Code 的任务runner,包括编译、构建、测试等常见的任务。
- vcpkg.json    # 管理 C++ 项目的依赖库,让 vcpkg 自动下载、构建和链接这些库。
- CMakePresets.json  # 配置 CMake 构建系统的行为,定义构建目标、配置参数、环境变量等。
- .clang-format # 

### C++ 项目目录结构

```yaml
project
- src
- include
- sublibrary
- main.cpp
- CMakeLists.txt
```



### Linux 编译运行 C++ 项目

1. 设置临时环境变量

```bash
export LD_LIBRARY_PATH=$(pwd)/lib:$LD_LIBRARY_PATH
```



### C++ 常用库

- [OpenCV](https://opencv.org)

- [Qt](https://www.qt.io/zh-cn)

- [Boost](https://www.boost.org)

- [libevent](https://libevent.org)

- [CMake](https://cmake.org/)

------

