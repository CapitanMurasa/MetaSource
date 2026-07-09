#version 330 core
layout (location = 0) in vec3 a_pos;
layout (location = 1) in vec3 Color;
layout (location = 2) in vec2 VertexTexCoord;

out vec3 rgb;
out vec2 TexCoord;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

const vec3 Pos[4] = vec3[4](
	vec3(-1.0, 0.0, -1.0),
	vec3( 1.0, 0.0, -1.0),
	vec3( 1.0, 0.0,  1.0),
	vec3(-1.0, 0.0,  1.0)
);

const int Indices[6] = int[6](0, 2, 1, 2, 0, 3);

void main() {
	int Index = Indices[gl_VertexID];
	vec4 vPos = vec4(Pos[Index], 1.0);
    gl_Position = projection * view * model * vec4(a_pos, 1.0);
    rgb = Color;
	TexCoord = VertexTexCoord;
}