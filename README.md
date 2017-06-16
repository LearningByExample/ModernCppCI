# Modem C++ CI

[![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)](/LICENSE)

Build status:
- Linux (clang  / gcc) , OSX (XCode 8 clang) [![CLang  / GCC / XCode Builds](https://travis-ci.org/LearningByExample/ModernCppCI.svg?branch=master)](https://travis-ci.org/LearningByExample/ModernCppCI)

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
