#include "actor.h"

using namespace winter;

component_t component_type_resolver::m_type_id = 0;

actor::actor() : m_transform_component(add_component<transform_component>()) {
}
