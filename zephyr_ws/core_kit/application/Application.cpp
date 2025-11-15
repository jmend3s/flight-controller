
#include "Application.h"


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

void Application::update()
{
    _registry.updateAll();
}
