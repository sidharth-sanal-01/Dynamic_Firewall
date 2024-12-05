#ifndef FirewallServer_H
#define FirewallServer_H

#include <dbus/dbus.h>

class FirewallServer
{
private:
    DBusConnection *connection = nullptr;
    DBusError error;
    std::string busName = "com.firewall.server";
public:
    bool start_session();
    bool RegisterServer();
    void startServer();
    DBusHandlerResult addRule(DBusConnection *connection, DBusMessage *message, void *user_data);
    DBusHandlerResult deleteRule(DBusConnection *connection, DBusMessage *message, void *user_data);
    DBusHandlerResult testServer(DBusConnection *connection, DBusMessage *message, void *user_data);
};

#endif