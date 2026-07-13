#version 330 core

uniform vec3 Color;
uniform vec3 AmbientLight;

in vec3 normal;

out vec4 FragColor;

void main()
{
	//FragColor = vec4(AmbientLight * Color, 1.0f);
	FragColor = vec4((normal + vec3(1))/2, 1.0f);
}