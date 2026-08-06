#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;
layout (location = 2) in vec2 aTexCoord;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
uniform vec3 lightDir;

out vec2 TexCoord;
out float Diffuse;

void main() {
    gl_Position = projection * view * model * vec4(aPos, 1.0);
    vec3 N = normalize(mat3(transpose(inverse(model))) * aNormal);
    Diffuse = max(dot(N, normalize(-lightDir)), 0.2);
    TexCoord = aTexCoord;
}