#include "pch.hpp"
#include "Script.hpp"

using namespace BrickEngine;

namespace Sandbox {

	void RotateScript::OnCreate()
	{
		m_Transform = &GetOrAddComponent<TransformComponent>();
	}

	void RotateScript::OnUpdate(float dt)
	{
		m_Transform->Rotation.x += 40.0f * dt;
		m_Transform->Rotation.y += 30.0f * dt;
		m_Transform->Rotation.z += 20.0f * dt;
	}

	void CameraScript::OnCreate()
	{
		m_Transform = &GetOrAddComponent<TransformComponent>();
	}

	void CameraScript::OnUpdate(float dt)
	{
		float speed = Input::GetKey(KeyCode::LeftShift) ? 25.0f : 5.0f;

		glm::vec3 forward = glm::normalize(glm::vec3(glm::sin(glm::radians(m_Transform->Rotation.y)), 0.0f, glm::cos(glm::radians(m_Transform->Rotation.y))));
		glm::vec3 right = glm::normalize(glm::cross(forward, glm::vec3(0.0f, 1.0f, 0.0f)));

		if (Input::GetKey(KeyCode::W))
			m_Transform->Position += forward * speed * dt;
		if (Input::GetKey(KeyCode::S))
			m_Transform->Position -= forward * speed * dt;
		if (Input::GetKey(KeyCode::A))
			m_Transform->Position += right * speed * dt;
		if (Input::GetKey(KeyCode::D))
			m_Transform->Position -= right * speed * dt;
		if (Input::GetKey(KeyCode::E))
			m_Transform->Position.y += speed * dt;
		if (Input::GetKey(KeyCode::Q))
			m_Transform->Position.y -= speed * dt;

		if (Input::GetKey(KeyCode::Up))
			m_Transform->Rotation.x -= 75.0f * dt;
		if (Input::GetKey(KeyCode::Down))
			m_Transform->Rotation.x += 75.0f * dt;
		if (Input::GetKey(KeyCode::Left))
			m_Transform->Rotation.y -= 75.0f * dt;
		if (Input::GetKey(KeyCode::Right))
			m_Transform->Rotation.y += 75.0f * dt;

		m_Transform->Rotation.x = glm::max(glm::min(m_Transform->Rotation.x, 90.0f), -90.0f);
	}

}
