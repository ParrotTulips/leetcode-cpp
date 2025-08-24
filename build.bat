@echo off
REM LeetCode C++ 项目构建脚本 (Windows)

echo 开始构建 LeetCode C++ 项目...

REM 创建构建目录
if not exist build mkdir build
cd build

REM 配置项目
echo 配置项目...
cmake ..

REM 构建项目
echo 构建项目...
cmake --build . --config Release

REM 运行测试
echo 运行测试...
ctest --output-on-failure

echo 构建完成！
echo 可执行文件位于: build\bin\Release\
echo 测试文件位于: build\bin\Release\test_*.exe

pause
