#include "Window.h"

Window::Window(int widht, int height, const std::string& name, bool vSync)
	: m_widht(widht)
	, m_height(height)
	, m_name(name)
	, m_vSync(vSync)
	, m_window(nullptr)
{
	init();
}

Window::~Window()
{
	glfwTerminate();

	if (m_window)
		glfwDestroyWindow(m_window);
}

void Window::clear(float x, float y, float z)
{
}

void Window::update()
{
}

void Window::closed()
{
}

void Window::init()
{
	glfwInit();

	//glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	//glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	// set GLFW to not work with OpenGL
	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

	// set GLFW to not resizable
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

	m_window = glfwCreateWindow(m_widht, m_height, m_name.c_str(), nullptr, nullptr);

	//glfwSetKeyCallback(m_Window, key_callback);
	//glfwSetFramebufferSizeCallback(m_Window, framebuffer_size_callback);
	//glfwMakeContextCurrent(m_Window);

	if (m_vSync)
	{
		glfwSwapInterval(1);
	}
}


