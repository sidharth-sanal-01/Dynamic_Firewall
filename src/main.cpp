#include "onboot.h"
#include "firewallServerMain.h"
#include <iostream>
#include <thread>

int main()
{
    std::thread boot(Onboot::startBoot);
    for (int i = 0; i < 5; i++)
    {
        std::cout << "Print First" << std::endl;
    }

    std::thread firewall(DynamicFirewall::StartMainServer);
    for (int i = 0; i < 5; i++)
    {
        std::cout << "Print Sec" << std::endl;
    }

    boot.join();
    firewall.join();
    return EXIT_SUCCESS;
}
