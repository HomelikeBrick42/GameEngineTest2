#include "brickpch.hpp"
#include "Platform/Windows/WindowsOpenGLContext.hpp"

#ifdef BRICKENGINE_PLATFORM_WINDOWS

#include <glad/glad.h>

namespace BrickEngine {

	WindowsOpenGLContext::WindowsOpenGLContext(GLFWwindow* window)
		: m_Window(window)
	{
		BRICKENGINE_CORE_ASSERT(m_Window, "Window is nullptr!");
	}

	void WindowsOpenGLContext::Bind()
	{
		glfwMakeContextCurrent(m_Window);
		int32_t success = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		BRICKENGINE_CORE_ASSERT(success, "Failed to initalize GLAD!");
	}

	void WindowsOpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(m_Window);
	}

}

#endif
