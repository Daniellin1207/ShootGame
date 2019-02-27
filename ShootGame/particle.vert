#version 330 core
layout (location = 0) in vec4 vertex; // <vec2 position, vec2 texCoords>

out vec2 TexCoords;
out vec4 ParticleColor;

uniform mat4 projMat;
uniform mat4 viewMat;
uniform mat4 modelMat;
uniform vec2 offset;
uniform vec4 color;

void main()
{
    float scale = 10.0f;
    TexCoords = vertex.zw;
    ParticleColor = color;
    gl_Position = projMat * viewMat * modelMat * vec4((vertex.xy * scale) + offset, 0.0, 1.0);
}