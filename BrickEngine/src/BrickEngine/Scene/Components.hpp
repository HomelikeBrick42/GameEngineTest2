#pragma once

#include "BrickEngine/Core/Base.hpp"

#include "BrickEngine/Scene/EntityScript.hpp"

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

}
