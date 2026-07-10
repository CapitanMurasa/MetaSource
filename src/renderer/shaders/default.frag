#version 330 core
out vec4 FragColor;

in vec3 rgb; 
in vec2 TexCoord;

uniform sampler2D Texture;

void main() {
    //FragColor = texture(Texture, TexCoord) * vec4(rgb, 1.0f);
    FragColor = vec4(rgb, 1.0f);
}