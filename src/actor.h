#ifndef WINTER_ACTOR_H
#define WINTER_ACTOR_H

#include "component.h"

namespace winter {

    class actor {
    public:
        transform& get_transform() { return m_transform; };
    private:
        winter::transform m_transform {};
    };
}

#endif //WINTER_ACTOR_H