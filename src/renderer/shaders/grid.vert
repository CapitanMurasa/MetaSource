#version 330 core

out vec3 WorldPos;

uniform mat4 view;       
uniform mat4 projection;

const vec3 Pos[4] = vec3[4](
    vec3(-5.0, -0.0, -5.0), 
    vec3( 5.0, -0.0, -5.0),
    vec3( 5.0, -0.0,  5.0),
    vec3(-5.0, -0.0,  5.0)
);

const int Indices[6] = int[6](0, 2, 1, 2, 0, 3);

void main() {
    int Index = Indices[gl_VertexID];
    
    vec4 vPos = vec4(Pos[Index], 1.0);

    WorldPos = vPos.xyz;
    gl_Position = projection * view * vPos; 
}