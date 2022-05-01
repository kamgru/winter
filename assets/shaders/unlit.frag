#version 330 core

in vec2 uv;
out vec4 col;
uniform sampler2D u_mainTex;

void main() {
    col = texture(u_mainTex, uv);
}
