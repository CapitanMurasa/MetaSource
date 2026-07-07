#version 330 core

in vec3 WorldPos;

layout(location = 0) out vec4 FragColor;

uniform float gGridCellSize = 0.125;
uniform vec4 gGridColorThin = vec4(0.0, 0.0, 0.0, 1.0);
uniform vec4 gGridColorThick = vec4(0.5, 0.5, 0.5, 1.0);


void main() {
    vec2 GridCalcultaions = vec2(1.0) - mod(WorldPos.xz, gGridCellSize) / (fwidth(WorldPos.xz) * vec2(2.0));
    //float Lod0a = mod(WorldPos.x, gGridCellSize) / fwidth(WorldPos.x);

    float Lod0a = max(GridCalcultaions.x, GridCalcultaions.y);

    vec4 Color;
    Color = gGridColorThick;
    Color.a *= Lod0a;

    FragColor = Color;
}
