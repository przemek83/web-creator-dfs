#include "WebCreator.h"

void WebCreator::addConnection(const std::string& fromIP,
                               const std::string& toIP)
{
    const unsigned int ip1Index{getIpIndex(fromIP)};
    const unsigned int ip2Index{getIpIndex(toIP)};
    connections_[ip1Index].push_back(ip2Index);
    connections_[ip2Index].push_back(ip1Index);
}

bool WebCreator::connectionExist(const std::string& fromIP,
                                 const std::string& toIP)
{
    auto ip1Iter{nodeNamesMap_.find(fromIP)};
    auto ip2Iter{nodeNamesMap_.find(toIP)};
    if ((ip1Iter == nodeNamesMap_.end()) || (ip2Iter == nodeNamesMap_.end()))
        return false;

    return checkConnection(ip1Iter->second, ip2Iter->second);
}

unsigned int WebCreator::getIpIndex(const std::string& ip)
{
    if (const auto ipIter{nodeNamesMap_.find(ip)};
        ipIter != nodeNamesMap_.cend())
        return ipIter->second;

    unsigned int ipIndex{currentNameIndex_};
    nodeNamesMap_[ip] = ipIndex;
    ++currentNameIndex_;
    return ipIndex;
}

void WebCreator::processNode(std::unordered_set<unsigned int>& checkedNodes,
                             std::list<unsigned int>& nodesToCheck,
                             const std::list<unsigned int>::iterator& it)
{
    if (const auto [_, success]{checkedNodes.insert(*it)}; !success)
        return;

    for (auto nodeToAdd : connections_.at(*it))
        if (checkedNodes.find(nodeToAdd) == checkedNodes.end())
            nodesToCheck.push_back(nodeToAdd);
}
bool WebCreator::checkConnection(unsigned int fromIPIndex,
                                 unsigned int toIPIndex)
{
    if (fromIPIndex == toIPIndex)
        return true;

    std::unordered_set<unsigned int> checkedNodes{};
    std::list<unsigned int> nodesToCheck{connections_.at(fromIPIndex)};

    auto it{nodesToCheck.begin()};
    while (it != nodesToCheck.end() && *it != toIPIndex)
    {
        processNode(checkedNodes, nodesToCheck, it);
        it = nodesToCheck.erase(it);
    }

    return *it == toIPIndex;
}
