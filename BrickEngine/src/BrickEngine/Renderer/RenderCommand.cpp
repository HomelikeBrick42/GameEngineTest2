#include "brickpch.hpp"
#include "BrickEngine/Renderer/RenderCommand.hpp"

#include "Platform/OpenGL/OpenGLRendererAPI.hpp"

namespace BrickEngine {

	Scope<RendererAPI> RenderCommand::s_RendererAPI = nullptr;

	void RenderCommand::Init()
	{
		s_RendererAPI = CreateScope<OpenGLRendererAPI>();
		s_RendererAPI->Init();
	}

}
