#version 330 core
out vec4 color;
in vec2 TexCoords;

//uniform sampler2D depthMap;

void main()
{             
	color=vec4(0.5,1,0.5,1.0);
//    float depthValue = texture(depthMap, TexCoords).r;
//    color = vec4(vec3(depthValue), 1.0);
}