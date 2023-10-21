#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <string>

class Window
{
public:

	Window(int widht, int height, const std::string& name, bool vSync);
	~Window();

	void clear(float x, float y, float z);
	void update();
	void closed();

	GLFWwindow* getWindow() { return m_window; }

private:

	void init();

	int m_widht;
	int m_height;
	bool m_vSync;

	std::string m_name;

	GLFWwindow* m_window;
};

