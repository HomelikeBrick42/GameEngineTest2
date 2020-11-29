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
		Log::Info("{0}", 1.0 / dt);
	}

	void SandboxLayer::OnRender()
	{
	}

	void SandboxLayer::OnImGuiRender()
	{
	}

}
