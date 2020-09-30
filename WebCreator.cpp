#include "WebCreator.h"

void WebCreator::addConnection(const std::string& fromIP,
                               const std::string& toIP)
{
    const int ip1Index{getIpIndex(fromIP)};
    const int ip2Index{getIpIndex(toIP)};
    connections_[ip1Index].insert(ip2Index);
    connections_[ip2Index].insert(ip1Index);
}

bool WebCreator::connectionExist(const std::string& fromIP,
                                 const std::string& toIP)
{
    auto ip1Iter{nodeNamesMap_.find(fromIP)};
    auto ip2Iter{nodeNamesMap_.find(toIP)};
    if (ip1Iter == nodeNamesMap_.end() || ip2Iter == nodeNamesMap_.end())
        return false;

    return checkConnection(ip1Iter->second, ip2Iter->second);
}

int WebCreator::getIpIndex(std::string ip)
{
    auto ipIter{nodeNamesMap_.find(ip)};
    int ipIndex{0};
    if (ipIter == nodeNamesMap_.end())
    {
        ipIndex = currentNameIndex_;
        nodeNamesMap_[ip] = ipIndex;
        currentNameIndex_++;
    }
    else
    {
        ipIndex = ipIter->second;
    }
    return ipIndex;
}

bool WebCreator::checkConnection(int fromIP, int toIP)
{
    if (fromIP == toIP)
        return true;

    std::unordered_set<int> checkedNodes{};
    std::unordered_set<int> nodesToCheck{connections_.at(fromIP)};
    std::unordered_set<int> newNodesToCheck{};

    while (!nodesToCheck.empty())
    {
        for (const auto& node : nodesToCheck)
        {
            if (node == toIP)
                return true;
            if (!checkedNodes.insert(node).second)
                continue;
            for (auto nodeToAdd : connections_.at(node))
                if (checkedNodes.find(nodeToAdd) == checkedNodes.end())
                    newNodesToCheck.insert(nodeToAdd);
        }
        nodesToCheck = std::move(newNodesToCheck);
    }

    return false;
}
