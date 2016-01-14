#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <gl/glew.h>
#ifdef __APPLE__
#  include <gl/glut.h>
#else
#  include <gl/glut.h>
#endif

#include "Texture.h"

#if 0
#include "Shader.h"
#include "Texture.h"
#include <gl/glew.h>
#include <glfw/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>

using namespace std;

int main()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	GLFWwindow *window = glfwCreateWindow(800, 600, "opengl", nullptr, nullptr);

	if (window == NULL)
	{
		cerr << "Failed to create window" << endl;
		glfwTerminate();
		exit(-1);
	}
	glfwMakeContextCurrent(window);

	glewExperimental = GL_TRUE;
	GLenum err = glewInit();
	if (err != GLEW_OK)
	{
		cerr << "Failed to init glew : " << glewGetErrorString(err) << endl;
		exit(-1);
	}

	GLfloat vertices[] = {
		-0.5f, -0.5f, -0.5f, 0.0f, 0.0f,
		0.5f, -0.5f, -0.5f, 1.0f, 0.0f,
		0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
		0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
		-0.5f, 0.5f, -0.5f, 0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f, 0.0f, 0.0f,

		-0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
		0.5f, -0.5f, 0.5f, 1.0f, 0.0f,
		0.5f, 0.5f, 0.5f, 1.0f, 1.0f,
		0.5f, 0.5f, 0.5f, 1.0f, 1.0f,
		-0.5f, 0.5f, 0.5f, 0.0f, 1.0f,
		-0.5f, -0.5f, 0.5f, 0.0f, 0.0f,

		-0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
		-0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
		-0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
		-0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
		-0.5f, 0.5f, 0.5f, 1.0f, 0.0f,

		0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
		0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
		0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
		0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
		0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
		0.5f, 0.5f, 0.5f, 1.0f, 0.0f,

		-0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
		0.5f, -0.5f, -0.5f, 1.0f, 1.0f,
		0.5f, -0.5f, 0.5f, 1.0f, 0.0f,
		0.5f, -0.5f, 0.5f, 1.0f, 0.0f,
		-0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
		-0.5f, -0.5f, -0.5f, 0.0f, 1.0f,

		-0.5f, 0.5f, -0.5f, 0.0f, 1.0f,
		0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
		0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
		0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
		-0.5f, 0.5f, 0.5f, 0.0f, 0.0f,
		-0.5f, 0.5f, -0.5f, 0.0f, 1.0f
	};

	GLuint vao, vbo;
	GLuint texture;

	glEnable(GL_DEPTH_TEST);
	Shader our;
	our.init();
	// 	TriangleShader.attach(GL_VERTEX_SHADER, "triangle.vert");
	// 	TriangleShader.attach(GL_FRAGMENT_SHADER, "triangle.frag");

	our.attach(GL_VERTEX_SHADER, "vershader.vsh");
	our.attach(GL_FRAGMENT_SHADER, "fragshader.fsh");
	our.link();
	GLuint program = our.GetProgram();


	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	GLuint pos_loc = glGetAttribLocation(program, "vposition");
	glVertexAttribPointer(pos_loc, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (void *)0);
	glEnableVertexAttribArray(pos_loc);

	GLuint text_loc = glGetAttribLocation(program, "vtex_coord");
	glVertexAttribPointer(text_loc, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (void *)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(text_loc);

	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	Texture mtex;
	mtex.Load("wall.jpg");
	// 	int width, height;
	// 	unsigned char *image = SOIL_load_image("wall.jpg", &width, &height, 0, SOIL_LOAD_RGB);
	// 
	// 	if (image == NULL)
	// 	{
	// 		cerr << "Failed to load image" << endl;
	// 		exit(-2);
	// 	}
	// 
	// 	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
	// 	glGenerateMipmap(GL_TEXTURE_2D);
	// 
	// 	SOIL_free_image_data(image);
	// 	glBindTexture(GL_TEXTURE_2D, 0);

	GLuint projection_loc = glGetUniformLocation(program, "projection_matrix");
	GLuint view_loc = glGetUniformLocation(program, "view_matrix");
	GLuint model_loc = glGetUniformLocation(program, "model_matrix");

	glm::mat4 model, view, projection;
	model = glm::rotate(model, glm::radians(45.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	view = glm::lookAt(glm::vec3(0.0f, 0.0f, 2.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);

	glUniformMatrix4fv(projection_loc, 1, GL_FALSE, glm::value_ptr(projection));
	glUniformMatrix4fv(view_loc, 1, GL_FALSE, glm::value_ptr(view));
	glUniformMatrix4fv(model_loc, 1, GL_FALSE, glm::value_ptr(model));

	glViewport(0, 0, 800, 600);

	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glBindVertexArray(vao);

		glActiveTexture(GL_TEXTURE0);
		glUniform1i(glGetUniformLocation(program, "texture"), 0);
		glBindTexture(GL_TEXTURE_2D, texture);

		glDrawArrays(GL_TRIANGLES, 0, 36);
		glFlush();
		glfwSwapBuffers(window);
	}

	glfwTerminate();

	return 0;
#endif

#if 1
	static struct {
		GLuint vertex_buffer, element_buffer, color_buffer;
		GLuint vertex_shader, fragment_shader, program;
		//用于保存CPU端的object名称

		struct {
			GLint position;
			GLint inColor;
		} attributes;
		//用于保存GPU端attribute变量的地址
	} names;

	static const GLfloat position_data[] = {
		-0.5, 0.5, 0.0,
		-0.5, -0.5, 0.0,
		0.5, -0.5, 0.0,
		0.5, 0.5, 0.0
	};
	static const GLfloat color_data[] = {
		1.0, 0.0, 0.0, 1.0,
		0.0, 1.0, 0.0, 1.0,
		0.0, 0.0, 1.0, 1.0
	};
	static const GLfloat uv_data[] = {
		0.0, 1.0, 
		0.0, 0.0,
		1.0, 0.0, 
		1.0, 1.0
	};
	static const GLushort element_data[] = { 0, 1, 2, 0, 2, 3 };

	static void infoLog(GLuint object, PFNGLGETSHADERIVPROC glGet__iv, PFNGLGETSHADERINFOLOGPROC glGet__InfoLog)
	{
		GLint log_length;
		char *log;

		glGet__iv(object, GL_INFO_LOG_LENGTH, &log_length);
		log = (char *)malloc(log_length);
		glGet__InfoLog(object, log_length, NULL, log);
		fprintf(stderr, "%s", log);
		free(log);
	}

	void *readShader(const char *filename, GLint *length)
	{
		FILE *f = fopen(filename, "r");
		void *buffer;

		if (!f) {
			fprintf(stderr, "Unable to open %s for reading\n", filename);
			return NULL;
		}

		fseek(f, 0, SEEK_END);
		*length = ftell(f);
		fseek(f, 0, SEEK_SET);

		buffer = malloc(*length + 1);
		*length = fread(buffer, 1, *length, f);
		fclose(f);
		((char*)buffer)[*length] = '\0';

		return buffer;
	}

	static GLuint initShader(GLenum type, const char *filename)
	{
		GLint length;
		GLchar *source = (GLchar *)readShader(filename, &length);
		GLuint shader;
		GLint shader_ok;

		if (!source)
			return 0;

		shader = glCreateShader(type);
		//创建shader object
		glShaderSource(shader, 1, (const GLchar**)&source, &length);
		//导入shader的代码
		//count - string的行数
		//length - 指向包含string每行字数的数组
		free(source);
		glCompileShader(shader);
		//编译shader代码

		glGetShaderiv(shader, GL_COMPILE_STATUS, &shader_ok);
		//查询shader的状态，导出可能的编译错误
		if (!shader_ok) {
			fprintf(stderr, "Failed to compile %s:\n", filename);
			infoLog(shader, glGetShaderiv, glGetShaderInfoLog);
			glDeleteShader(shader);
			getchar();
		}
		return shader;
	}

	static void installShaders(void)
	{
		names.vertex_shader = initShader(GL_VERTEX_SHADER, "test1.vsh");
		names.fragment_shader = initShader(GL_FRAGMENT_SHADER, "test1.fsh");

		GLint program_ok;
		names.program = glCreateProgram();
		glAttachShader(names.program, names.vertex_shader);
		glAttachShader(names.program, names.fragment_shader);
		//把shader依附在同一个program上，以连接两个shader
		glLinkProgram(names.program);
		//链接program，在GPU端创建相应可执行文件，并初始化uniform变量及其地址
		glGetProgramiv(names.program, GL_LINK_STATUS, &program_ok);
		//查询program的状态，并导出可能的错误
		if (!program_ok) {
			fprintf(stderr, "Failed to link shader program:\n");
			infoLog(names.program, glGetProgramiv, glGetProgramInfoLog);
			glDeleteProgram(names.program);
			getchar();
		}
		glUseProgram(names.program);
		//激活program后才能为shader指定uniform变量的值
	}

	static void initBuffers(void)
	{
		names.attributes.position = glGetAttribLocation(names.program, "position");
		names.attributes.inColor = glGetAttribLocation(names.program, "inColor");
		//获取GPU端attribute变量的地址保存在本地变量中，用于值的传递

		glGenBuffers(1, &names.vertex_buffer);
		//产生1个buffer object的名称，并分配显存空间
		glBindBuffer(GL_ARRAY_BUFFER, names.vertex_buffer);
		//把产生的buffer object与相应target绑定，以改变其值
		glBufferData(GL_ARRAY_BUFFER, sizeof(position_data), position_data, GL_STATIC_DRAW);
		//GL_STATIC_DRAW其他可用参数：
		//STATIC - 长时间不更改的值		DYNAMIC - 需要频繁改变的值		STREAM - 需要偶尔重写整个buffer的值
		//DRAW - 保存于GPU用于绘制的值		READ - 保存于CPU用于读取的值		COPY - 折衷
		glVertexAttribPointer(names.attributes.position, 3, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 3, (void*)0);
		glEnableVertexAttribArray(names.attributes.position);

		glGenBuffers(1, &names.color_buffer);
		glBindBuffer(GL_ARRAY_BUFFER, names.color_buffer);
		glBufferData(GL_ARRAY_BUFFER, sizeof(color_data), color_data, GL_STATIC_DRAW);
		glVertexAttribPointer(names.attributes.inColor, 4, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 4, (void*)0);
		glEnableVertexAttribArray(names.attributes.inColor);

		glGenBuffers(1, &names.element_buffer);
		glBindBuffer(GL_ARRAY_BUFFER, names.element_buffer);
		glBufferData(GL_ARRAY_BUFFER, sizeof(element_data), element_data, GL_STATIC_DRAW);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, names.element_buffer);
	}

	static void idleFunc(void)
	{
	}

	static void displayFunc(void)
	{
		glClearColor(1.0, 1.0, 1.0, 1.0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glDrawElements(GL_TRIANGLE_STRIP, 6, GL_UNSIGNED_SHORT, (void*)0);

		glutSwapBuffers();
	}

	int main(int argc, char** argv)
	{
		glutInit(&argc, argv);
		glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
		glutInitWindowSize(400, 400);
		glutCreateWindow("Hello World");
		glutIdleFunc(&idleFunc);
		glutDisplayFunc(&displayFunc);

		glewInit();
		if (!GLEW_VERSION_2_0) {
			fprintf(stderr, "OpenGL 2.0 not available\n");
			getchar();
		}
		//与glew扩展库相关的函数要在glewInit()后执行
		installShaders();
		initBuffers();

		glutMainLoop();
		return 0;
	}

#endif
#if 0
#include "RenderSystem.h"
#include <memory>

	int main(int argc, const char **argv)
	{
		auto app = std::make_shared<RenderSystem>();

		app->Run(app);

		return 0;
	}
#endif