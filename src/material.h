#ifndef WINTER_MATERIAL_H
#define WINTER_MATERIAL_H

#include <memory>
#include "texture2d.h"
#include "shader_program.h"

namespace winter {
    namespace gfx {

        class material {
        public:
            material();
            ~material();

            void set_albedo_tex(std::shared_ptr<texture2d> tex);
            void set_shader_program(std::shared_ptr<shader_program> program);


        };
    }
}


#endif
