#version 330 core

in vec2 uv;
out vec4 col;
uniform sampler2D _mainTex;

void main() {
    col = texture(_mainTex, uv);
}
