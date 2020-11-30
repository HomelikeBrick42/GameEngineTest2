#include "pch.hpp"
#include "SandboxLayer.hpp"

using namespace BrickEngine;

namespace Sandbox {

	class RotateScript : public NativeEntityScript
	{
	public:
		void OnCreate() override
		{
			m_Transform = &GetOrAddComponent<TransformComponent>();
		}

		void OnUpdate(float dt) override
		{
			m_Transform->Rotation.z += 90.0f * dt;
		}
	private:
		TransformComponent* m_Transform = nullptr;
	};

	void SandboxLayer::OnAttach()
	{
		m_Entity = m_Scene.CreateEntity("Test Entity");
		m_Entity.AddComponent<NativeScriptComponent>().Bind<RotateScript>();
	}

	void SandboxLayer::OnDetach()
	{
	}

	void SandboxLayer::OnUpdate(float dt)
	{
		m_Delta = dt;
		m_Scene.OnUpdate(dt);
	}

	void SandboxLayer::OnRender()
	{
		m_Scene.DrawScene();
	}

	void SandboxLayer::OnImGuiRender()
	{
		ImGui::Begin("Test Window");
		ImGui::Text("Frame Time: %.3fms", m_Delta * 1000.0f);
		ImGui::End();
	}

	void SandboxLayer::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowResizeEvent>([&](WindowResizeEvent& e)
			{
				m_Scene.OnViewportResize(e.GetWidth(), e.GetHeight());
				return false;
			});
	}

}
