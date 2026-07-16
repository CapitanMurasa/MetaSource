#version 330 core

uniform vec3 Color;
uniform vec3 AmbientLight;
uniform vec3 LightPos;
uniform vec3 viewPos;
//uniform vec3 lightColor;

in vec3 normal;
in vec3 FragPos;

out vec4 FragColor;

void main()
{
    vec3 ambientColor = AmbientLight * Color;

    vec3 norm = normalize(normal);
    vec3 lightDir = normalize(LightPos - FragPos);
    vec3 diffuseColor = max(0.0, dot(norm, lightDir)) * Color;

    float specularStrength = 0.5; 
    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 reflectDir = reflect(-lightDir, norm);  
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
    vec3 specularColor = specularStrength * spec * vec3(1.0); 

    FragColor = vec4(ambientColor + diffuseColor + specularColor, 1.0);
}