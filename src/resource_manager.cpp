#include "resource_manager.h"
#include "texture2d.h"

using namespace winter;

template<>
std::shared_ptr<texture2d> resource_manager::get_resource(res_handle<texture2d> handle) {

    if (m_texture_cache.contains(handle.get_id())){
        return m_texture_cache.get(handle.get_id());
    }

    std::shared_ptr<texture2d> texture = std::make_shared<texture2d>();
    texture->from_file(handle.get_id());
    m_texture_cache.upsert(handle.get_id(), texture);
    return texture;
}
