#pragma once

#include "BrickEngine/Core/Base.hpp"

#include <entt/entt.hpp>

namespace BrickEngine {

	class Scene
	{
		friend class Entity;
	public:
		Scene();
		~Scene();

		Entity CreateEntity(const std::string& name = "Entity");
		void DestroyEntity(Entity& entity);

		void DrawScene();

		void OnUpdate(float dt);
		void OnViewportResize(uint32_t width, uint32_t height);
	private:
		entt::registry m_Registry;
	};

}
