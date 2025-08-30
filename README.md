# LeetCode C++ Solutions

A comprehensive collection of LeetCode problem solutions implemented in C++ with Google Test (GTest) for unit testing and benchmarking.

## 🚀 Features

- **Modern C++20**: Uses the latest C++ standard for optimal performance and modern language features
- **Comprehensive Testing**: Google Test framework with unit tests and performance benchmarks
- **CMake Build System**: Cross-platform build configuration with Ninja generator support
- **Performance Analysis**: Built-in benchmarking capabilities for algorithm performance evaluation
- **Clean Architecture**: Well-organized project structure with separation of concerns

## 📋 Requirements

- **CMake**: 4.0 or higher
- **C++ Compiler**: C++20 compatible compiler (Clang, GCC, or MSVC)
- **Git**: For downloading Google Test automatically
- **Ninja** (optional): For faster builds

## 🛠️ Installation

### Google Test Installation

The project uses the following configuration in `tests/problems/CMakeLists.txt`:

```cmake
include(FetchContent)

FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG main
)
FetchContent_MakeAvailable(googletest)
```

This means Google Test will be:

- Automatically downloaded from GitHub during the first build
- Configured and built as part of your project
- Available for all tests without manual installation

### Installing Ninja (optional)

```bash
# macOS
brew install ninja

# Ubuntu/Debian
sudo apt-get install ninja-build
```

## 🏗️ Building the Project

### Using CMake Presets (Recommended)

The project includes a `CMakePresets.json` file that defines build configurations for different environments. Here's an example configuration:

```json
{
  "version": 8,
  "configurePresets": [
    {
      "name": "release",
      "displayName": "Clang 21.1.0 (brew llvm) arm64-apple-darwin",
      "description": "Using Compiler: C = /opt/homebrew/opt/llvm/bin/clang, CXX = /opt/homebrew/opt/llvm/bin/clang++",
      "generator": "Ninja",
      "binaryDir": "${sourceDir}/build",
      "cacheVariables": {
        "CMAKE_INSTALL_PREFIX": "${sourceDir}/out/install/${presetName}",
        "CMAKE_C_COMPILER": "/opt/homebrew/opt/llvm/bin/clang",
        "CMAKE_CXX_COMPILER": "/opt/homebrew/opt/llvm/bin/clang++",
        "CMAKE_BUILD_TYPE": "Debug",
        "CMAKE_OSX_SYSROOT": "macosx",
        "CMAKE_EXPORT_COMPILE_COMMANDS": "ON",
        "CMAKE_EXE_LINKER_FLAGS": "-L/opt/homebrew/opt/llvm/lib/c++ -L/opt/homebrew/opt/llvm/lib/unwind -lunwind",
        "CMAKE_SHARED_LINKER_FLAGS": "-L/opt/homebrew/opt/llvm/lib/c++ -L/opt/homebrew/opt/llvm/lib/unwind -lunwind",
        "CMAKE_CXX_FLAGS": "-I/opt/homebrew/opt/llvm/include",
        "CMAKE_C_FLAGS": "-I/opt/homebrew/opt/llvm/include"
      },
      "environment": {
        "NINJA_STATUS": "[%f/%t %p :: %e] "
      }
    }
  ]
}
```

**Note**: The above configuration is specific to macOS with Homebrew-installed LLVM. You may need to adjust paths and compiler settings for your specific environment.

```bash
# Configure with release preset
cmake --preset release

# Build the project
cmake --build build
```

### Manual Build

```bash
mkdir build
cd build
cmake ..
cmake --build .
```

## 🧪 Running Tests

### Run All Tests

```bash
cd build
ctest --output-on-failure
```

### Run Specific Test

```bash
# Run Two Sum test
./bin/test_0001_two_sum

# Run Add Two Numbers test
./bin/test_0002_add_two_numbers

# Run Longest Substring Without Repeating Characters test
./bin/test_0003_length_of_longest_substring
```

### Run Tests with Verbose Output

```bash
cd build
ctest --verbose
```

## 📁 Project Structure

```
leetcode-cpp/
├── src/
│   └── problems/              # Problem solutions
│       ├── 0001_two_sum/
│       │   ├── solution.hpp   # Header file
│       │   ├── solution.cpp   # Implementation
│       │   └── CMakeLists.txt # Build configuration
│       ├── 0002_add_two_numbers/
│       └── 0003_length_of_longest_substring/
├── tests/
│   └── problems/              # Test files
│       ├── test_0001_two_sum.cpp
│       ├── test_0002_add_two_numbers.cpp
│       └── test_0003_length_of_longest_substring.cpp
├── include/                   # Common headers
├── build/                     # Build artifacts
├── CMakeLists.txt            # Main build configuration
├── CMakePresets.json         # Build presets (see example above)
└── README.md                 # This file
```

## 📝 Adding New Problems

1. **Create Problem Directory**:

   ```bash
   mkdir src/problems/XXXX_problem_name
   ```

2. **Create Solution Files**:

   - `solution.hpp`: Class declaration
   - `solution.cpp`: Implementation
   - `CMakeLists.txt`: Build configuration

3. **Create Test File**:

   ```bash
   touch tests/problems/test_XXXX_problem_name.cpp
   ```

4. **Example Solution Structure**:

   ```cpp
   // solution.hpp
   #pragma once
   #include <vector>

   class Solution {
   public:
       std::vector<int> solve(std::vector<int>& input);
   };
   ```

## 🧪 Testing Framework

This project uses Google Test (GTest) which provides:

- **Unit Testing**: Basic functionality testing
- **Test Fixtures**: Reusable test setup and teardown
- **Parameterized Tests**: Testing with multiple input sets
- **Benchmarking**: Performance measurement capabilities
- **Test Discovery**: Automatic test discovery and execution

### Example Test Structure

```cpp
#include <gtest/gtest.h>
#include "../../src/problems/XXXX_problem_name/solution.hpp"

class ProblemTest : public ::testing::Test {
protected:
    Solution sol;
};

TEST_F(ProblemTest, BasicCases) {
    // Test basic functionality
    std::vector<int> input = {1, 2, 3};
    auto result = sol.solve(input);
    EXPECT_EQ(result, std::vector<int>({expected}));
}
```

## 🔧 Development Setup

### IDE Configuration

#### Visual Studio Code

- Install C/C++ extension
- Configure `compile_commands.json` for IntelliSense
- Use CMake Tools extension for build integration

#### CLion

- Open project as CMake project
- Configure Google Test framework
- Enable code analysis and refactoring

### Debugging

```bash
# Build with debug symbols
cmake --preset release -DCMAKE_BUILD_TYPE=Debug
cmake --build build

# Run with debugger
gdb ./bin/test_0001_two_sum
```

## 📊 Performance Benchmarking

The project includes built-in benchmarking capabilities:

```cpp
// Example benchmark test
TEST_F(ProblemBenchmark, PerformanceTest) {
    auto start = std::chrono::high_resolution_clock::now();
    // Run algorithm
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    std::cout << "Execution time: " << duration.count() << " μs" << std::endl;
}
```

## 🤝 Contributing

1. Fork the repository
2. Create a feature branch
3. Implement your solution
4. Add comprehensive tests
5. Ensure all tests pass
6. Submit a pull request

## 📄 License

This project is open source and available under the [MIT License](LICENSE).

## 🐛 Troubleshooting

### Common Issues

1. **CMake not found**: Install CMake 4.0+ from [cmake.org](https://cmake.org/)
2. **Git not found**: Install Git for automatic Google Test download
3. **Compiler not C++20 compatible**: Update your compiler or use a different one
4. **Build failures**: Clean build directory and rebuild
5. **Network issues**: Ensure internet connection for Google Test download during first build

### Getting Help

- Check the [CMake documentation](https://cmake.org/documentation/)
- Review [Google Test documentation](https://google.github.io/googletest/)
- Open an issue for project-specific problems

---

**Happy Coding! 🎉**
