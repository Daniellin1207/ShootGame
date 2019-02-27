#version 330 core			
out vec4 FragColor;
in vec2 Texture;
in float shadow;
uniform sampler2D cubeTexture;
void main()					
{
	vec3 color = texture(cubeTexture,Texture).rgb;
//	vec3 color = vec3(1.0);
	FragColor=vec4(color,1.0);
}									