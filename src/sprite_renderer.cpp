#include "sprite_renderer.h"
#include "transform_component.h"
#include "actor.h"
#include "sprite_component.h"
#include "texture2d.h"

using namespace winter;

glm::mat4 create_model_mat(std::weak_ptr<transform_component> transform_ptr){
    std::shared_ptr<transform_component> transform = transform_ptr.lock();
    glm::mat4 model(1.0f);
    model = glm::translate(model, transform->position());
    model = glm::scale(model, transform->scale());
    return model;
}

sprite_renderer::sprite_renderer(camera cam)
    : m_cam(cam){
}

void sprite_renderer::render(std::shared_ptr<sprite_component> spr_comp) {

    sprite spr = spr_comp->sprite();
    if (spr.texture() == nullptr) {
        return;
    }

    const actor* owner = spr_comp->get_owner();
    if (!owner) {
        return;
    }

    std::shared_ptr<transform_component> transform = owner->get_transform();

    spr.texture()->use();
    spr_comp->program().use();
    spr_comp->program().set_uniform_mat4("u_model", create_model_mat(transform));
    spr_comp->program().set_uniform_mat4("u_view", m_cam.view());
    spr_comp->program().set_uniform_mat4("u_projection", m_cam.projection());
    spr_comp->mesh().render();
}
