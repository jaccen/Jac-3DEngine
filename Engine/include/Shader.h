
#ifndef Shader_H
#define Shader_H

#include <GL/glew.h>
#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
#include <memory>
#include "Utility.h"

#ifdef _WIN32
#define WINDOW_PLATFORM
#endif


char *textFileRead(const char *fn);

class Shader
{

public:
	Shader() = default;
	Shader(std::string shaderName) : m_Name(shaderName) {}
	~Shader() = default;

public:
	void init(std::string folder = "");
	void attach(int type, char *filename);
	void link();
	void info();
	void use()  const;
	void end()  const;

	GLuint GetProgram() const;


private:


	GLuint m_Program =0;
	std::string fileDir;
	std::string m_Name = "Shader";
};
#endif