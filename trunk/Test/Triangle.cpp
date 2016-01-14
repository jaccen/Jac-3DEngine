#include "Triangle.h"
const static GLfloat VertexData[] = {
	0.0f, 1.0f, 0.0f,
	-1.0f, -1.0f, 0.0f,
	1.0f, -1.0f, 0.0f
};
Triangle::Triangle()
{

}

Triangle::~Triangle()
{

}

void Triangle::Init()
{
	init_buffer();
	init_vertexArray();
	init_shader();
}

void Triangle::Render(const MvpMatrix& matrix)
{
	//Use this shader and vao data to render
	glUseProgram(program);
	glBindVertexArray(vao);

	glm::mat4 view = glm::mat4(glm::mat3(matrix.view));
	glm::mat4 proj = matrix.proj;
	glm::mat4 model = matrix.model;

	glUniformMatrix4fv(view_loc, 1, GL_FALSE, &view[0][0]);
	glUniformMatrix4fv(proj_loc, 1, GL_FALSE, &proj[0][0]);
	glUniformMatrix4fv(model_loc, 1, GL_FALSE, &model[0][0]);

	glDepthFunc(GL_LEQUAL);

	glDrawArrays(GL_TRIANGLES, 0, 3);

	glBindVertexArray(0);
	//
	glUseProgram(0);
}


void Triangle::Shutdown()
{
	glDeleteProgram(program);
}

void Triangle::init_buffer()
{
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);    //load the vertex data
	glBufferData(GL_ARRAY_BUFFER, sizeof(VertexData), VertexData, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Triangle::init_vertexArray()
{
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 3, (GLvoid*)(NULL));

	glBindVertexArray(0);
}

void Triangle::init_shader()
{
	TriangleShader.init();
// 	TriangleShader.attach(GL_VERTEX_SHADER, "triangle.vert");
// 	TriangleShader.attach(GL_FRAGMENT_SHADER, "triangle.frag");

	TriangleShader.attach(GL_VERTEX_SHADER, "test.vsh");
	TriangleShader.attach(GL_FRAGMENT_SHADER, "test.fsh");
	TriangleShader.link();
	program = TriangleShader.GetProgram();

	model_loc = glGetUniformLocation(program, "model");
	view_loc = glGetUniformLocation(program, "view");
	proj_loc = glGetUniformLocation(program, "proj");

}
