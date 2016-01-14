#ifndef RENDERSYSTEM_H
#define RENDERSYSTEM_H

#include "Application.h"
#include "Polygon.h"
#include "Triangle.h"
#include "Camera.h"
class RenderSystem:public Application
{
public:
	RenderSystem();
	~RenderSystem();

public:
	void v_InitInfo();
	void v_Init();
	void v_Update();
	void v_Render();
	void v_Shutdown();

	/////////////////////////////////Key and Mouse//////////////////////////////////
	void v_Movement(GLFWwindow *Triangle);
	void v_KeyCallback(GLFWwindow* Triangle, int key, int scancode, int action, int mode);
	void v_MouseCallback(GLFWwindow* Triangle, double xpos, double ypos);
	void v_ScrollCallback(GLFWwindow* Triangle, double xoffset, double yoffset);
private:
	PolygonA m_Polygon;
	Triangle m_Triangle;
	Camera m_Camera;
};

#endif