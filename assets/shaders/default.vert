#version 410 core

layout (location = 0) in vec3 i_vertexPosition;
layout (location = 1) in vec3 i_vertexNormal;
layout (location = 2) in vec2 i_vertexUv;

layout (location = 0) out vec2 o_vertexUv;
layout (location = 1) out vec3 o_vertexNormal;
layout (location = 2) out vec3 o_fragmentPosition;

uniform mat4 u_modelMatrix;
uniform mat4 u_viewMatrix;
uniform mat4 u_projectionMatrix;
uniform mat3 u_normalMatrix;

void main() {
    gl_Position = u_projectionMatrix * u_viewMatrix * u_modelMatrix * vec4(i_vertexPosition, 1.0);

    o_vertexUv = i_vertexUv;
    o_vertexNormal = u_normalMatrix * i_vertexNormal;
    o_fragmentPosition = vec3(u_modelMatrix * vec4(i_vertexPosition, 1.0));
}