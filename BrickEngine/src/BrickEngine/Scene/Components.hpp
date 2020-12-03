#pragma once

#include "BrickEngine/Core/Base.hpp"

#include "BrickEngine/Scene/EntityScript.hpp"

#include "BrickEngine/Renderer/Mesh.hpp"
#include "BrickEngine/GraphicsObjects/Shader.hpp"

namespace BrickEngine {

	struct TagComponent
	{
		std::string Name;

		TagComponent(const std::string& name = "Entity")
			: Name(name) {}
	};

	struct TransformComponent
	{
		glm::vec3 Position;
		glm::vec3 Rotation;
		glm::vec3 Scale;

		TransformComponent(const glm::vec3& position = glm::vec3(0.0f))
			: Position(position), Rotation(0.0f), Scale(1.0f) {}

		glm::mat4 GetMatrix() const
		{
			return
				glm::translate(glm::mat4(1.0f), Position) *
				(glm::mat4)glm::quat(glm::radians(Rotation)) *
				glm::scale(glm::mat4(1.0f), Scale);
		}
	};

	struct NativeScriptComponent
	{
		NativeEntityScript* Instance = nullptr;
		void(*InstantiateScript)(NativeEntityScript*&, Entity) = nullptr;
		void(*DestroyScript)(NativeEntityScript*&) = nullptr;

		template<typename T, typename... Args>
		void Bind(Args&&... args)
		{
			if (Instance)
				DestroyScript(Instance);
			InstantiateScript = [](NativeEntityScript*& script, Entity entity) -> void
			{
				script = new T(args...);
				script->m_Entity = entity;
				script->OnCreate();
			};
			DestroyScript = [](NativeEntityScript*& script) -> void
			{
				script->OnDestroy();
				delete script;
				script = nullptr;
			};
		}
	};

	struct PerspectiveCameraComponent
	{
		float Width, Height, Fov, Near, Far;
		bool FixedAspect;
		bool MainCamera;

		PerspectiveCameraComponent()
			: Width(1280.0f), Height(720.0f), Fov(45.0f), Near(0.001f), Far(1000.0f), FixedAspect(true), MainCamera(false) {}
		PerspectiveCameraComponent(float width, float height, float fov, float _near = 0.001f, float _far = 1000.0f, bool fixedAspect = false)
			: Width(width), Height(height), Fov(fov), Near(_near), Far(_far), FixedAspect(fixedAspect), MainCamera(false) {}
		PerspectiveCameraComponent(float fov, float _near = 0.001f, float _far = 1000.0f, bool fixedAspect = false)
			: Width(0), Height(0), Fov(fov), Near(_near), Far(_far), FixedAspect(fixedAspect), MainCamera(false) {}

		glm::mat4 GetMatrix() const
		{
			return glm::perspectiveLH(glm::radians(Fov), Width / Height, Near, Far);
		}
	};

	struct OrthographicCameraComponent
	{
		float Left, Right, Top, Bottom, Near, Far;
		bool FixedAspect;
		bool MainCamera;

		OrthographicCameraComponent()
			: Left(-1.0f), Right(1.0f), Top(1.0f), Bottom(-1.0f), Near(-1.0f), Far(1.0f), FixedAspect(true), MainCamera(false) {}
		OrthographicCameraComponent(float left, float right, float top, float bottom, float _near = -1.0f, float _far = 1.0f, bool fixedAspect = true)
			: Left(left), Right(right), Top(top), Bottom(bottom), Near(_near), Far(_far), FixedAspect(fixedAspect), MainCamera(false) {}
		OrthographicCameraComponent(float aspect, float _near = -1.0f, float _far = 1.0f, bool fixedAspect = false)
			: Left(-aspect), Right(aspect), Top(1.0f), Bottom(-1.0f), Near(_near), Far(_far), FixedAspect(fixedAspect), MainCamera(false) {}

		glm::mat4 GetMatrix() const
		{
			return glm::orthoLH(Left, Right, Bottom, Top, Near, Far);
		}
	};

	struct MeshRendererComponent
	{
		Ref<Mesh> Mesh;
		Ref<Shader> Shader;
		glm::vec4 Color;

		MeshRendererComponent()
			: Mesh(nullptr), Shader(nullptr), Color(1.0f) {}
		MeshRendererComponent(const Ref<BrickEngine::Mesh>& mesh, const Ref<BrickEngine::Shader>& shader, const glm::vec4& color)
			: Mesh(mesh), Shader(shader), Color(color) {}
	};

}
