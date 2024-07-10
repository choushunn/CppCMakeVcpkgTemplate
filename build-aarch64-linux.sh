set -e

# 交叉编译设置
CROSS_COMPILE="$1"
if [ "$CROSS_COMPILE" == "aarch64" ]; then
    CROSS_COMPILE=1
    GCC_COMPILER=/opt/toolchain/aarch64-rockchip1031-linux-gnu/bin/aarch64-none-linux-gnu
    export CC=${GCC_COMPILER}-gcc
    export CXX=${GCC_COMPILER}-g++
fi

ROOT_PWD=$( cd "$( dirname $0 )" && cd -P "$( dirname "$SOURCE" )" && pwd )

# 构建目录
BUILD_DIR=${ROOT_PWD}/build
if [ ! -d "${BUILD_DIR}" ]; then
  mkdir -p ${BUILD_DIR}
fi

cd ${BUILD_DIR}

# 配置和构建
if [ "$CROSS_COMPILE" == "aarch64" ]; then
    cmake -DCMAKE_SYSTEM_NAME=Linux -DCMAKE_SYSTEM_PROCESSOR=aarch64 -DCMAKE_INSTALL_PREFIX=./install ..
else
    cmake -DCMAKE_INSTALL_PREFIX=./install ..
fi

make -j${nproc}
make install
cd -