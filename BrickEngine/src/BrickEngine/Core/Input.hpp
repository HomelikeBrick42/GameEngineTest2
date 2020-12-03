#pragma once

#include "BrickEngine/Core/Base.hpp"

#include "BrickEngine/Core/KeyCodes.hpp"
#include "BrickEngine/Events/Event.hpp"

#include "BrickEngine/Core/Window.hpp"

namespace BrickEngine {

	class Input
	{
	public:
		Input() = delete;
		
		static void Init(Window* window);
		static void EndFrame();

		static bool GetKey(KeyCode key);
		static bool GetKeyUp(KeyCode key);
		static bool GetKeyDown(KeyCode key);

		static bool GetMouseButton(MouseButton button);
		static bool GetMouseButtonUp(MouseButton button);
		static bool GetMouseButtonDown(MouseButton button);

		static glm::vec2 GetMouseScroll();
		static glm::vec2 GetMousePosition();
		static glm::vec2 GetMouseDelta();

		static void OnEvent(Event& e);
	};

}
