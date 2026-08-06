#version 330 core
in vec2 TexCoord;
in float Diffuse;
uniform sampler2D ourTexture;
out vec4 FragColor;

void main() {
    vec3 texColor = texture(ourTexture, TexCoord).rgb;
    FragColor = vec4(texColor * Diffuse, 1.0);
}