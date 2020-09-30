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

#include <algorithm>
#include <array>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <unordered_map>
#include <unordered_set>

bool checkConnection(
    const std::unordered_map<int, std::unordered_set<int>>& data, int from,
    int to)
{
    if (from == to)
        return true;

    std::unordered_set<int> checkedNodes{};
    std::unordered_set<int> nodesToCheck{data.at(from)};
    std::unordered_set<int> newNodesToCheck{};

    while (!nodesToCheck.empty())
    {
        for (const auto& node : nodesToCheck)
        {
            if (node == to)
                return true;
            if (!checkedNodes.insert(node).second)
                continue;
            for (auto nodeToAdd : data.at(node))
                if (checkedNodes.find(nodeToAdd) == checkedNodes.end())
                    newNodesToCheck.insert(nodeToAdd);
        }
        nodesToCheck = std::move(newNodesToCheck);
    }

    return false;
}

int getIpIndex(std::string ip, int& nodeNamesIndex,
               std::unordered_map<std::string, int>& nodeNamesMap)
{
    auto ipIter = nodeNamesMap.find(ip);
    int ipIndex{0};
    if (ipIter == nodeNamesMap.end())
    {
        ipIndex = nodeNamesIndex;
        nodeNamesMap[ip] = ipIndex;
        nodeNamesIndex++;
    }
    else
    {
        ipIndex = ipIter->second;
    }
    return ipIndex;
}

int main()
{
    int nodeNamesIndex{0};
    std::unordered_map<std::string, int> nodeNamesMap{};
    std::unordered_map<int, std::unordered_set<int>> data;
    while (!std::cin.eof())
    {
        char operation{};
        std::string ip1;
        std::string ip2;
        std::cin >> operation >> ip1 >> ip2;

        if (operation == 'B')
        {
            const int ip1Index{getIpIndex(ip1, nodeNamesIndex, nodeNamesMap)};
            const int ip2Index{getIpIndex(ip2, nodeNamesIndex, nodeNamesMap)};
            data[ip1Index].insert(ip2Index);
            data[ip2Index].insert(ip1Index);
        }

        if (operation == 'T')
        {
            auto ip1Iter = nodeNamesMap.find(ip1);
            auto ip2Iter = nodeNamesMap.find(ip2);
            if (ip1Iter != nodeNamesMap.end() && ip2Iter != nodeNamesMap.end())
            {
                bool pathExist =
                    checkConnection(data, ip1Iter->second, ip2Iter->second);
                std::cout << (pathExist ? "Y" : "N") << std::endl;
            }
            else
            {
                std::cout << "N" << std::endl;
            }
        }
    }

    return 0;
}
