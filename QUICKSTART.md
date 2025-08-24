# 快速开始指南

## 环境要求

- **操作系统**: Linux, macOS, Windows
- **编译器**: 支持 C++17 的编译器 (GCC 7+, Clang 5+, MSVC 2017+)
- **构建工具**: CMake 3.10+
- **依赖**: 无需预先安装，项目会自动下载 GTest

## 快速构建

### 1. 克隆项目

```bash
git clone <your-repo-url>
cd leetcode-cpp
```

### 2. 一键构建

```bash
# Linux/macOS
./build.sh

# Windows
build.bat
```

### 3. 运行测试

```bash
# 运行所有测试
cd build
ctest --output-on-failure

# 运行特定测试
./bin/test_0001_two_sum
./bin/test_0002_add_two_numbers
```

## 项目结构

```
leetcode-cpp/
├── src/problems/          # 题目解决方案
│   ├── 0001_two_sum/     # 两数之和
│   └── 0002_add_two_numbers/  # 两数相加
├── tests/problems/        # 测试文件
├── CMakeLists.txt         # 主构建配置
├── build.sh               # Linux/macOS构建脚本
├── build.bat              # Windows构建脚本
└── README.md              # 项目说明
```

## 添加新题目

### 1. 创建解决方案

```bash
mkdir src/problems/0003_longest_substring
```

在 `src/problems/0003_longest_substring/` 下创建：

- `solution.hpp` - 头文件
- `solution.cpp` - 实现文件
- `CMakeLists.txt` - 构建配置

### 2. 创建测试

```bash
# 复制现有测试文件作为模板
cp tests/problems/test_0001_two_sum.cpp tests/problems/test_0003_longest_substring.cpp
```

修改测试文件，使用 GTest 语法编写测试用例。

### 3. 重新构建

```bash
./build.sh
```

## 常用命令

```bash
# 清理构建
rm -rf build/

# 重新配置
cd build && cmake .. && cd ..

# 只构建特定目标
cd build && cmake --build . --target test_0001_two_sum

# 运行测试并显示详细输出
cd build && ctest --verbose
```

## 故障排除

### 构建失败

1. 检查 CMake 版本: `cmake --version`
2. 检查编译器: `g++ --version` 或 `clang++ --version`
3. 清理构建目录: `rm -rf build/`

### 测试失败

1. 检查测试输出: `ctest --output-on-failure`
2. 单独运行测试: `./bin/test_0001_two_sum`
3. 检查测试代码语法

### 依赖问题

1. 项目使用 FetchContent 自动下载 GTest
2. 确保网络连接正常
3. 如果下载失败，可以手动安装 GTest

## 下一步

- 阅读 [MIGRATION_NOTES.md](MIGRATION_NOTES.md) 了解从 Catch2 到 GTest 的迁移详情
- 查看 [README.md](README.md) 获取完整项目信息
- 开始解决 LeetCode 题目并添加测试用例
