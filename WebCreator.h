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
    int getIpIndex(std::string ip);

    bool checkConnection(int fromIP, int toIP);

    unsigned int currentNameIndex_{0};
    std::unordered_map<std::string, int> nodeNamesMap_{};
    std::unordered_map<int, std::unordered_set<int>> connections_{};
};
