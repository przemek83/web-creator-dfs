#include "WebCreator.h"

void WebCreator::addConnection(const std::string& fromIP,
                               const std::string& toIP)
{
    const unsigned int ip1Index{getIpIndex(fromIP)};
    const unsigned int ip2Index{getIpIndex(toIP)};
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

unsigned int WebCreator::getIpIndex(const std::string& ip)
{
    const auto ipIter{nodeNamesMap_.find(ip)};
    if (ipIter != nodeNamesMap_.end())
        return ipIter->second;

    unsigned int ipIndex{currentNameIndex_};
    nodeNamesMap_[ip] = ipIndex;
    currentNameIndex_++;
    return ipIndex;
}

bool WebCreator::checkConnection(unsigned int fromIPIndex,
                                 unsigned int toIpIndex)
{
    if (fromIPIndex == toIpIndex)
        return true;

    std::unordered_set<unsigned int> checkedNodes{};
    std::unordered_set<unsigned int> nodesToCheck{connections_.at(fromIPIndex)};

    while (!nodesToCheck.empty())
    {
        std::unordered_set<unsigned int> newNodesToCheck{};
        for (const auto& node : nodesToCheck)
        {
            if (node == toIpIndex)
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
