#ifndef WINTER_COMPONENT_H
#define WINTER_COMPONENT_H

#include <memory>
#include <string>

namespace winter {

    class actor;

    class component {
    public:
        explicit component(actor *owner) : m_owner(owner){}
        virtual ~component() {};
        const actor* get_owner() { return m_owner; }
    private:
        actor *m_owner;
    };
}

#endif
