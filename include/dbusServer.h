#ifndef dbusServer_h
#define dbusServer_h
#include <iostream>
#include <sdbus-c++/sdbus-c++.h>
#include "my_adaptor.h"

class firewallServer : public sdbus::AdaptorInterfaces<org::firewall::server_adaptor /*, more adaptor classes if there are more interfaces*/>
{
public:
    firewallServer(sdbus::IConnection &connection, sdbus::ObjectPath objectPath)
        : AdaptorInterfaces(connection, std::move(objectPath))
    {
        registerAdaptor();
    }

    ~firewallServer()
    {
        unregisterAdaptor();
    }

protected:
    std::string addRule(const sdbus::Struct<int32_t, std::string, std::string, std::string> &input) override;
    sdbus::Struct<int32_t, std::string, std::string, std::string> showRule(const int32_t &id) override;
    std::string deleteRule(const int32_t &id) override;
};
#endif