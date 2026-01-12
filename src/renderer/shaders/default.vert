#version 330 core
layout (location = 0) in vec3 a_pos;
layout (location = 1) in vec3 Color;

out vec3 rgb;

void main() {
	gl_Position = vec4(a_pos.xyz, 1.0);
	rgb =  Color;
}
