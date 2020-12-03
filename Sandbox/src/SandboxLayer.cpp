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
			m_Transform->Rotation.z += 45.0f * dt;
		}
	private:
		TransformComponent* m_Transform = nullptr;
	};

	void SandboxLayer::OnAttach()
	{
		RenderCommand::SetClearColor(0.1f);

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

		Entity entity = m_Scene.CreateEntity("Test Entity");
		entity.AddComponent<MeshRendererComponent>(m_VertexBuffer, m_IndexBuffer, m_Shader, glm::vec4(0.2f, 0.3f, 0.8f, 1.0f));
		entity.AddComponent<NativeScriptComponent>().Bind<RotateScript>();

		Entity camera = m_Scene.CreateEntity("Camera");
		camera.GetComponent<TransformComponent>().Position.z = -3.0f;
		camera.AddComponent<PerspectiveCameraComponent>(45.0f).MainCamera = true;
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
