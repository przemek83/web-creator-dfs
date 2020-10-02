#pragma once

#include <string>
#include <unordered_map>
#include <unordered_set>

class WebCreator
{
public:
    void addConnection(const std::string& fromIP, const std::string& toIP);

    bool connectionExist(const std::string& fromIP, const std::string& toIP);

private:
    int getIpIndex(const std::string& ip);

    bool checkConnection(unsigned int fromIPIndex, unsigned int toIPIndex);

    unsigned int currentNameIndex_{0};
    std::unordered_map<std::string, unsigned int> nodeNamesMap_{};
    std::unordered_map<unsigned int, std::unordered_set<unsigned int>>
        connections_{};
};
