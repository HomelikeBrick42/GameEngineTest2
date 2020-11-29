#pragma once

#include "BrickEngine/Core/Window.hpp"

#ifdef BRICKENGINE_PLATFORM_WINDOWS

#include <GLFW/glfw3.h>

namespace BrickEngine {

	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowProps& props);
		~WindowsWindow();

		virtual void SetSize(const glm::uvec2& size) override;
		virtual glm::uvec2 GetSize() const override { return { m_Data.Width, m_Data.Height }; }

		virtual void SetPos(const glm::ivec2& pos) override;
		virtual glm::ivec2 GetPos() const override { return { m_Data.XPos, m_Data.YPos }; }

		virtual void Focus() const override;
		virtual void SetVisible(bool visible)override;
		virtual void SetTitle(const std::string& title) override;

		virtual void PollEvents() const override;

		virtual void* GetNativeWindowHandle() override;

		virtual void SetEventCallbackFn(EventCallbackFn fn) override;
	private:
		GLFWwindow* m_Window = nullptr;

		struct WindowData
		{
			uint32_t Width, Height;
			int32_t XPos, YPos;
		};

		WindowData m_Data;
	};

}

#endif
