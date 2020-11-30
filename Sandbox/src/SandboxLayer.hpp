#pragma once

#include "pch.hpp"

namespace Sandbox {

	class SandboxLayer : public BrickEngine::Layer
	{
	public:
		virtual void OnAttach();
		virtual void OnDetach();
		virtual void OnUpdate(float dt);
		virtual void OnRender();
		virtual void OnImGuiRender();
		virtual void OnEvent(BrickEngine::Event& e);
	private:
		BrickEngine::Scene m_Scene;
		BrickEngine::Entity m_Entity;
	};

}
