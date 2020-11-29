#pragma once

#include "BrickEngine/Core/Base.hpp"

#include "BrickEngine/Events/Event.hpp"

namespace BrickEngine {

	struct WindowProps
	{
		std::string Title = "BrickEngine Window";
		int32_t Width = 1280, Height = 720;
		bool Fullscreen = false;
		bool Resizeable = false;

		WindowProps() = default;
		WindowProps(const std::string& title, int32_t width, int32_t height, bool fullscreen = false, bool resizeable = true)
			: Title(title), Width(width), Height(height), Fullscreen(fullscreen), Resizeable(resizeable) {}
		WindowProps(const std::string& title)
			: Title(title), Width(-1), Height(-1), Fullscreen(true), Resizeable(false) {}
	};

	class Window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;
	public:
		virtual ~Window() = default;

		virtual void SetSize(const glm::uvec2& size) = 0;
		virtual glm::uvec2 GetSize() const = 0;

		virtual void SetPos(const glm::ivec2& pos) = 0;
		virtual glm::ivec2 GetPos() const = 0;

		virtual void Focus() const = 0;
		virtual void SetVisible(bool visible) = 0;
		virtual void SetTitle(const std::string& title) = 0;

		virtual void PollEvents() const = 0;

		virtual void* GetNativeWindowHandle() = 0;

		virtual void SetEventCallbackFn(EventCallbackFn fn) = 0;

		static Scope<Window> Create(const WindowProps& props);
	protected:
		Window() = default;
	};

}
