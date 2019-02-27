#include "pch.h"
//#include <cstdio>
//#include <iostream>
//#include <vector>
//
//#define GLEW_STATIC
//#include <gl/glew.h>
//#include <GLFW/glfw3.h>
//
//#include <glm/glm.hpp>
//#include <glm/gtc/matrix_transform.hpp>
//#include <glm/gtc/type_ptr.hpp>
//
//#define STB_IMAGE_IMPLEMENTATION
//#include "stb_image.h"
//
//
//#include "Shader.h"
//#include "Camera.h"
//
//const float window_width = 800;
//const float window_height = 600;
//
//#pragma region Camera Declare
//Camera camera(glm::vec3(0.0f, 0.0f, 3.0f), 0.0f, 91.0f, glm::vec3(0, 1.0f, 0));
//#pragma endregion
//
//struct Particle {
//	glm::vec2 Position;
//	glm::vec2 Velocity;
//	glm::vec4 Color;
//	float Life;
//
//	Particle()
//		: Position(glm::vec2(0.6f,0.6f)), Velocity(glm::vec2(0.0f)), Color(glm::vec4(1.0f,0.0,0.0,1.0f)), Life(10.0f) { }
//};
//int nr_particles = 500;
//std::vector<Particle> particles;
//GLuint lastUsedParticle = 0;
//int FirstUnusedParticle();
//void ReuseParticle(int unused, glm::vec2 position, glm::vec2 velocity, glm::vec2 offset);
//
//#pragma region Funcion Declare
//void framebuffer_size_callback(GLFWwindow* window, int width, int height);
//void mouse_callback(GLFWwindow* window, double xpos, double ypos);
//void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
//void processInput(GLFWwindow *window);
//unsigned LoadImageToGPU(const char* filename, GLint internalformat, GLenum format, int slot);
//bool firstMouse = true;
//double lastX, lastY;
//
//#pragma endregion
//float planeVertices[] = {
//	-1,1,0,1,
//	-1,-1,0,0,
//	1,-1,1,0,
//
//	-1,1,0,1,
//	1,-1,1,0,
//	1,1,1,1
//};
//float quadVertices[] = { // vertex attributes for a quad that fills the entire screen in Normalized Device Coordinates.
//	// positions   // texCoords
//	-0.0f,  0.1f,  0.0f, 1.0f,
//	-1.0f, -1.0f,  0.0f, 0.0f,
//	 1.0f, -1.0f,  1.0f, 0.0f,
//
//	-1.0f,  1.0f,  0.0f, 1.0f,
//	 1.0f, -1.0f,  1.0f, 0.0f,
//	 1.0f,  1.0f,  1.0f, 1.0f
//};
//float particleVertices[] = {
//		// positions   // texCoords
//	-1.0f,  1.0f,  0.0f, 1.0f,
//	-1.0f, -1.0f,  0.0f, 0.0f,
//	 1.0f, -1.0f,  1.0f, 0.0f,
//
//	-1.0f,  1.0f,  0.0f, 1.0f,
//	 1.0f, -1.0f,  1.0f, 0.0f,
//	 1.0f,  1.0f,  1.0f, 1.0f
//};
//float vertices[] = {
//	// positions          // normals           // texture coords
//	-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f,  0.0f,
//	 0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f,  0.0f,
//	 0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f,  1.0f,
//	 0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f,  1.0f,
//	-0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f,  1.0f,
//	-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f,  0.0f,
//
//	-0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  0.0f,
//	 0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f,  0.0f,
//	 0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f,  1.0f,
//	 0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f,  1.0f,
//	-0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  1.0f,
//	-0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  0.0f,
//
//	-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f,  0.0f,
//	-0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  1.0f,  1.0f,
//	-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
//	-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
//	-0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  0.0f,
//	-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f,  0.0f,
//
//	 0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  0.0f,
//	 0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  1.0f,
//	 0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
//	 0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
//	 0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  0.0f,
//	 0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  0.0f,
//
//	-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  1.0f,
//	 0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  1.0f,  1.0f,
//	 0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f,  0.0f,
//	 0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f,  0.0f,
//	-0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  0.0f,
//	-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  1.0f,
//
//	-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  1.0f,
//	 0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  1.0f,
//	 0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  0.0f,
//	 0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  0.0f,
//	-0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  0.0f,
//	-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  1.0f
//};
//glm::vec3 cubePositions[] = {
//	glm::vec3(0.0f,  0.0f,  0.0f),
//	glm::vec3(2.0f,  5.0f, -15.0f),
//	glm::vec3(-1.5f, -2.2f, -2.5f),
//	glm::vec3(-3.8f, -2.0f, -12.3f),
//	glm::vec3(2.4f, -0.4f, -3.5f),
//	glm::vec3(-1.7f,  3.0f, -7.5f),
//	glm::vec3(1.3f, -2.0f, -2.5f),
//	glm::vec3(1.5f,  2.0f, -2.5f),
//	glm::vec3(1.5f,  0.2f, -1.5f),
//	glm::vec3(-1.3f,  1.0f, -1.5f)
//};
//float points[] = {
//	0,0,
//	0.5,0.5,
//	0.5,0,
//	0,0.5
//};
//
//int main()
//{
//
//	glfwInit();
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//	GLFWwindow* window = glfwCreateWindow(window_width, window_height, "GameShoot", NULL, NULL);
//	if (window == NULL) {
//		printf("Failed to create GLFW window\n");
//		glfwTerminate();
//		return -1;
//	}
//	glfwMakeContextCurrent(window);
//	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
//	glfwSetCursorPosCallback(window, mouse_callback);
//	glewExperimental = true;
//	if (glewInit() != GLEW_OK) {
//		printf("Init GLEW failed.");
//		glfwTerminate();
//		return -1;
//	}
//	glViewport(0, 0, window_width, window_height);
//	glEnable(GL_DEPTH_TEST);
//	glEnable(GL_BLEND);
//
//	glm::mat4 viewMat = glm::mat4(1.0f);
//	glm::mat4 modelMat = glm::mat4(1.0f);
//	glm::mat4 projMat = glm::mat4(1.0f);
//
//	unsigned int mapTexture, cubeTexture, grassTexture;
//	mapTexture = LoadImageToGPU("canyon_elev.bmp", GL_RGB, GL_RGB, 0);
//	cubeTexture = LoadImageToGPU("timg.jpg", GL_RGB, GL_RGB, 0);
//	grassTexture = LoadImageToGPU("grass.png", GL_RGBA, GL_RGBA, 0);
//
//	unsigned int cubeVAO, cubeVBO;
//	glGenVertexArrays(1, &cubeVAO);
//	glBindVertexArray(cubeVAO);
//	glGenBuffers(1, &cubeVBO);
//	glBindBuffer(GL_ARRAY_BUFFER, cubeVBO);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
//	glEnableVertexAttribArray(0);
//	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
//	glEnableVertexAttribArray(1);
//	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
//	glEnableVertexAttribArray(2);
//	Shader* cubeShader = new Shader("cube.vert", "cube.frag");
//
//	unsigned int quadVAO, quadVBO;
//	glGenVertexArrays(1, &quadVAO);
//	glBindVertexArray(quadVAO);
//	glGenBuffers(1, &quadVBO);
//	glBindBuffer(GL_ARRAY_BUFFER, quadVBO);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(quadVertices), quadVertices, GL_STATIC_DRAW);
//	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
//	glEnableVertexAttribArray(0);
//	Shader* quadShader = new Shader("quad.vert", "quad.frag");
//
//
//	unsigned int particleVAO, particleVBO;
//	glGenVertexArrays(1, &particleVAO);
//	glBindVertexArray(particleVAO);
//	glGenBuffers(1, &particleVBO);
//	glBindBuffer(GL_ARRAY_BUFFER, particleVBO);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(particleVertices), particleVertices, GL_STATIC_DRAW);
//	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
//	glEnableVertexAttribArray(0);
//
//	for (int i = 0; i < nr_particles; i++)
//		particles.push_back(Particle());
//	Shader* particleShader = new Shader("particle.vert", "particle.frag");
//
//
//	while (!glfwWindowShouldClose(window)) {
//		processInput(window);
//
//		glClearColor(0.2,0.2,0.2,1.0);
//		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//		//cubeShader->use();
//		//glBindVertexArray(cubeVAO);
//		//viewMat = camera.GetViewMatrix();
//		//projMat = glm::perspective(glm::radians(camera.Zoom), window_width / window_height, 0.1f, 100.0f);
//		//glUniformMatrix4fv(glGetUniformLocation(cubeShader->ID, "viewMat"), 1, GL_FALSE, glm::value_ptr(viewMat));
//		//glUniformMatrix4fv(glGetUniformLocation(cubeShader->ID, "projMat"), 1, GL_FALSE, glm::value_ptr(projMat));
//		//glActiveTexture(GL_TEXTURE0);
//		//glBindTexture(GL_TEXTURE_2D, cubeTexture);
//		//glUniform1i(glGetUniformLocation(cubeShader->ID, "cubeTexture"), 0);
//		//for (int i = 0; i < 1; i++)
//		//{
//		//	modelMat = glm::mat4(1.0);
//		//	modelMat = glm::translate(modelMat, cubePositions[i]);
//		//	glUniformMatrix4fv(glGetUniformLocation(cubeShader->ID, "modelMat"), 1, GL_FALSE, glm::value_ptr(modelMat));
//		//	//glDrawArrays(GL_TRIANGLES, 0, 36);
//		//}
//
//		int new_particles = 2;
//		glm::vec2 offset(0.2, 0.2);
//		for (int i = 0; i < new_particles; i++)
//		{
//			int unusedParticle = FirstUnusedParticle();
//			ReuseParticle(unusedParticle, glm::vec2(0.0, 0.0), glm::vec2(30.0f, rand()%30-15), offset);
//		}
//		glBlendFunc(GL_SRC_ALPHA, GL_ONE);
//		particleShader->use();
//		glBindVertexArray(particleVAO);
//		glActiveTexture(GL_TEXTURE0);
//		glBindTexture(GL_TEXTURE_2D, grassTexture);
//		glUniform1i(glGetUniformLocation(particleShader->ID, "sprite"), 0);
//		glUniform2f(glGetUniformLocation(particleShader->ID, "offset"), offset.x, offset.y);
//		viewMat = camera.GetViewMatrix();
//		projMat = glm::perspective(glm::radians(camera.Zoom), window_width / window_height, 0.1f, 100.0f);
//		float dt = 0.5;
//		for (int i = 0; i < nr_particles; i++)
//		{
//			Particle &p=particles[i];
//			p.Life -= dt;
//			if (p.Life > 0.0f) {
//				p.Position += p.Velocity*dt;
//				p.Color.a -= dt * 0.01;
//
//				modelMat = glm::mat4(1.0);
//				modelMat = glm::scale(modelMat, glm::vec3(0.0005, 0.0005, 0.0005));
//				modelMat = glm::translate(modelMat, glm::vec3(p.Position, 0));
//				glUniform4f(glGetUniformLocation(particleShader->ID, "color"), 
//					p.Color.r, p.Color.g, p.Color.b, p.Color.a);
//				glUniformMatrix4fv(glGetUniformLocation(particleShader->ID, "projMat"), 1, GL_FALSE, glm::value_ptr(projMat));
//				glUniformMatrix4fv(glGetUniformLocation(particleShader->ID, "viewMat"), 1, GL_FALSE, glm::value_ptr(viewMat));
//				glUniformMatrix4fv(glGetUniformLocation(particleShader->ID, "modelMat"), 1, GL_FALSE, glm::value_ptr(modelMat));
//				glDrawArrays(GL_TRIANGLES, 0, 6);
//			}
//		}
//		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
//		glPointSize(9.0);
//		quadShader->use();
//		glBindVertexArray(quadVAO);
//		glDrawArrays(GL_LINES, 0, 6);
//
//		glfwPollEvents();
//		glfwSwapBuffers(window);
//	}
//	glfwTerminate();
//	return 0;
//}
//
//#pragma region Function Define
//void framebuffer_size_callback(GLFWwindow* window, int width, int height)
//{
//	glViewport(0, 0, width, height);
//}
//
//void processInput(GLFWwindow *window)
//{
//	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
//		glfwSetWindowShouldClose(window, true);
//	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
//		camera.Position += camera.Forward*camera.MovementSpeed;
//	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
//		camera.Position -= camera.Forward*camera.MovementSpeed;
//	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
//		camera.Position -= camera.Right*camera.MovementSpeed;
//	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
//		camera.Position += camera.Right*camera.MovementSpeed;
//	if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
//		camera.Position -= camera.Up*camera.MovementSpeed;
//	if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
//		camera.Position += camera.Up*camera.MovementSpeed;
//}
//
//unsigned int LoadImageToGPU(const char* filename, GLint internalformat, GLenum format, int slot)
//{
//	unsigned int TexBuffer;
//	glGenTextures(1, &TexBuffer);
//	glActiveTexture(GL_TEXTURE0 + slot);
//	glBindTexture(GL_TEXTURE_2D, TexBuffer);
//	int width, height, nrChannel;
//	stbi_set_flip_vertically_on_load(true); // µﬂµπ‘ÿ»Î
//	unsigned char *data = stbi_load(filename, &width, &height, &nrChannel, 0);
//	if (data) {
//		glTexImage2D(GL_TEXTURE_2D, 0, internalformat, width, height, 0, format, GL_UNSIGNED_BYTE, data);
//		glGenerateMipmap(GL_TEXTURE_2D);
//	}
//	else {
//		printf("load image failed.");
//	}
//	stbi_image_free(data);
//	return TexBuffer;
//}
//
//void mouse_callback(GLFWwindow * window, double xpos, double ypos)
//{
//	printf("mouseMove: %f %f\n", xpos, ypos);
//	if (firstMouse == true) {
//		lastX = xpos;
//		lastY = ypos;
//		firstMouse = false;
//		return;
//	}
//	float deltaX, deltaY;
//	deltaX = xpos - lastX;
//	deltaY = ypos - lastY;
//
//	lastX = xpos;
//	lastY = ypos;
//	camera.ProcessMouseMovement(deltaX, -deltaY);
//}
//
//void scroll_callback(GLFWwindow * window, double xoffset, double yoffset)
//{
//	camera.ProcessMouseScroll(yoffset);
//}
//
//int FirstUnusedParticle() {
//	// Search from last used particle, this will usually return almost instantly
//	for (GLuint i = lastUsedParticle; i < nr_particles; ++i) {
//		if (particles[i].Life <= 0.0f) {
//			lastUsedParticle = i;
//			return i;
//		}
//	}
//	// Otherwise, do a linear search
//	for (GLuint i = 0; i < lastUsedParticle; ++i) {
//		if (particles[i].Life <= 0.0f) {
//			lastUsedParticle = i;
//			return i;
//		}
//	}
//	// Override first particle if all others are alive
//	lastUsedParticle = 0;
//	return 0;
//};
//void ReuseParticle(int unused,glm::vec2 position, glm::vec2 velocity,glm::vec2 offset) {
//	GLfloat random = ((rand() % 100) - 50) / 10.0f;
//	GLfloat rColor = 0.5 + ((rand() % 100) / 200.0f);
//	particles[unused].Position = position + random + offset;
//	particles[unused].Color = glm::vec4(rColor, rColor, rColor, 1.0f);
//	particles[unused].Life = 100.0f;
//	particles[unused].Velocity = velocity * 0.1f;
//};
//#pragma endregion