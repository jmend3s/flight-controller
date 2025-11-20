
#ifndef __COMPONENT_H__
#define __COMPONENT_H__


class Component
{
public:
    virtual ~Component() = default;

    virtual void initialize() = 0;
    virtual void update() = 0;
};

#endif
