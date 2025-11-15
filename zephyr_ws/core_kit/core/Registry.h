
#ifndef __REGISTRY_H__
#define __REGISTRY_H__

#include "Component.h"

#include <cstddef>

template <size_t N>
class Registry
{
public:
    bool add(Component& component);

    void initializeAll();
    void updateAll();

    size_t size() const;

private:
    Component* _components[N];
    size_t _size = 0;
};

template <size_t N>
bool Registry<N>::add(Component& component)
{
    bool onCapacity = false;
    if (_size < N)
    {
        _components[_size++] = &component;
        onCapacity = true;
    }

    return onCapacity;
}

template <size_t N>
void Registry<N>::initializeAll()
{
    for (size_t i = 0; i < _size; i++)
    {
        _components[i]->initialize();
    }
}

template <size_t N>
void Registry<N>::updateAll()
{
    for (size_t i = 0; i < _size; i++)
    {
        _components[i]->update();
    }
}

template <size_t N>
size_t Registry<N>::size() const
{
    return _size;
}

#endif
