#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 2) in vec2 aTex;

out vec2 Texture;
out float shadow;

uniform mat4 modelMat;

uniform mat4 viewMat;
uniform mat4 projMat;

uniform mat4 light_viewMat;
uniform mat4 light_projMat;

uniform sampler2D shadowMap;
void main()
{
	vec4 lightPoint = light_projMat * light_viewMat * modelMat * vec4(aPos, 1.0);
	vec3 projCoords= lightPoint.xyz / lightPoint.w;
	projCoords= projCoords * 0.5 + 0.5;
	float currentDepth = projCoords.z;
	float closestDepth=texture(shadowMap,projCoords.xy).r;
	shadow = currentDepth > closestDepth  ? 1.0 : 0.0;

	Texture=aTex;
    gl_Position =projMat*viewMat*modelMat*vec4(aPos, 1.0);
}