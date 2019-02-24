#version 330 core
layout (location = 0) in vec4 aVertex;

out vec2 TexCoords;

void main()
{
    gl_Position = vec4(aVertex.xy, 0.0, 1.0); 
    TexCoords = aVertex.zw;
}