#version 330 core
layout (location = 0) in vec4 aVertex;

uniform mat4 modelMat;
uniform mat4 viewMat;
uniform mat4 projMat;

void main()
{
    gl_Position =projMat*viewMat*modelMat*vec4(aVertex.xy,0.0, 1.0);
}