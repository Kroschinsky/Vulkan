#pragma once

#include <fstream>
#include <vector>

const int MAX_FRAME_DRAWS = 2;

const std::vector<const char*> deviceExtensions = 
{
	VK_KHR_SWAPCHAIN_EXTENSION_NAME
};

const std::vector<const char*> validationLayers =
{
	"VK_LAYER_KHRONOS_validation"
};

struct QueueFamilyIndices
{
	int graphicsFamily = -1;		// Location of Graphics Queue Family
	int presentFamily = -1;			// Location of Presentation Queue Family

	// Check if queue family is valid
	bool isValid()
	{
		return graphicsFamily >= 0 && presentFamily >= 0;
	}
};

struct SwapChainSupportDetails 
{
	VkSurfaceCapabilitiesKHR capabilities;						// Surface properties
	std::vector<VkSurfaceFormatKHR> formats;					// Surface image formats, RGBA
	std::vector<VkPresentModeKHR> presentModes;					// How images should be presented to screen
};

struct SwapChainImage
{
	VkImage image;
	VkImageView imageView;
};

static std::vector<char> readFile(const std::string& filename) 
{
	// Open stream from file
	std::ifstream file(filename, std::ios::ate | std::ios::binary);

	if (!file.is_open()) 
	{
		throw std::runtime_error("failed to open file!");
	}

	// Get current read position and use to resize file buffer
	size_t fileSize = (size_t)file.tellg();
	std::vector<char> buffer(fileSize);

	// Move read position to the start of the file
	file.seekg(0);

	// Read all data into the buffer
	file.read(buffer.data(), fileSize);

	// Close the file
	file.close();

	return buffer;
}

