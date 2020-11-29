#include "pch.hpp"
#include "SandboxLayer.hpp"

using namespace BrickEngine;

namespace Sandbox {

	void SandboxLayer::OnAttach()
	{
	}

	void SandboxLayer::OnDetach()
	{
	}

	void SandboxLayer::OnUpdate(float dt)
	{
	}

	void SandboxLayer::OnRender()
	{
	}

	void SandboxLayer::OnImGuiRender()
	{
	}

	void SandboxLayer::OnEvent(Event& e)
	{
		Log::Info("{0}", e);
	}

}
