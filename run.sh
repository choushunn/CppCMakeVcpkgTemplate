#!/bin/bash
set -e

# 设置临时环境变量
export LD_LIBRARY_PATH=$(pwd)/lib:$LD_LIBRARY_PATH

# 检查参数数量
if [ "$#" -ne 1 ]; then
    echo "Usage: $0 <video_path>"
    exit 1
fi

# 获取参数
video_path="$1"

./main "$video_path"