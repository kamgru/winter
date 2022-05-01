#version 330 core
layout (location = 0) in vec3 i_pos;
layout (location = 1) in vec3 i_norm;
layout (location = 2) in vec2 i_uv;

out vec2 uv;
out vec3 norm;
out vec3 fragPos;

uniform mat4 u_model;
uniform mat4 u_view;
uniform mat4 u_projection;
uniform mat3 u_normal;

void main() {
    gl_Position = u_projection * u_view * u_model * vec4(i_pos, 1.0);
    fragPos = vec3(u_model * vec4(i_pos, 1.0));
    uv = i_uv.xy;
    norm = u_normal * i_norm;
}