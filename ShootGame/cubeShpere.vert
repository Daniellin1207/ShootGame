#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTex;
layout (location = 2) in vec3 aNor;

out vec2 Texture;
out vec3 Normal;

uniform mat4 modelMat;
uniform mat4 viewMat;
uniform mat4 projMat;
void main()
{
	Texture=aTex;
	Normal=aNor;
    gl_Position =projMat*viewMat*vec4(aPos, 1.0);
}