
#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "Component.h"
#include "Registry.h"


class Application
{
public:
    Application();

    bool add(Component& component);

    void initialize();
    void update();

private:
    Registry<8> _registry;
};

#endif
