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
//#include "Shader.h"
//#include "Camera.h"
//
//const float window_width = 800;
//const float window_height = 600;
//
//#pragma region Camera Declare
//Camera camera(glm::vec3(-2.0f, 4.0f, -1.0f), 0.0f, 0.0f, glm::vec3(0, 1.0f, 0));
//#pragma endregion
//
//#pragma region Funcion Declare
//void framebuffer_size_callback(GLFWwindow* window, int width, int height);
//void mouse_callback(GLFWwindow* window, double xpos, double ypos);
//void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
//void processInput(GLFWwindow *window);
//unsigned LoadImageToGPU(const char* filename, GLint internalformat, GLenum format, int slot);
//bool firstMouse = true;
//double lastX, lastY;
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
//
//int main()
//{
//	
//	glfwInit();
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);
//	GLFWwindow* window = glfwCreateWindow(window_width,window_height,"GameShoot",NULL,NULL);
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
//
//	glm::mat4 viewMat = glm::mat4(1.0f);
//	glm::mat4 modelMat = glm::mat4(1.0f);
//	glm::mat4 projMat = glm::mat4(1.0f);
//
//	unsigned int mapTexture,cubeTexture;
//	mapTexture = LoadImageToGPU("canyon_elev.bmp", GL_RGB, GL_RGB, 0);
//	cubeTexture = LoadImageToGPU("snow-packed12-preview-600x600.jpg", GL_RGB, GL_RGB, 0);
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
//	Shader* cubeShader = new Shader("cube.vert","cube.frag");
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
//	const GLuint SHADOW_WIDTH = 1024, SHADOW_HEIGHT = 1024;
//	unsigned int depthMapFBO;
//	glGenFramebuffers(1, &depthMapFBO);
//	GLuint depthMap;
//	glGenTextures(1, &depthMap);
//	glBindTexture(GL_TEXTURE_2D, depthMap);
//
//	glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT,
//		SHADOW_WIDTH, SHADOW_HEIGHT, 0, GL_DEPTH_COMPONENT, GL_FLOAT, NULL);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//
//	glBindFramebuffer(GL_FRAMEBUFFER, depthMapFBO);
//	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, depthMap, 0);
//	glDrawBuffer(GL_NONE);
//	glReadBuffer(GL_NONE);
//	glBindFramebuffer(GL_FRAMEBUFFER, 0);
//
//	glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
//
//	glm::vec3 lightPos(-6.0f, 4.0f, -1.0f);
//
//	Shader* easyShader8 = new Shader("easy8.vert", "easy8.frag");
//	while (!glfwWindowShouldClose(window)) {
//		processInput(window);
//
//		glViewport(0, 0, window_width, window_height);
//		glBindFramebuffer(GL_FRAMEBUFFER, depthMapFBO);
//		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//		GLfloat near_plane = 1.0f, far_plane = 7.5f;
//		glm::mat4 lightProjection = glm::ortho(-10.0f, 10.0f, -10.0f, 2.0f, near_plane, far_plane);
//		glm::mat4 lightView = glm::lookAt(lightPos, glm::vec3(0.0f), glm::vec3(0,1.0,0));
//
//		easyShader8->use();
//		glBindVertexArray(cubeVAO);
//		viewMat = lightView;
//		projMat = lightProjection;
//		glUniformMatrix4fv(glGetUniformLocation(easyShader8->ID, "viewMat"), 1, GL_FALSE, glm::value_ptr(viewMat));
//		glUniformMatrix4fv(glGetUniformLocation(easyShader8->ID, "projMat"), 1, GL_FALSE, glm::value_ptr(projMat));
//		for (int i = 0; i < 10; i++)
//		{
//			modelMat = glm::mat4(1.0);
//			modelMat = glm::translate(modelMat, cubePositions[i]);
//			glUniformMatrix4fv(glGetUniformLocation(easyShader8->ID, "modelMat"), 1, GL_FALSE, glm::value_ptr(modelMat));
//			glDrawArrays(GL_TRIANGLES, 0, 36);
//		}
//
//		glBindFramebuffer(GL_FRAMEBUFFER, 0);
//		glViewport(0, 0, window_width, window_height);
//		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//		//quadShader->use();
//		//glBindVertexArray(quadVAO);
//		//glActiveTexture(GL_TEXTURE0);
//		//glBindTexture(GL_TEXTURE_2D, depthMap);
//		//glDrawArrays(GL_TRIANGLES, 0, 6);
//
//		cubeShader->use();
//		glBindVertexArray(cubeVAO);
//		viewMat = lightView;
//		projMat = lightProjection;
//		glUniformMatrix4fv(glGetUniformLocation(cubeShader->ID, "light_viewMat"), 1, GL_FALSE, glm::value_ptr(viewMat));
//		glUniformMatrix4fv(glGetUniformLocation(cubeShader->ID, "light_projMat"), 1, GL_FALSE, glm::value_ptr(projMat));
//		viewMat = camera.GetViewMatrix();
//		projMat = glm::perspective(glm::radians(camera.Zoom), window_width / window_height, 0.1f, 100.0f);
//		glUniformMatrix4fv(glGetUniformLocation(cubeShader->ID, "viewMat"), 1, GL_FALSE, glm::value_ptr(viewMat));
//		glUniformMatrix4fv(glGetUniformLocation(cubeShader->ID, "projMat"), 1, GL_FALSE, glm::value_ptr(projMat));
//		glActiveTexture(GL_TEXTURE0);
//		glBindTexture(GL_TEXTURE_2D, cubeTexture);
//		glUniform1i(glGetUniformLocation(cubeShader->ID, "cubeTexture"), 0);
//		glActiveTexture(GL_TEXTURE1);
//		glBindTexture(GL_TEXTURE_2D, depthMap);
//		glUniform1i(glGetUniformLocation(cubeShader->ID, "shadowMap"), 1);
//
//		for (int i = 0; i < 10; i++)
//		{
//			modelMat = glm::mat4(1.0);
//			modelMat = glm::translate(modelMat, cubePositions[i]);
//			glUniformMatrix4fv(glGetUniformLocation(cubeShader->ID, "modelMat"), 1, GL_FALSE, glm::value_ptr(modelMat));
//
//			glDrawArrays(GL_TRIANGLES, 0, 36);
//		}
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
//	stbi_set_flip_vertically_on_load(true); // 颠倒载入
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
//#pragma endregion