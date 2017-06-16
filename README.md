# Modem C++ CI

[![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)](/LICENSE)

Build status:
- Linux (clang  / gcc) , OSX (XCode 8 clang) [![CLang  / GCC / XCode Builds](https://travis-ci.org/LearningByExample/ModernCppCI.svg?branch=master)](https://travis-ci.org/LearningByExample/ModernCppCI)
- Windows (Visual Studio 2017 /2015 / 2013) [![Visual Studio Builds](https://ci.appveyor.com/api/projects/status/t6i95u07gw1gqhql?svg=true)](https://ci.appveyor.com/project/juan-medina/moderncppci)

## W. I. P.

# Usage

Linux and Mac

```shell
  cmake -BBuild
  cd Build
  make
  ctest -C Debug
```

Windows

```bat
  cmake -BBuild
  cd Build
  msbuild ModernCppCI.sln
  ctest -C Debug
```
