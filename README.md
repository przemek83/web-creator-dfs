[![Build & test](https://github.com/przemek83/web-creator-dfs/actions/workflows/buld-and-test.yml/badge.svg)](https://github.com/przemek83/web-creator-dfs/actions/workflows/buld-and-test.yml)
[![CodeQL](https://github.com/przemek83/web-creator-dfs/actions/workflows/github-code-scanning/codeql/badge.svg)](https://github.com/przemek83/web-creator-dfs/actions/workflows/github-code-scanning/codeql)
[![codecov](https://codecov.io/gh/przemek83/web-creator-dfs/graph/badge.svg?token=IHVEAAXJNU)](https://codecov.io/gh/przemek83/web-creator-dfs)

[![Quality Gate Status](https://sonarcloud.io/api/project_badges/measure?project=przemek83_web-creator-dfs&metric=alert_status)](https://sonarcloud.io/summary/new_code?id=przemek83_web-creator-dfs)
[![Bugs](https://sonarcloud.io/api/project_badges/measure?project=przemek83_web-creator-dfs&metric=bugs)](https://sonarcloud.io/summary/new_code?id=przemek83_web-creator-dfs)
[![Code Smells](https://sonarcloud.io/api/project_badges/measure?project=przemek83_web-creator-dfs&metric=code_smells)](https://sonarcloud.io/summary/new_code?id=przemek83_web-creator-dfs)
[![Coverage](https://sonarcloud.io/api/project_badges/measure?project=przemek83_web-creator-dfs&metric=coverage)](https://sonarcloud.io/summary/new_code?id=przemek83_web-creator-dfs)
[![Duplicated Lines (%)](https://sonarcloud.io/api/project_badges/measure?project=przemek83_web-creator-dfs&metric=duplicated_lines_density)](https://sonarcloud.io/summary/new_code?id=przemek83_web-creator-dfs)

# Table of content
- [About](#about)
- [Problem description](#problem-description)
- [Getting Started](#getting-started)
   * [Prerequisites](#prerequisites)
   * [Building](#building)
   * [Used tools and libs](#used-tools-and-libs)
- [Usage](#usage)
- [Testing](#testing)
- [License](#license)

# About
Tool for creating simple network (graph) containing nodes in form of IP addresses and checking nodes connections using DFS (Depth-First Search) algorithm.

# Problem description
Write application allowing to create web of connected nodes in form of IP addresses (5 numbers separated by dots). User should be able to create connection between nodes and check if there is a connection between 2 given nodes.

**Input**:  
Set of lines with 3 entries separated by space:
1) Operation type: B - build, T - test.
2) From IP.
3) To IP.

**Output**:  
For the B (build) operation, display nothing. For the T (test) operation, display "Y" if there is a connection between the given nodes and "N" otherwise.

# Getting Started
This section describes briefly how to setup the environment and build the project.

## Prerequisites
C++ compiler with C++17 support as a minimum and CMake 3.14+. Additionally, the Git tool for downloading the Google Test library is needed by the test subproject.

## Building
Clone and use CMake directly or via any IDE supporting it. CMake should:
- configure everything automatically,
- compile and create binaries.

As a result of compilation, binary for simulations and binary for testing should be created.

## Used tools and libs
| Tool |  Windows 10 | Lubuntu 20.04 |
| --- | --- | --- |
| OS version | 10 22H2 | 24.04 |
| GCC | 13.1.0 | 13.2.0 |
| Cmake | 3.30.2 | 3.28.3 |
| Git | 2.46.0 | 2.43.0 |
| GoogleTest | 1.15.2 | 1.15.2 |

# Usage
Application expects on std in lines containing type of operation (B or T) and 2 IP addresses. Each element in line need to be separated by space.  
Example input:
```
B 1.1.1.1.1 2.2.2.2.2
T 1.1.1.1.1 2.2.2.2.2
T 1.1.1.1.1 3.3.3.3.3
```
Example output:
```
Y
N
```

Examples of usage:  
1. Pass example file named `testFile.txt` from project repo:
    ```shell
    $ ./web-creator-dfs  < testFile.txt
    Y
    N
    Y
    Y
    N
    ```
2. Use binary directly:
    ```shell
    $ ./web-creator-dfs
    B 1.1.1.1.1 2.2.2.2.2
    T 1.1.1.1.1 2.2.2.2.2
    Y
    T 1.1.1.1.1 3.3.3.3.3
    N
    ```
3. Pipe input:
    ```shell
    $ cat testFile.txt | ./web-creator-dfs
    Y
    N
    Y
    Y
    N
    ```
# Testing
The project contains a test subproject based on Goggle Test framework. Compile testing subproject and launch tests via IDE or directly from the console. Example run:
```
$ ./web-creator-dfs-tests
(...)
[==========] Running 4 tests from 1 test suite.
[----------] Global test environment set-up.
[----------] 4 tests from WebCreator
[ RUN      ] WebCreator.checkConnectionEmptyWeb
[       OK ] WebCreator.checkConnectionEmptyWeb (0 ms)
[ RUN      ] WebCreator.checkConnectionOneElementWeb
[       OK ] WebCreator.checkConnectionOneElementWeb (0 ms)
[ RUN      ] WebCreator.checkConnectionOneElementWebReversed
[       OK ] WebCreator.checkConnectionOneElementWebReversed (0 ms)
[ RUN      ] WebCreator.testCreationOfNonTrivialWeb
[       OK ] WebCreator.testCreationOfNonTrivialWeb (0 ms)
[----------] 4 tests from WebCreator (0 ms total)

[----------] Global test environment tear-down
[==========] 4 tests from 1 test suite ran. (0 ms total)
[  PASSED  ] 4 tests.
```

# License
The project is distributed under the MIT License. See `LICENSE` for more information.

The project uses the following open-source software:
| Name | License | Home | Description |
| --- | --- | --- | --- |
| GoogleTest | BSD-3-Clause | https://github.com/google/googletest | testing framework |
