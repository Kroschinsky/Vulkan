#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/glm.hpp>
#include <glm/mat4x4.hpp>

#include "Window.h"
#include "VulkanRender.h"

#include <iostream>

int main()
{
	// create window
	auto window = new Window(800, 600, "Vulkan App", false);
	auto glwfWindow = window->getWindow();

	// create vulkan render
	auto vulkanRender = new VulkanRender();
	if (vulkanRender->init(glwfWindow) == EXIT_FAILURE)
		return EXIT_FAILURE;

	while (!glfwWindowShouldClose(glwfWindow))
	{
		glfwPollEvents();

		vulkanRender->draw();
	}

	delete vulkanRender;
	delete window;	

	return EXIT_SUCCESS;
}