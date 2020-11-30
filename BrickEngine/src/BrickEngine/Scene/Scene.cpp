#include "brickpch.hpp"
#include "BrickEngine/Scene/Scene.hpp"

#include "BrickEngine/Scene/Entity.hpp"

#include "BrickEngine/Scene/Components.hpp"

#pragma warning(push)
#pragma warning(disable : 4267)

namespace BrickEngine {

    Scene::Scene()
    {
    }

    Scene::~Scene()
    {
        m_Registry.view<NativeScriptComponent>().each([&](entt::entity id, NativeScriptComponent& nsc)
            {
                if (nsc.Instance)
                    nsc.DestroyScript(nsc.Instance);
            });
    }

    Entity Scene::CreateEntity(const std::string& name)
    {
        Entity entity(m_Registry.create(), this);
        entity.AddComponent<TagComponent>(name);
        entity.AddComponent<TransformComponent>();
        return entity;
    }

    void Scene::DestroyEntity(Entity& entity)
    {
        BRICKENGINE_CORE_ASSERT(entity.m_Scene == this, "Entity is not of this scene!");
        if (entity.HasComponent<NativeScriptComponent>())
        {
            NativeScriptComponent& nsc = entity.GetComponent<NativeScriptComponent>();
            if (nsc.DestroyScript)
                nsc.DestroyScript(nsc.Instance);
        }
        m_Registry.destroy(entity);
    }

    void Scene::DrawScene()
    {
    }

    void Scene::OnUpdate(float dt)
    {
        m_Registry.view<NativeScriptComponent>().each([&](entt::entity id, NativeScriptComponent& nsc)
            {
                if (nsc.InstantiateScript)
                {
                    if (!nsc.Instance)
                        nsc.InstantiateScript(nsc.Instance, Entity(id, this));
                    nsc.Instance->OnUpdate(dt);
                }
            });
    }

    void Scene::OnViewportResize(uint32_t width, uint32_t height)
    {
        float aspect = (float)width / (float)height;
        m_Registry.view<PerspectiveCameraComponent>().each([&](entt::entity id, PerspectiveCameraComponent& pc)
            {
                if (!pc.FixedAspect)
                {
                    pc.Width = (float)width;
                    pc.Height = (float)height;
                }
            });
        m_Registry.view<OrthographicCameraComponent>().each([&](entt::entity id, OrthographicCameraComponent& oc)
            {
                if (!oc.FixedAspect)
                {
                    oc.Left = -aspect;
                    oc.Right = aspect;
                }
            });
    }

}

#pragma warning(pop)
