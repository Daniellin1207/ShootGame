#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#define GLEW_STATIC
#include <gl/glew.h>
#include <GLFW/glfw3.h>

class Shader
{
public:
	unsigned int ID;
	Shader(const GLchar* vertexPath, const GLchar* fragmentPath);
	string vertexString;
	string fragmentString;
	const char* vertexSource;
	const char* fragmentSource;

	enum {
		DIFFUSE,
		SPECULAR
	};

	void use();
	void setVec3(const std::string & name, const glm::vec3 & value) const;
	void SetUniform3f(const char* paramNameString, glm::vec3 param);
	void SetUniform1f(const char* paramNameString, float param);
	void SetUniform1i(const char* paramNameString, int slot);
private:
	void checkCompileErrors(unsigned int ID, std::string type);
};

