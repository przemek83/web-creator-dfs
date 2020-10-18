## Web creator using DFS
Tool for creating simple network (graph) containing nodes in form of IP addresses and checking nodes connections using DFS (Depth-First Search) algorithm.

## Table of content
- [Problem description](#problem-description)
- [Getting Started](#getting-started)
  * [Prerequisites](#prerequisites)
  * [Building](#building)
- [Built with](#built-with)
- [Usage](#usage)
- [Testing](#testing)
- [License](#license)

## Problem description
Write application allowing to create web of connected nodes in form of IP addresses (5 numbers separated by dots). User should be able to create connection between nodes and check if there is a connection between 2 given nodes.

**Input**:  
Set of lines with 3 entries separated by space:
1) Operation type: B - build, T - test.
2) From IP.
3) To IP.

**Output**:  
For B (build) operation display nothing. For T (test) operation display "Y" if there is connection between given nodes, "N" otherwise.

## Getting Started
This section describes briefly how to setup environment and build project.

### Prerequisites
C++ compiler with C++17 support as a minimum and CMake 3.8+. Additionally Git tool for downloading Google Test library as it is needed by test subproject.

### Building
Recommended:  
Use Cmake directly or your favorite IDE supporting CMake projects.  

Alternative:  
Use bare compiler for building project binary:
```shell
$ g++ -Wall -std=c++17 -O3 -c *.cpp
$ g++ -Wall -std=c++17 -O3 -o web-creator-dfs *.o
```

## Built with
| Tool |  Windows 10 | Lubuntu 20.04 |
| --- | --- | --- |
| GCC | 7.3.0 | 9.3.0 |
| Cmake | 3.14 | 3.17 |
| Git | 2.20 | 2.25 |
| QtCreator | 4.12.0 | 4.13.0 |

## Usage
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
## Testing
Project contains test subproject based on Goggle Test framework. Compile testing subproject and launch tests via IDE or directly from console.  
Example run:
```
$ ./web-creator-dfs-test
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

## License
Project is distributed under the MIT License. See `LICENSE` for more information.
