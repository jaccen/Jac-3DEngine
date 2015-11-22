#ifndef __APP_H_
#define __APP_H_

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <string>
#include <windows.h>
#include <memory>

#ifdef _WIN32
const int ScreenWidth = static_cast<int>(GetSystemMetrics(SM_CXSCREEN) * 0.75);
const int ScreenHeight = static_cast<int>(GetSystemMetrics(SM_CYSCREEN) * 0.75);
const int PosX = (GetSystemMetrics(SM_CXSCREEN) - ScreenWidth);
const int PosY = (GetSystemMetrics(SM_CYSCREEN) - ScreenHeight);
#else
const int ScreenWidth = 1200;
const int ScreenHeight = 1000;
const int PosX = 300;
const int PosY = 100;
#endif


class Application
{
public:
	Application();
	virtual ~Application();
public:
	void Run(std::shared_ptr<Application> the_app);

	//Override
	virtual void v_InitInfo() = 0;
	virtual void v_Init() = 0;
	virtual void v_Update() = 0;
	virtual void v_Render() = 0;
	virtual void v_Shutdown() = 0;

	virtual void v_KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mode);
	virtual void v_Movement(GLFWwindow *window) {}
	virtual void v_MouseCallback(GLFWwindow* window, double xpos, double ypos) {}
	virtual void v_ScrollCallback(GLFWwindow* window, double xoffset, double yoffset) {}

protected:
	struct WindowInfo
	{
		WindowInfo() :title("OpenGL BlueBook : "),
			Width(ScreenWidth),
			Height(ScreenHeight),
			posX(PosX),
			posY(PosY) {}

		std::string title;
		int Width;
		int Height;
		int posX, posY;
	}windowInfo;

	float GetAspect();
	int GetScreenWidth();
	int GetScreenHeight();

	std::string GetGLRenderer()
	{
		return m_GLRenderer;
	}
	std::string GetGLVersion()
	{
		return m_GLVersion;
	}
	std::string GetGLSLVersion()
	{
		return m_GLSLVersion;
	}
private:
	static  std::shared_ptr<Application> app;

	static void glfw_key(GLFWwindow * window, int key, int scancode, int action, int mode);
	static void glfw_mouse(GLFWwindow* window, double xpos, double ypos);
	static void glfw_scroll(GLFWwindow* window, double xoffset, double yoffset);
	static void glfw_mouseButton(GLFWwindow *window, int x, int y, int z);
	static void glfw_char(GLFWwindow *window, unsigned int x);

	std::string m_GLRenderer;
	std::string m_GLVersion;
	std::string m_GLSLVersion;
};

#endif