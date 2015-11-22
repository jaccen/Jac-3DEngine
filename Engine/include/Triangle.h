#ifndef Triangle_H
#define Triangle_H

#include <GL/glew.h>
#include "Shader.h"
#include "Utility.h"
class Triangle
{
public:
	Triangle();
	~Triangle();

	void Init();
	void Render(const MvpMatrix& matrix);
	void Shutdown();

private:
	void init_buffer();
	void init_vertexArray();
	void init_shader();

public:
	GLuint vao, vbo;
	GLuint model_prog;
	struct ModelUniformLoc
	{
		GLuint model;
		GLuint view;
		GLuint proj;
		GLuint cubemap;
		GLuint viewPos;
	}modelUniform_loc;


	Shader TriangleShader{ "Triangle Shader" };
	GLuint program = 0;

	GLuint model_loc, view_loc, proj_loc;

};
#endif
