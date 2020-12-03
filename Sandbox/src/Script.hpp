#pragma once

#include <BrickEngine.hpp>

namespace Sandbox {

	class RotateScript : public BrickEngine::NativeEntityScript
	{
	public:
		void OnCreate() override;
		void OnUpdate(float dt) override;
	private:
		BrickEngine::TransformComponent* m_Transform = nullptr;
	};

	class CameraScript : public BrickEngine::NativeEntityScript
	{
	public:
		void OnCreate() override;
		void OnUpdate(float dt) override;
	private:
		BrickEngine::TransformComponent* m_Transform = nullptr;
	};

}
