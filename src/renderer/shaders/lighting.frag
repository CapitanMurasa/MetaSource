#version 330 core

uniform vec3 Color;
uniform vec3 AmbientLight;

out vec4 FragColor;

void main()
{
	FragColor = vec4(AmbientLight * Color, 1.0f);
}