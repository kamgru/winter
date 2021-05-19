#ifndef WINTER_RESOURCE_MANAGER_H
#define WINTER_RESOURCE_MANAGER_H

#include <string>
#include <memory>
#include <map>

namespace winter{

    class texture2d;

    typedef std::string resource_id;

    template<class T>
    class res_handle {
    public:
        res_handle(resource_id id): m_id(id){};
        resource_id get_id() { return m_id; }
    private:
        resource_id m_id;
    };

    template<class T>
    class resource_cache {
    public:
        bool contains(resource_id id){
            return m_cache.count(id) == 1;
        };
        void upsert(resource_id id, std::shared_ptr<T> resource){
            m_cache[id] = resource;
        };
        std::shared_ptr<T> get(resource_id id){
            return m_cache[id];
        };
    private:
        std::map<resource_id, std::shared_ptr<T>> m_cache;
    };

    class resource_manager {
    public:
        template<class T>
        std::shared_ptr<T> get_resource(res_handle<T> handle);
    private:
        resource_cache<texture2d> m_texture_cache;
    };
}


#endif
