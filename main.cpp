// Web creator using DFS
// Tool for creating simple network (graph) containing nodes in form of IP
// addresses and checking nodes connections using DFS (Depth-First Search)
// algorithm.

// Input
// Set of rows with 3 entries separated by space:
// 1) Operation type: B - build, T - test.
// 2) From IP.
// 3) To IP.

// Output
// For B (build) operation display nothing. For T (test) operation "Y" if there
// is connection between given nodes, "N" otherwise.

//  Example
//  IN
//  B 100.100.100.1 100.100.100.2
//  B 100.100.100.1 100.100.100.3
//  B 100.100.100.10 100.100.100.11
//  T 100.100.100.1 100.100.100.3
//  T 100.100.100.10 100.100.100.2
//  T 100.100.100.10 100.100.100.11
//  B 100.100.100.11 100.100.100.2
//  T 100.100.100.10 100.100.100.3
//  T 100.100.100.100 100.100.100.103

//  OUT
//  Y
//  N
//  Y
//  Y
//  N

#include <iostream>

#include "WebCreator.h"

int main()
{
    WebCreator creator;
    while (!std::cin.eof())
    {
        char operation{};
        std::string ip1;
        std::string ip2;
        std::cin >> operation >> ip1 >> ip2;

        if (operation == 'B')
            creator.addConnection(ip1, ip2);

        if (operation == 'T')
        {
            const bool connectioExist{creator.connectionExist(ip1, ip2)};
            std::cout << (connectioExist ? "Y" : "N") << std::endl;
        }
    }

    return 0;
}
