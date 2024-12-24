#include "firewallServerMain.h"
#include "dbusServer.h"
#include <iostream>
#include <fstream>
#include <filesystem>

namespace fs = std::filesystem;

int DynamicFirewall::addRichRule(std::string rule)
{
    std::string ruleFilePath = "../rules.nft";

    if (!fs::exists(ruleFilePath))
    {
        std::cout << "Rule file not present.." << std::endl;
    }
    else
    {
        std::ofstream file(ruleFilePath, std::ios::app);
        file << rule << std::endl;
    }
    std::cout << "Sucessfully Added the rule" << std::endl;
    return 0;
}

int DynamicFirewall::deleteRichRule(int userId, int ruleID)
{
    return 0;
}

void DynamicFirewall::StartMainServer()
{
    try
    {
        // Create a D-Bus connection (system bus or session bus)
        auto connection = sdbus::createSessionBusConnection(); // No ServiceName type
        std::cout << "Connection established successfully.." << std::endl;
        // Request a well-known name on the bus
        const char *serviceName = "org.firewall.server_adaptor";
        connection->requestName(serviceName);
        std::cout << "Service name assiged Sucessfully" << std::endl;

        // Define the object path and create the server object
        const char *objectPath = "/org/firewall/server_adaptor";
        firewallServer server(*connection, objectPath);

        // Run the main event loop
        std::cout << "Service running..." << std::endl;
        connection->enterEventLoop();
    }
    catch (const std::exception &ex)
    {
        std::cerr << "Error: " << ex.what() << std::endl;
        std::cout << "Failed to start Main Server..." << std::endl;
    }
}