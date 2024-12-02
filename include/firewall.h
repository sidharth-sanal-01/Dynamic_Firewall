#ifndef firewall_h
#define firewall_h
#include <iostream>

class NetFirewall
{
private:
    std::string s_port;
    std::string d_port;
    int userID;
    std::string protocol;
    std::string source_ip;
    std::string destination_ip;

public:
    int addRichRule(int userId, std::string sportVal, std::string dportVal, std::string sip, std::string dip, std::string);

    int deleteRichRule(int userID, int ruleID);
};

#endif