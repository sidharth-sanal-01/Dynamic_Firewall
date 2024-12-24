#include "clientDerived.cpp"
#include <iostream>
int main()
{
    try
    {
        // Create a D-Bus connection to the session bus
        auto connection = sdbus::createSessionBusConnection();

        // Create a proxy object for the server
        auto proxy = sdbus::createProxy(*connection, "org.firewall.server_adaptor", "/org/firewall/server_adaptor");

        // Use the proxy to call server methods
        MyServerProxy server(*proxy);

        // Example 1: Add a rule
        sdbus::Struct<int32_t, std::string, std::string, std::string> addRuleInput = {1, "168.254.33.95", "TCP", "4456"};
        std::string addRuleResult = server.addRule(addRuleInput);
        std::cout << "addRule Result: " << addRuleResult << std::endl;

        // Example 2: Show a rule
        auto showRuleResult = server.showRule(1);
        std::cout << "showRule Result: "
                  << std::get<0>(showRuleResult) << ", "
                  << std::get<1>(showRuleResult) << ", "
                  << std::get<2>(showRuleResult) << ", "
                  << std::get<3>(showRuleResult) << std::endl;

        // Example 3: Delete a rule
        std::string deleteRuleResult = server.deleteRule(1);
        std::cout << "deleteRule Result: " << deleteRuleResult << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
