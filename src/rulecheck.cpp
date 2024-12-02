#include "rulecheck.h"
#include <iostream>
#include <algorithm>

int RuleCheck::checkProtocol(const std::string &protocol)
{
    if (protocol == "udp" || protocol == "tcp" || protocol == "icmp")
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int RuleCheck::checkValidIP(const std::string &ipaddress)
{
    char delimiter = '.';
    int total = std::count(ipaddress.begin(), ipaddress.end(), delimiter);
    if (total > 3 || total < 3 || total == 0)
    {
        std::cout << "wrong IP Adress given..Please give a correct IP address.." << std::endl;
        return -1;
    }
    else
    {
        std::cout << "Ip Address is in correct Format: " << ipaddress << std::endl;
    }
    std::cout << "Total Count: " << total << std::endl;
    return total;
}

int RuleCheck::checkValidMac(const std::string &macAddress)
{
    return 0;
}

int RuleCheck::checkValidPortNumber(const std::string &portNumber)
{
    return 0;
}