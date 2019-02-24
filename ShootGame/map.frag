#version 330 core			
out vec4 FragColor;
in vec2 Texture;

uniform sampler2D mapTexture;
uniform sampler2D shadowMap;

void main()					
{
	vec3 color=texture(mapTexture,Texture).rgb;
	FragColor=vec4(color,1.0);
}									