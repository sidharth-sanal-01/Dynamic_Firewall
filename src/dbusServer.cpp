#include "dbusServer.h"
#include "rulecheck.h"
#include "firewallServerMain.h"
#include <iostream>

std::string firewallServer::addRule(const sdbus::Struct<int32_t, std::string, std::string, std::string> &input)
{
    int32_t id = std::get<0>(input);
    std::string dip = std::get<1>(input);
    std::string protocol = std::get<2>(input);
    std::string port = std::get<3>(input);
    std::string ruleMade = protocol + " saddr " + dip + " port=" + port + " keepstate active";

    // checking the rule details
    if (RuleCheck::checkProtocol(protocol) && RuleCheck::checkValidPortNumber(port) && RuleCheck::checkValidIP(dip))
    {
        std::cout << "Rule Details provided are correct" << std::endl;
        DynamicFirewall::addRichRule(ruleMade);
    }
    else
    {
        return "Wrong Parmeters given..Please try again with correct Params";
    }

    // transform the rule to lower case---
    std::transform(ruleMade.begin(), ruleMade.end(), ruleMade.begin(), [](char c)
                   { return std::tolower(c); });

    std::cout << "Rule Made: " << ruleMade << std::endl;
    return ruleMade;
}

sdbus::Struct<int32_t, std::string, std::string, std::string> firewallServer::showRule(const int32_t &id)
{
    int32_t uid = id;                     // Rule ID (input parameter)
    std::string port = "8080";            // Example port
    std::string sourceIP = "192.168.1.1"; // Example source IP
    std::string destIP = "192.168.1.100"; // Example destination IP

    // Create and return the sdbus struct
    return sdbus::Struct<int32_t, std::string, std::string, std::string>{uid, port, sourceIP, destIP};
};

std::string firewallServer::deleteRule(const int32_t &id)
{
    return "Hey Deleted the rule";
}