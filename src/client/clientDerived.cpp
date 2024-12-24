#include "my_proxy.h"
#include <sdbus-c++/sdbus-c++.h>
#include <iostream>

// Derived class to make the constructor public
class MyServerProxy : public org::firewall::server_proxy
{
public:
    MyServerProxy(sdbus::IProxy &proxy) : org::firewall::server_proxy(proxy) {}
};
