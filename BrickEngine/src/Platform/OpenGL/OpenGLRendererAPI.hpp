#pragma once

#include "BrickEngine/Renderer/RendererAPI.hpp"

namespace BrickEngine {

	class OpenGLRendererAPI : public RendererAPI
	{
	public:
		virtual void Init() override;
		virtual void ClearColor(const glm::vec3& color) override;
		virtual void Clear() override;

		virtual void SetViewport(int32_t x, int32_t y, int32_t width, int32_t height) override;

		virtual void Draw(uint32_t first, uint32_t count) override;
		virtual void DrawIndexed(uint32_t count) override;
	};

}
