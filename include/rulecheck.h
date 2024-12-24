#ifndef RULE_CHECK_H
#define RULE_CHECK_H
#include <iostream>

class RuleCheck
{
public:
    static bool checkValidIP(const std::string &ip_address);              // to check for valid ip adresses
    static bool checkValidMac(const std ::string &mac_address);           // to check for valid mac address
    static bool checkValidPortNumber(const std::string &validPortNumber); // to check for valid port number
    static bool checkProtocol(const std::string &protocol);               // to check for valid protocol check
};

#endif