#include <iostream>
#include <dbus/dbus.h>
#include "firewallServer.h"

bool FirewallServer::start_session()
{
    dbus_error_init(&error);

    connection = dbus_bus_get(DBUS_BUS_SESSION, &error);

    if (dbus_error_is_set(&error))
    {
        std::cerr << "Error connecting to the session bus: " << error.message << std::endl;
        dbus_error_free(&error);
        return 1;
    }

    if (!connection)
    {
        std::cerr << "Failed to connect to the session bus." << std::endl;
        return 1;
    }

    std::cout << "Successfully connected to the session bus!" << std::endl;

    // Close the connection when done (not strictly necessary for session bus)
    dbus_connection_unref(connection);

    return 0;
}

bool FirewallServer::RegisterServer()
{
    if (!connection)
    {
        std::cout << "Connection to dbus not established properly..Please try again after establishing proper connection..." << std::endl;
        return false;
    }

    dbus_error_init(&error);

    int ret = dbus_bus_request_name(connection, busName.c_str(), DBUS_NAME_FLAG_REPLACE_EXISTING, &error);

    if (ret != DBUS_REQUEST_NAME_REPLY_PRIMARY_OWNER)
    {
        std::cerr << "The bus name is already Taken..Please give a diffrenet unique name.." << std::endl;
        return false;
    }

    std::cout << "Successfully registered the bus name: " << busName << std::endl;
    return true;
}

DBusHandlerResult FirewallServer::addRule(DBusConnection *connection, DBusMessage *message, void *user_data)
{
    if (dbus_message_is_method_call(message, busName.c_str(), "addRule"))
    {
        // Send a simple response back
        DBusMessage *reply = dbus_message_new_method_return(message);
        if (reply == NULL)
        {
            std::cerr << "Failed to create reply message!" << std::endl;
            return DBUS_HANDLER_RESULT_NEED_MEMORY;
        }
        dbus_connection_send(connection, reply, NULL);
        dbus_message_unref(reply);
    }
    return DBUS_HANDLER_RESULT_HANDLED;
}

void FirewallServer::startServer()
{
    while (true)
    {
        dbus_connection_read_write_dispatch(connection, -1); // Process incoming messages
    }
}
