#version 330 core
layout (location = 0) in vec3 a_pos;
layout (location = 0) in vec3 VertexNormal;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

out vec3 normal;
out vec3 FragPos;

void main() {
    gl_Position = projection * view * model * vec4(a_pos, 1.0);
    normal = mat3(model) * VertexNormal;
    FragPos = mat3(model) * a_pos;
}