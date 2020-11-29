#include "pch.hpp"

#include <BrickEngine/EntryPoint.hpp>

#include "SandboxLayer.hpp"

namespace Sandbox {

	class SandboxApplication : public BrickEngine::Application
	{
	public:
		SandboxApplication()
		{
			PushLayer(new SandboxLayer());
		}

		~SandboxApplication()
		{
		}
	};

}

BrickEngine::Application* BrickEngine::CreateApplication()
{
	return new Sandbox::SandboxApplication();
}
