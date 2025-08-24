#!/bin/bash

# LeetCode C++ 项目构建脚本

echo "开始构建 LeetCode C++ 项目..."

# 创建构建目录
mkdir -p build
cd build

# 配置项目
echo "配置项目..."
cmake ..

# 检测构建工具并构建项目
echo "构建项目..."
if command -v ninja &> /dev/null; then
    echo "使用 Ninja 构建..."
    ninja
elif command -v make &> /dev/null; then
    echo "使用 Make 构建..."
    make -j$(nproc 2>/dev/null || sysctl -n hw.ncpu 2>/dev/null || echo 4)
else
    echo "使用 CMake 构建..."
    cmake --build . --parallel
fi

# 运行测试
echo "运行测试..."
ctest --output-on-failure

echo "构建完成！"
echo "可执行文件位于: build/bin/"
echo "测试文件位于: build/bin/test_*"
