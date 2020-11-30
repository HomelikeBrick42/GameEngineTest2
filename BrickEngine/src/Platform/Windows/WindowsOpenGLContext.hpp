#pragma once

#include "BrickEngine/GraphicsObjects/GraphicsContext.hpp"

#ifdef BRICKENGINE_PLATFORM_WINDOWS

#include <GLFW/glfw3.h>

namespace BrickEngine {

	class WindowsOpenGLContext : public GraphicsContext
	{
	public:
		WindowsOpenGLContext(GLFWwindow* window);
		~WindowsOpenGLContext() = default;

		virtual void Bind() override;
		virtual void SwapBuffers() override;
	private:
		GLFWwindow* m_Window;
	};

}

#endif
