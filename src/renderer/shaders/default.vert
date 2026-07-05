#version 330 core
layout (location = 0) in vec3 a_pos;
layout (location = 1) in vec3 Color;

out vec3 rgb;

uniform float src_aspect;

void main() {
	gl_Position = vec4(a_pos.x * src_aspect, a_pos.y, a_pos.z, 1.0);
	rgb =  Color;
}
