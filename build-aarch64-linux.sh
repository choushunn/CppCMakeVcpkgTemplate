set -e

# 交叉编译
 #GCC_COMPILER=/usr/local/arm64/gcc-arm-10.3-2021.07-x86_64-aarch64-none-linux-gnu/bin/aarch64-none-linux-gnu

#GCC_COMPILER=/opt/toolchain/aarch64-rockchip1031-linux-gnu/bin/aarch64-none-linux-gnu

#export CC=${GCC_COMPILER}-gcc
#export CXX=${GCC_COMPILER}-g++

ROOT_PWD=$( cd "$( dirname $0 )" && cd -P "$( dirname "$SOURCE" )" && pwd )

# build
BUILD_DIR=${ROOT_PWD}/build

if [ ! -d "${BUILD_DIR}" ]; then
  mkdir -p ${BUILD_DIR}
fi

cd ${BUILD_DIR}

cmake ../ -DCMAKE_SYSTEM_NAME=Linux
make -j8

make install
cd -


