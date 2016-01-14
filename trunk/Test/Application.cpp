#include "Application.h"


Application::Application()
{
}


Application::~Application()
{
}
void Application::v_KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
	if (key == GLFW_KEY_C && action == GLFW_PRESS)
		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
}

std::shared_ptr<Application> Application::app;

////////////////////////////////////////////////////////////////////////////////////////

void Application::glfw_key(GLFWwindow * window, int key, int scancode, int action, int mode)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);


}

////////////////////////////////////////////////////////////////////////////////////////

void Application::glfw_mouse(GLFWwindow* window, double xpos, double ypos)
{

}

////////////////////////////////////////////////////////////////////////////////////////

void Application::glfw_scroll(GLFWwindow* window, double xoffset, double yoffset)
{

}

////////////////////////////////////////////////////////////////////////////////////////
void Application::glfw_mouseButton(GLFWwindow *window, int x, int y, int z)
{
	//TwEventMouseButtonGLFW(x, y);
}
void Application::glfw_char(GLFWwindow *window, unsigned int x)
{
//	TwEventCharGLFW(x, GLFW_PRESS);
}

////////////////////////////////////////////////////////////////////////////////////////


void Application::Run(std::shared_ptr<Application> the_app)
{
	app = the_app;

	std::cout << "Starting GLFW context" << std::endl;
	if (!glfwInit())
	{
		std::cerr << "Failed to initialize GLFW" << std::endl;
		return;
	}

	v_InitInfo();

	//Add this to use the debug output
	glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, true);


	GLFWwindow *window = glfwCreateWindow(windowInfo.Width, windowInfo.Height,
		windowInfo.title.c_str(), nullptr, nullptr);
	glfwSetWindowPos(window, windowInfo.posX, windowInfo.posY);
	glfwMakeContextCurrent(window);


	glfwSetCursorPosCallback(window, glfw_mouse);          // - Directly redirect GLFW mouse position events to AntTweakBar
	glfwSetScrollCallback(window, glfw_scroll);    // - Directly redirect GLFW mouse wheel events to AntTweakBar
	glfwSetKeyCallback(window, glfw_key);                         // - Directly redirect GLFW key events to AntTweakBar

	//glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
	// GLFW Options
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	if (window == NULL)
	{
		std::cerr << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return;
	}
	glewExperimental = GL_TRUE;

	//Check the GLSL and OpenGL status 
	if (glewInit() != GLEW_OK)
	{
		std::cerr << "Failed to initialize GLEW" << std::endl;
		return;
	}
	const GLubyte *renderer = glGetString(GL_RENDERER);
	const GLubyte *vendor = glGetString(GL_VENDOR);
	const GLubyte *version = glGetString(GL_VERSION);
	const GLubyte *glslVersion = glGetString(GL_SHADING_LANGUAGE_VERSION);

	m_GLRenderer = (const char *)renderer;
	m_GLVersion = (const char *)version;
	m_GLSLVersion = (const char *)glslVersion;

	GLint major, minor;
	glGetIntegerv(GL_MAJOR_VERSION, &major);
	glGetIntegerv(GL_MINOR_VERSION, &minor);
	std::cout << "GL Vendor    :" << vendor << std::endl;
	std::cout << "GL Renderer  : " << renderer << std::endl;
	std::cout << "GL Version (std::string)  : " << version << std::endl;
	std::cout << "GL Version (integer) : " << major << "." << minor << std::endl;
	std::cout << "GLSL Version : " << glslVersion << std::endl;
	std::cout << "--------------------------------------------------------------------------------"
		<< std::endl;
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, major); //opengl 4.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, minor);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);

	// Create a GLFWwindow object that we can use for GLFW's functions
	v_Init();



	while (!glfwWindowShouldClose(window))
	{
		int sw, sh;
		glfwGetWindowSize(window, &sw, &sh);

		glViewport(0, 0, sw, sh);

		glfwPollEvents();
		v_Movement(window);

		v_Update();
		//Render for the object
		v_Render();

		glfwSwapBuffers(window);
	}
	v_Shutdown();


	glfwTerminate();
}

float Application::GetAspect()
{
	return static_cast<float>(ScreenWidth) / static_cast<float>(ScreenHeight);
}

int Application::GetScreenWidth()
{
	return ScreenWidth;
}

int Application::GetScreenHeight()
{
	return ScreenHeight;
}