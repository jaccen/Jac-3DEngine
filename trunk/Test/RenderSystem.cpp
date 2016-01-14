#include <GL/glew.h>
#include "RenderSystem.h"

RenderSystem::RenderSystem()
{
}




RenderSystem::~RenderSystem()
{

}

void RenderSystem::v_InitInfo()
{
	windowInfo.title += "Triangle";
}

void RenderSystem::v_Init()
{
	m_Triangle.Init();
	m_Camera.SetPos(glm::vec3(0.0f, 1.0f, 3.0f));
}

void RenderSystem::v_Update()
{
	static GLfloat lastFrame = static_cast<float>(glfwGetTime());
	GLfloat currentFrame = static_cast<float>(glfwGetTime());
	GLfloat deltaTime = currentFrame - lastFrame;
	lastFrame = currentFrame;

	m_Camera.update(deltaTime);
}

void RenderSystem::v_Render()
{

	static const GLfloat black[] = { 0.0f, 0.0f, 0.0f, 1.0f };
	glClearBufferfv(GL_COLOR, 0, &black[0]);


	static MvpMatrix matrix;
	matrix.view = m_Camera.GetViewMatrix();
	matrix.proj = glm::perspective(m_Camera.GetZoom(), GetAspect(), 0.1f, 1000.0f);
	matrix.model = glm::mat4(1.0f);
	m_Triangle.Render(matrix);

}

void RenderSystem::v_Shutdown()
{
	m_Triangle.Shutdown();
}

/////////////////////////////////Key and Mouse//////////////////////////////////
void RenderSystem::v_Movement(GLFWwindow *Triangle)
{
	m_Camera.movement(Triangle);
}
void RenderSystem::v_KeyCallback(GLFWwindow* Triangle, int key, int scancode, int action, int mode)
{
	m_Camera.key_callback(Triangle, key, scancode, action, mode);
}

void RenderSystem::v_MouseCallback(GLFWwindow* Triangle, double xpos, double ypos)
{
	m_Camera.mouse_callback(Triangle, xpos, ypos);
}

void RenderSystem::v_ScrollCallback(GLFWwindow* Triangle, double xoffset, double yoffset)
{
	m_Camera.scroll_callback(Triangle, xoffset, yoffset);
}