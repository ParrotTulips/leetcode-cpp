# LeetCode C++ Solutions

这是一个包含 LeetCode 题目 C++解决方案的项目，使用 Google Test (GTest) 进行单元测试。

## 依赖要求

- CMake 3.10+
- C++17 兼容的编译器
- Google Test (GTest)

## 安装 GTest

### macOS (使用 Homebrew)

```bash
brew install googletest
```

### Ubuntu/Debian

```bash
sudo apt-get install libgtest-dev
```

### 从源码编译

```bash
git clone https://github.com/google/googletest.git
cd googletest
mkdir build && cd build
cmake ..
make
sudo make install
```

## 构建项目

```bash
mkdir build
cd build
cmake ..
make
```

## 运行测试

```bash
# 运行所有测试
make test

# 运行特定测试
./bin/test_0001_two_sum
./bin/test_0002_add_two_numbers
```

## 项目结构

```
leetcode-cpp/
├── src/problems/          # 题目解决方案
│   ├── 0001_two_sum/
│   └── 0002_add_two_numbers/
├── tests/problems/        # 测试文件
│   ├── test_0001_two_sum.cpp
│   └── test_0002_add_two_numbers.cpp
└── CMakeLists.txt
```

## 添加新题目

1. 在 `src/problems/` 下创建新的题目目录
2. 实现解决方案
3. 在 `tests/problems/` 下创建对应的测试文件
4. 更新相应的 CMakeLists.txt 文件

## 测试框架

项目使用 Google Test (GTest) 作为测试框架，提供：

- 单元测试支持
- 测试夹具 (Test Fixtures)
- 参数化测试
- 基准测试支持
