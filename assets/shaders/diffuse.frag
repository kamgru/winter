#version 410 core

layout (location = 0) in vec2 i_vertexUv;
layout (location = 1) in vec3 i_vertexNormal;
layout (location = 2) in vec3 i_fragmentPosition;

out vec4 framentColor;

uniform sampler2D u_mainTex;
uniform vec3 u_lightPosition;
uniform vec3 u_cameraPosition;

void main() {

    vec3 lightColor = vec3(1.0f, 0.0f, 0.5f);
    float ambientStrength = 0.3;
    float specularStrength = 0.5;

    vec3 lightDirection = normalize(u_lightPosition - i_fragmentPosition);
    float diff = max(dot(i_vertexNormal, lightDirection), 0.0);
    vec4 diffuse = vec4(diff * lightColor, 1.0);

    vec3 viewDirection = normalize(u_cameraPosition - i_fragmentPosition);
    vec3 reflectDirection = reflect(-lightDirection, i_vertexNormal);
    float spec = pow(max(dot(viewDirection, reflectDirection), 0.0), 32);
    vec4 specular = vec4(specularStrength * spec * lightColor, 1.0);

    framentColor = texture(u_mainTex, i_vertexUv) * (ambientStrength + diffuse + specular);
}