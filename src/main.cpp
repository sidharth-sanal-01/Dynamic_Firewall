#include <iostream>
#include "rulecheck.h"
#include "firewallServer.h"
#include <memory>

int main()
{
    std::unique_ptr<RuleCheck> check = std::make_unique<RuleCheck>();
    // check->checkValidMac("00:1A:2B:3C:4D:5E");
    // check->checkValidPortNumber("65535");
    std::unique_ptr<FirewallServer> server = std::make_unique<FirewallServer>();

    server->start_session();
    server->RegisterServer();
    server->startServer();
}