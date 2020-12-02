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
		RenderCommand::SetClearColor(0.1f);

		m_Entity = m_Scene.CreateEntity("Test Entity");
		m_Entity.AddComponent<NativeScriptComponent>().Bind<RotateScript>();

		const glm::vec3 vertices[] = {
			glm::vec3( 0.0f,  0.5f, 0.0f),
			glm::vec3( 0.5f, -0.5f, 0.0f),
			glm::vec3(-0.5f, -0.5f, 0.0f)
		};
		m_VertexBuffer = VertexBuffer::Create(vertices, sizeof(vertices), {
			{ ShaderDataType::Float3, "a_Position" }
		});

		const uint32_t indices[] = {
			0, 1, 2
		};
		m_IndexBuffer = IndexBuffer::Create(indices, (uint32_t)std::size(indices));

		m_Shader = Shader::Create("assets/shaders/FlatColor.glsl");
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
		RenderCommand::Clear();

		m_Scene.DrawScene();

		m_Shader->Bind();
		m_Shader->SetFloat4("u_Color", glm::vec4(0.2f, 0.3f, 0.8f, 1.0f));
		m_VertexBuffer->Bind();
		m_IndexBuffer->Bind();
		RenderCommand::DrawIndexed(m_IndexBuffer->GetCount());
	}

	void SandboxLayer::OnImGuiRender()
	{
		ImGui::Begin("Test Window");
		ImGui::Text("FPS: %.3f\nFrame Time: %.3fms", 1.0f / m_Delta, m_Delta * 1000.0f);
		ImGui::End();
	}

	void SandboxLayer::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowResizeEvent>([&](WindowResizeEvent& e)
			{
				RenderCommand::SetViewport(0, 0, e.GetWidth(), e.GetHeight());
				m_Scene.OnViewportResize(e.GetWidth(), e.GetHeight());
				return false;
			});
	}

}
