#include "pch.hpp"
#include "SandboxLayer.hpp"

using namespace BrickEngine;

namespace Sandbox {

	void SandboxLayer::OnAttach()
	{
		Log::Info("OnAttach");
	}

	void SandboxLayer::OnDetach()
	{
		Log::Info("OnDetach");
	}

	void SandboxLayer::OnUpdate(float dt)
	{
		Log::Info("OnUpdate");
	}

	void SandboxLayer::OnRender()
	{
		Log::Info("OnRender");
	}

	void SandboxLayer::OnImGuiRender()
	{
	}

}
