# 从 Catch2 迁移到 GTest 的说明

本文档详细说明了如何将 LeetCode C++项目的测试框架从 Catch2 迁移到 Google Test (GTest)。

## 主要变化

### 1. 测试宏的转换

#### Catch2 语法 → GTest 语法

```cpp
// Catch2
TEST_CASE("test name", "[tag]") {
    SECTION("subsection") {
        REQUIRE(condition);
    }
}

// GTest
TEST(TestSuiteName, TestName) {
    EXPECT_TRUE(condition);
}
```

#### 测试夹具 (Test Fixtures)

```cpp
// Catch2
TEST_CASE("test with setup", "[tag]") {
    Solution sol;
    // test code...
}

// GTest
class TestSuiteName : public ::testing::Test {
protected:
    Solution sol;
};

TEST_F(TestSuiteName, TestName) {
    // test code...
}
```

### 2. 断言宏的转换

| Catch2                   | GTest                    | 说明         |
| ------------------------ | ------------------------ | ------------ |
| `REQUIRE(condition)`     | `EXPECT_TRUE(condition)` | 期望条件为真 |
| `REQUIRE(expr == value)` | `EXPECT_EQ(expr, value)` | 期望相等     |
| `REQUIRE(expr != value)` | `EXPECT_NE(expr, value)` | 期望不相等   |
| `REQUIRE(expr > value)`  | `EXPECT_GT(expr, value)` | 期望大于     |
| `REQUIRE(expr < value)`  | `EXPECT_LT(expr, value)` | 期望小于     |
| `REQUIRE(expr >= value)` | `EXPECT_GE(expr, value)` | 期望大于等于 |
| `REQUIRE(expr <= value)` | `EXPECT_LE(expr, value)` | 期望小于等于 |

### 3. 基准测试的转换

#### Catch2 基准测试

```cpp
BENCHMARK("benchmark name") {
    return function_to_benchmark();
};
```

#### GTest 基准测试

```cpp
// 使用标准库的chrono进行手动基准测试
auto start = std::chrono::high_resolution_clock::now();
for (int i = 0; i < iterations; ++i) {
    function_to_benchmark();
}
auto end = std::chrono::high_resolution_clock::now();
auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
```

## 文件修改详情

### CMakeLists.txt

- 移除了 `FetchContent` 和 Catch2 相关配置
- 添加了 GTest 的 `FetchContent` 配置
- 使用 `gtest_main` 目标链接测试

### tests/problems/CMakeLists.txt

- 简化了测试发现和注册逻辑
- 移除了 Catch2 特定的 `catch_discover_tests`
- 使用标准的 `add_test` 和 `ctest`

### 测试文件

- `test_0001_two_sum.cpp`: 转换为 GTest 语法，包含基本测试和基准测试
- `test_0002_add_two_numbers.cpp`: 转换为 GTest 语法，包含基本测试

## 构建和运行

### 自动构建

```bash
./build.sh  # Linux/macOS
build.bat   # Windows
```

### 手动构建

```bash
mkdir build
cd build
cmake ..
cmake --build . --parallel
ctest --output-on-failure
```

### 运行特定测试

```bash
./build/bin/test_0001_two_sum
./build/bin/test_0002_add_two_numbers
```

## 优势

1. **更广泛的支持**: GTest 是 Google 开发的测试框架，在更多平台上得到支持
2. **更好的集成**: 与 CMake、IDE 等工具集成更好
3. **更丰富的功能**: 提供参数化测试、类型参数化测试等高级功能
4. **更好的文档**: 有更完善的官方文档和社区支持

## 注意事项

1. **基准测试**: GTest 本身不提供内置的基准测试功能，需要使用第三方库如 Google Benchmark 或手动实现
2. **测试发现**: GTest 的测试发现机制与 Catch2 不同，需要适应新的测试组织结构
3. **断言语义**: 某些断言宏的行为可能略有不同，需要仔细测试

## 未来改进

1. 集成 Google Benchmark 进行更专业的基准测试
2. 添加参数化测试用例
3. 实现测试覆盖率报告
4. 添加性能回归测试
