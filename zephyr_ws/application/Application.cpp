
#include "Application.h"

#include <zephyr/kernel.h>


namespace fc
{
    Application::Application()
        : _registry()
    {
    }

    bool Application::add(Component& component)
    {
        return _registry.add(component);
    }

    void Application::initialize()
    {
        _registry.initializeAll();
    }

    void Application::run()
    {
        _registry.updateAll();
        k_msleep(100);
    }
}
