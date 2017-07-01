# Modern C++ CI

[![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)](/LICENSE)

| Build status          | Systems / Compilers         |
| ------------- | ------------------------------------------ |
| [![CLang  / GCC / XCode Builds](https://travis-ci.org/LearningByExample/ModernCppCI.svg?branch=master)](https://travis-ci.org/LearningByExample/ModernCppCI) | Linux (clang38  / gcc6) OSX (XCode 8.3 clang) |
| [![Visual Studio Builds](https://ci.appveyor.com/api/projects/status/t6i95u07gw1gqhql/branch/master?svg=true)](https://ci.appveyor.com/project/juan-medina/moderncppci/branch/master)       | Windows (Visual Studio 2017 / 2015)  |

## info
This is an example of doing a Modern C++ project with CI.

It use basic [C++14](https://isocpp.org/wiki/faq/cpp14-language) syntax, but nothing really complicated.

[CMake](https://cmake.org/) is the chosen build system using [ctest](https://cmake.org/Wiki/CMake/Testing_With_CTest).

## libraries used
- [spdlog](https://github.com/gabime/spdlog) for a moderm log system. (included)
- [catch](https://github.com/philsquared/Catch) as the test framework.  (included)

##  project structure

| folder       | Content              |
| ------------ | -------------------- |
| [/lib](/lib) | library |
| [/lib/src](/lib/src) | library sources  |
| [/lib/include](/lib/include) | library includes |
| [/lib/test](/lib/test) | library test |
| [/app](/app) | application |
| [/app/src](/app/src) | application sources  |
| [/app/include](/app/include) | application includes |
| [/app/test](/app/test) | application test |
| [/test/src](/test/src) | test sources |
| [/test/include](/test/include) | test includes        |
| [/third_party](/third_party) | third party software        |

## Generate project

```shell
  cmake -H. -BBuild
```

Auto detect everything.

If you like to set a implicit compiler set the variable CXX=${COMPILER}, for example COMPILER could be gcc, clang and so on.

Auto detect in Windows usually generate a Visual Studio project since msbuild require it, but in mac does not generate and XCode project, since is not required for compiling using XCode clang.

Specify build type debug/release

```shell
  # generate a debug project
  cmake -H. -BBuild -DCMAKE_BUILD_TYPE=Debug
  # generate a release project
  cmake -H. -BBuild -DCMAKE_BUILD_TYPE=Release
```

Specify architecture

```shell
  # 64 bits architecture
  cmake -H. -BBuild -Ax64
  # ARM architecture
  cmake -H. -BBuild -AARM
  # Windows 32 bits architecture
  cmake -H. -BBuild -AxWin32
```

Generate different project types

```shell
  # MinGW makefiles
  cmake -H. -BBuild -G "MinGW Makefiles"
  # XCode project
  cmake -H. -BBuild -G "XCode"
  # Visual Studio 15 2017 solution
  cmake -H. -BBuild -G "Visual Studio 15 2017"
```

## Build

From the Build folder

```shell
  # build the default build type (in multi build types usually debug)
  cmake --build .
  # build a specific build type
  cmake --build . --config Release
```
## Run tests

From the Build folder

```shell
  # run all test using the default build type
  ctest -V
  # run all test in Release build type
  ctest -V -C Release
```

## references

- https://github.com/philsquared/Catch
- https://github.com/gabime/spdlog
- https://github.com/cognitivewaves/CMake-VisualStudio-Example
- http://derekmolloy.ie/hello-world-introductions-to-cmake/
- https://cmake.org/Wiki/CMake/Testing_With_CTest
- https://www.appveyor.com/docs/lang/cpp/
- https://docs.travis-ci.com/user/languages/cpp/
- https://github.com/philsquared/Catch/blob/master/docs/build-systems.md
- https://stackoverflow.com/questions/14446495/cmake-project-structure-with-unit-tests
