#pragma once

#include "BrickEngine/Core/Base.hpp"

#include "BrickEngine/Events/Event.hpp"

namespace BrickEngine {

	class Layer
	{
	public:
		virtual ~Layer() = default;

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate(float dt) {}
		virtual void OnRender() {}
		virtual void OnEvent(Event& e) {}
		virtual void OnImGuiRender() {}
	protected:
		Layer() = default;
	};

}
