# Modern C++ CI

[![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)](/LICENSE)

| Build status          | Systems / Compilers         |
| ------------- | ------------------------------------------ |
| [![CLang  / GCC / XCode Builds](https://travis-ci.org/LearningByExample/ModernCppCI.svg?branch=master)](https://travis-ci.org/LearningByExample/ModernCppCI) | Linux (clang  / gcc) OSX (XCode 8 clang) |
| [![Visual Studio Builds](https://ci.appveyor.com/api/projects/status/t6i95u07gw1gqhql/branch/master?svg=true)](https://ci.appveyor.com/project/juan-medina/moderncppci/branch/master)       | Windows (Visual Studio 2017 /2015 / 2013)  |

## info
This is an example of doing a Modern C++ project with CI.

It use basic [C++14](https://isocpp.org/wiki/faq/cpp14-language) syntax, but nothing really complicated.

[CMake](https://cmake.org/) is the chosen build system and for test it uses [catch](https://github.com/philsquared/Catch).

# project structure

| folder       | Content              |
| ------------ | -------------------- |
| [/app](app) | application |
| [/app/src](/app/src) | application sources  |
| [/app/include](/app/include) | application includes |
| [/test](/test) | application test |
| [/test/src](/test/src) | test sources |
| [/test/include](/test/include) | test includes        |

# usage

Linux and Mac Debug

```shell
  cmake -H. -BBuild -DCMAKE_BUILD_TYPE=Debug
  cd Build
  make
  ctest -V
```

Linux and Mac Release

```shell
  cmake -H. -BBuild -DCMAKE_BUILD_TYPE=Release
  cd Build
  make
  ctest -V
```

Windows x64 Debug

```bat
  cmake -H. -BBuild -Ax64
  cd Build
  msbuild ModernCppCI.sln
  ctest -V -C Debug
```

Windows Win32 Debug

```bat
  cmake -H. -BBuild -AWin32
  cd Build
  msbuild ModernCppCI.sln
  ctest -V -C Debug
```

Windows x64 Release

```bat
  cmake -H. -BBuild -Ax64
  cd Build
  msbuild ModernCppCI.sln
  ctest -V -C Release
```

Windows Win32 Release

```bat
  cmake -H. -BBuild -AWin32
  cd Build
  msbuild ModernCppCI.sln
  ctest -V -C Release
```

# references

- https://github.com/philsquared/Catch
- https://github.com/cognitivewaves/CMake-VisualStudio-Example
- http://derekmolloy.ie/hello-world-introductions-to-cmake/
- https://cmake.org/Wiki/CMake/Testing_With_CTest
- https://www.appveyor.com/docs/lang/cpp/
- https://docs.travis-ci.com/user/languages/cpp/
- https://github.com/philsquared/Catch/blob/master/docs/build-systems.md