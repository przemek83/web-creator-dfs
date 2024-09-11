#pragma once

#include <list>
#include <string>
#include <unordered_map>
#include <unordered_set>

class WebCreator
{
public:
    void addConnection(const std::string& fromIP, const std::string& toIP);

    bool connectionExist(const std::string& fromIP, const std::string& toIP);

private:
    unsigned int getIpIndex(const std::string& ip);

    void processNode(std::unordered_set<unsigned int>& checkedNodes,
                     std::list<unsigned int>& nodesToCheck,
                     const std::list<unsigned int>::iterator& it);
    bool checkConnection(unsigned int fromIPIndex, unsigned int toIPIndex);

    unsigned int currentNameIndex_{0};
    std::unordered_map<std::string, unsigned int> nodeNamesMap_{};
    std::unordered_map<unsigned int, std::list<unsigned int>> connections_{};
};
