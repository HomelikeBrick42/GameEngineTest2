#include "brickpch.hpp"
#include "BrickEngine/Scene/Scene.hpp"

#include "BrickEngine/Scene/Entity.hpp"

#include "BrickEngine/Scene/Components.hpp"

#include "BrickEngine/Renderer/RenderCommand.hpp"

#include "BrickEngine/Core/Application.hpp"

#pragma warning(push)
#pragma warning(disable : 4267)

namespace BrickEngine {

    static void OnPerspectiveCameraAdded(entt::registry& registry, entt::entity entity)
    {
        PerspectiveCameraComponent& pc = registry.get<PerspectiveCameraComponent>(entity);
        glm::vec2 windowSize = Application::GetWindowSize();
        pc.Width = windowSize.x;
        pc.Height = windowSize.y;
    }

    Scene::Scene()
    {
        m_Registry.on_construct<PerspectiveCameraComponent>().connect<&OnPerspectiveCameraAdded>();
    }

    Scene::~Scene()
    {
        m_Registry.view<NativeScriptComponent>().each([&](entt::entity id, NativeScriptComponent& nsc)
            {
                if (nsc.Instance)
                    nsc.DestroyScript(nsc.Instance);
            });

        m_Registry.on_construct<PerspectiveCameraComponent>().connect<&OnPerspectiveCameraAdded>();
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
        bool foundCamera = false;
        glm::mat4 viewProjection = glm::mat4(1.0f);

        m_Registry.view<TransformComponent, PerspectiveCameraComponent>().each([&](entt::entity id, TransformComponent& tc, PerspectiveCameraComponent& pc)
            {
                if (!foundCamera && pc.MainCamera)
                {
                    foundCamera = true;
                    viewProjection = pc.GetMatrix() * glm::inverse(tc.GetMatrix());
                }
            });
        if (!foundCamera)
            m_Registry.view<TransformComponent, OrthographicCameraComponent>().each([&](entt::entity id, TransformComponent& tc, OrthographicCameraComponent& oc)
                {
                    if (!foundCamera && oc.MainCamera)
                    {
                        foundCamera = true;
                        viewProjection = oc.GetMatrix() * glm::inverse(tc.GetMatrix());
                    }
                });

        if (foundCamera)
        {
            m_Registry.group<TransformComponent, MeshRendererComponent>().each([&](entt::entity id, TransformComponent& tc, MeshRendererComponent& mc)
                {
                    mc.Mesh->GetVertexBuffer()->Bind();
                    mc.Mesh->GetIndexBuffer()->Bind();
                    mc.Shader->Bind();
                    mc.Shader->SetFloat4("u_Color", mc.Color);
                    mc.Shader->SetFloatMatrix4x4("u_Model", tc.GetMatrix());
                    mc.Shader->SetFloatMatrix4x4("u_ViewProjection", viewProjection);
                    RenderCommand::DrawIndexed(mc.Mesh->GetIndexBuffer()->GetCount());
                });
        }
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
