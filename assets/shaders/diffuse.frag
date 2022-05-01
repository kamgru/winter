#version 330 core

in vec2 uv;
in vec3 norm;
in vec3 fragPos;

out vec4 col;
uniform sampler2D u_mainTex;
uniform vec3 u_lightpos;

void main() {

    vec3 lightDir = normalize(u_lightpos - fragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 lightCol = vec3(1.0f, 1.0f, 1.0f);
    vec4 diffuse = vec4(diff * lightCol, 1.0);

    float ambient = 0.1;
    vec4 color = texture(u_mainTex, uv);
    color = color * (ambient + diffuse);
    col = color.xyzw;
}