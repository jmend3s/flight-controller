
#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "Component.h"
#include "Registry.h"


namespace fc
{
    class Application
    {
    public:
        Application();

        bool add(Component& component);

        void initialize();
        void run();

    private:
        Registry<8> _registry;
    };
}

#endif