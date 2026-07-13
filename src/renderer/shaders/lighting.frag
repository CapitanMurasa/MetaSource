#version 330 core

uniform vec3 Color;
uniform vec3 AmbientLight;
uniform vec3 LightPos;
//uniform vec3 lightColor;

in vec3 normal;
in vec3 FragPos;

out vec4 FragColor;

void main()
{
	vec3 ambientcolor = AmbientLight * Color;

	vec3 norm = normalize(normal);
	vec3 lightDir = normalize(LightPos-FragPos);
	vec3 DiffuseColor = max(0.0f, dot(norm, lightDir)) * Color;


	FragColor = vec4(ambientcolor + DiffuseColor, 1.0f);
}