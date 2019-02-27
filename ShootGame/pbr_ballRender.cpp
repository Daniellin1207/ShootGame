#include "pch.h"
//#include <cstdio>
//#include <iostream>
//#include <vector>
//#include <math.h>
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
//#pragma region Funcion Declare
//void framebuffer_size_callback(GLFWwindow* window, int width, int height);
//void mouse_callback(GLFWwindow* window, double xpos, double ypos);
//void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
//void processInput(GLFWwindow *window);
//unsigned LoadImageToGPU(const char* filename, GLint internalformat, GLenum format);
//bool firstMouse = true;
//double lastX, lastY;
//void renderSphere();
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
//#pragma region Prepare
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
//
//	// lights
//// ------
//	glm::vec3 lightPositions[] = {
//		glm::vec3(-10.0f,  10.0f, 10.0f),
//		glm::vec3(10.0f,  10.0f, 10.0f),
//		glm::vec3(-10.0f, -10.0f, 10.0f),
//		glm::vec3(10.0f, -10.0f, 10.0f),
//	};
//	glm::vec3 lightColors[] = {
//		glm::vec3(300.0f, 300.0f, 300.0f),
//		glm::vec3(300.0f, 300.0f, 300.0f),
//		glm::vec3(300.0f, 300.0f, 300.0f),
//		glm::vec3(300.0f, 300.0f, 300.0f)
//	};
//	int nrRows = 7;
//	int nrColumns = 7;
//	float spacing = 2.5;
//	Shader* shader=new Shader("pbr.vert", "pbr.frag");
//	// initialize static shader uniforms before rendering
//	// --------------------------------------------------
//	glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float)window_width / (float)window_height, 0.1f, 100.0f);
//	shader->use();
//	glUniformMatrix4fv(glGetUniformLocation(shader->ID, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
//	glUniform1f(glGetUniformLocation(shader->ID, "ao"),1.0f);
//	glUniform3f(glGetUniformLocation(shader->ID, "albedo"), 0.5f, 0.0f, 0.0f);
//#pragma endregion
//
//	glViewport(0, 0, window_width, window_height);
//	glEnable(GL_DEPTH_TEST);
//
//	unsigned int mapTexture,cubeTexture;
//	mapTexture = LoadImageToGPU("canyon_elev.bmp", GL_RGB, GL_RGB);
//	cubeTexture = LoadImageToGPU("snow-packed12-preview-600x600.jpg", GL_RGB, GL_RGB);
//
//
//	while (!glfwWindowShouldClose(window)) {
//		processInput(window);
//		glClearColor(0.3,0.2,0.2,1.0);
//		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//		shader->use();
//		glm::mat4 view = camera.GetViewMatrix();
//		glUniformMatrix4fv(glGetUniformLocation(shader->ID, "view"), 1, GL_FALSE, glm::value_ptr(view));
//		glUniform3fv(glGetUniformLocation(shader->ID, "camPos"), 1,&camera.Position[0]);
//
//		glm::mat4 model = glm::mat4(1.0f);
//		for (int row = 0; row < nrRows; row++)
//		{
//			glUniform1f(glGetUniformLocation(shader->ID, "metallic"), (float)row / (float)nrRows);
//			for (int col = 0; col < nrColumns; ++col)
//			{
//				// we clamp the roughness to 0.025 - 1.0 as perfectly smooth surfaces (roughness of 0.0) tend to look a bit off
//				// on direct lighting.
//				glUniform1f(glGetUniformLocation(shader->ID, "roughness"), glm::clamp((float)col / (float)nrColumns, 0.05f, 1.0f));
//
//				model = glm::mat4(1.0f);
//				model = glm::translate(model, glm::vec3(
//					(col - (nrColumns / 2)) * spacing,
//					(row - (nrRows / 2)) * spacing,
//					0.0f
//				));
//				glUniformMatrix4fv(glGetUniformLocation(shader->ID, "model"), 1, GL_FALSE, glm::value_ptr(model));
//				renderSphere();
//			}
//		}
//		for (unsigned int i = 0; i < sizeof(lightPositions) / sizeof(lightPositions[0]); ++i)
//		{
//			glm::vec3 newPos = lightPositions[i] + glm::vec3(sin(glfwGetTime() * 5.0) * 5.0, 0.0, 0.0);
//			newPos = lightPositions[i];
//			shader->setVec3("lightPositions[" + std::to_string(i) + "]", newPos);
//			shader->setVec3("lightColors[" + std::to_string(i) + "]", lightColors[i]);
//
//			model = glm::mat4(1.0f);
//			model = glm::translate(model, newPos);
//			model = glm::scale(model, glm::vec3(0.5f));
//			glUniformMatrix4fv(glGetUniformLocation(shader->ID, "model"), 1, GL_FALSE, glm::value_ptr(model));
//			renderSphere();
//		}
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
//unsigned int LoadImageToGPU(const char* filename, GLint internalformat, GLenum format)
//{
//	unsigned int TexBuffer;
//	glGenTextures(1, &TexBuffer);
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
//// renders (and builds at first invocation) a sphere
//// -------------------------------------------------
//unsigned int sphereVAO = 0;
//unsigned int indexCount;
//void renderSphere()
//{
//	if (sphereVAO == 0)
//	{
//		glGenVertexArrays(1, &sphereVAO);
//
//		unsigned int vbo, ebo;
//		glGenBuffers(1, &vbo);
//		glGenBuffers(1, &ebo);
//
//		std::vector<glm::vec3> positions;
//		std::vector<glm::vec2> uv;
//		std::vector<glm::vec3> normals;
//		std::vector<unsigned int> indices;
//
//		const unsigned int X_SEGMENTS = 64;
//		const unsigned int Y_SEGMENTS = 64;
//		const float PI = 3.14159265359;
//		for (unsigned int y = 0; y <= Y_SEGMENTS; ++y)
//		{
//			for (unsigned int x = 0; x <= X_SEGMENTS; ++x)
//			{
//				float xSegment = (float)x / (float)X_SEGMENTS;
//				float ySegment = (float)y / (float)Y_SEGMENTS;
//				float xPos = std::cos(xSegment * 2.0f * PI) * std::sin(ySegment * PI);
//				float yPos = std::cos(ySegment * PI);
//				float zPos = std::sin(xSegment * 2.0f * PI) * std::sin(ySegment * PI);
//
//				positions.push_back(glm::vec3(xPos, yPos, zPos));
//				uv.push_back(glm::vec2(xSegment, ySegment));
//				normals.push_back(glm::vec3(xPos, yPos, zPos));
//			}
//		}
//
//		bool oddRow = false;
//		for (int y = 0; y < Y_SEGMENTS; ++y)
//		{
//			if (!oddRow) // even rows: y == 0, y == 2; and so on
//			{
//				for (int x = 0; x <= X_SEGMENTS; ++x)
//				{
//					indices.push_back(y       * (X_SEGMENTS + 1) + x);
//					indices.push_back((y + 1) * (X_SEGMENTS + 1) + x);
//				}
//			}
//			else
//			{
//				for (int x = X_SEGMENTS; x >= 0; --x)
//				{
//					indices.push_back((y + 1) * (X_SEGMENTS + 1) + x);
//					indices.push_back(y       * (X_SEGMENTS + 1) + x);
//				}
//			}
//			oddRow = !oddRow;
//		}
//		indexCount = indices.size();
//
//		std::vector<float> data;
//		for (int i = 0; i < positions.size(); ++i)
//		{
//			data.push_back(positions[i].x);
//			data.push_back(positions[i].y);
//			data.push_back(positions[i].z);
//			if (uv.size() > 0)
//			{
//				data.push_back(uv[i].x);
//				data.push_back(uv[i].y);
//			}
//			if (normals.size() > 0)
//			{
//				data.push_back(normals[i].x);
//				data.push_back(normals[i].y);
//				data.push_back(normals[i].z);
//			}
//		}
//		glBindVertexArray(sphereVAO);
//		glBindBuffer(GL_ARRAY_BUFFER, vbo);
//		glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(float), &data[0], GL_STATIC_DRAW);
//		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
//		glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);
//		float stride = (3 + 2 + 3) * sizeof(float);
//		glEnableVertexAttribArray(0);
//		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, stride, (void*)0);
//		glEnableVertexAttribArray(1);
//		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, stride, (void*)(3 * sizeof(float)));
//		glEnableVertexAttribArray(2);
//		glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, stride, (void*)(5 * sizeof(float)));
//	}
//
//	glBindVertexArray(sphereVAO);
//	glDrawElements(GL_TRIANGLE_STRIP, indexCount, GL_UNSIGNED_INT, 0);
//}
//#pragma endregion