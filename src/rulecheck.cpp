#include "rulecheck.h"
#include <iostream>
#include <algorithm>
#include <regex>

bool RuleCheck::checkProtocol(const std::string &protocol)
{
    if (protocol == "udp" || protocol == "tcp" || protocol == "icmp")
    {

        return true;
    }
    else
    {
        std::cout << "Wrong protocol given.." << std::endl;
        return false;
    }
}

bool RuleCheck::checkValidIP(const std::string &ipaddress)
{
    char delimiter = '.';
    int total = std::count(ipaddress.begin(), ipaddress.end(), delimiter);
    if (total > 3 || total < 3 || total == 0)
    {
        std::cout << "wrong IP Adress given..Please give a correct IP address.." << std::endl;
        return false;
    }
    else
    {
        std::cout << "Ip Address is in correct Format: " << ipaddress << std::endl;
    }
    std::cout << "Total Count: " << total << std::endl;
    return true;
}

bool RuleCheck::checkValidMac(const std::string &macAddress)
{
    std::regex MAC_format("^([0-9A-Fa-f]{2}([-:])?){5}([0-9A-Fa-f]{2})$");
    if (!std::regex_match(macAddress, MAC_format))
    {
        std::cout << "Invalid Mac address...Please try Again with valid one\n";
        return false;
    }
    std::cout << "Valid Mac address..Checking other Parmaeters" << std::endl;
    return true;
}

bool RuleCheck::checkValidPortNumber(const std::string &portNumber)
{
    int port = 0;
    try
    {
        port = std::stoi(portNumber);
    }
    catch (...)
    {
        std::cout << "Invalid Port Number given...Please provide correct Port Number" << std::endl;
        return false;
    }

    if (port > 1025 && port <= 65535)
    {
        std::cout << "Valid Port number is given..Moving Forward.." << std::endl;
        return true;
    }
    std::cout << "Port number given is out of range..Please give correct Port Number" << std::endl;
    return false;
}