#pragma once

#include "BrickEngine/Core/Base.hpp"

#include "BrickEngine/Core/KeyCodes.hpp"

#include "BrickEngine/Events/Event.hpp"

namespace BrickEngine {

	class Input
	{
	public:
		Input() = delete;
		
		static void Init();
		static void EndFrame();

		static bool GetKey(KeyCode key);
		static bool GetKeyUp(KeyCode key);
		static bool GetKeyDown(KeyCode key);

		static void OnEvent(Event& e);
	};

}
