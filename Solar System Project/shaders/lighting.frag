#version 330 core
in vec2 TexCoord;
in vec3 FragPos;
in vec3 Normal;

uniform sampler2D u_Texture;
uniform vec3 u_ViewPos;

out vec4 FragColor;

void main() {
    vec4 texColor = texture(u_Texture, TexCoord);
    
    // Simple directional light
    vec3 lightDir = normalize(vec3(1.0, 2.0, 1.0));
    vec3 norm = normalize(Normal);
    float diff = max(dot(norm, lightDir), 0.2);
    
    // Ambient light to ensure visibility
    float ambient = 0.3;
    float brightness = ambient + diff;
    
    FragColor = vec4(texColor.rgb * brightness, 1.0);
}