#ifndef firewallServerMain_h
#define firewallServerMain_h
#include <iostream>

class DynamicFirewall
{
public:
    static int addRichRule(std::string);
    static int showRichRule(int userId);
    static int deleteRichRule(int userID, int ruleID);
    static void StartMainServer();
};

#endif