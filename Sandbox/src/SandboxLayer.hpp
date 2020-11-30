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
		float m_Delta = 0.0f;
	private:
		BrickEngine::Scene m_Scene;
		BrickEngine::Entity m_Entity;
	};

}
