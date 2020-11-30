#pragma once

#include "BrickEngine/Core/Base.hpp"

#include "BrickEngine/Renderer/RendererAPI.hpp"

namespace BrickEngine {

	class RenderCommand
	{
	public:
		static void Init();

		static void SetClearColor(const glm::vec3& color) { s_RendererAPI->ClearColor(color); }
		static void SetClearColor(float color) { s_RendererAPI->ClearColor(glm::vec4(color)); }
		static void Clear() { s_RendererAPI->Clear(); }

		static void SetViewport(int32_t x, int32_t y, int32_t width, int32_t height) { s_RendererAPI->SetViewport(x, y, width, height); }
	private:
		static Scope<RendererAPI> s_RendererAPI;
	};

}
