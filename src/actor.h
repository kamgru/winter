#ifndef WINTER_ACTOR_H
#define WINTER_ACTOR_H

#include <map>
#include "transform_component.h"

namespace winter {

    typedef unsigned int component_t;

    class component_type_resolver {
    public:
        template<class TComponent>
        static component_t get_type(){
            const static component_t TYPE_ID = ++m_type_id;
            return TYPE_ID;
        };
    private:
        static component_t m_type_id;
    };

    class actor : std::enable_shared_from_this<actor> {
    public:
        actor();
        template<class TComponent>
        std::shared_ptr<TComponent> add_component(){
            std::shared_ptr<TComponent> component = std::make_shared<TComponent>(this);
            component_t type = component_type_resolver::get_type<TComponent>();
            m_components[type] = component;
            return component;
        };

        template<class TComponent>
        std::shared_ptr<TComponent> get_component() const {
            component_t type = component_type_resolver::get_type<TComponent>();
            std::shared_ptr<component> component = m_components.at(type);
            return std::dynamic_pointer_cast<TComponent>(component);
        }

        std::shared_ptr<transform_component> get_transform() const { return m_transform_component; };

    private:
        std::map<component_t, std::shared_ptr<component>> m_components;
        std::shared_ptr<transform_component> m_transform_component;
    };
}

#endif
