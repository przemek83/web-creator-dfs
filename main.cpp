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
