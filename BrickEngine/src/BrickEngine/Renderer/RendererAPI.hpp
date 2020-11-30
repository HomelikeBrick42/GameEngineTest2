#pragma once

#include "BrickEngine/Core/Base.hpp"

namespace BrickEngine {

	class RendererAPI
	{
	public:
		virtual ~RendererAPI() = default;

		virtual void Init() = 0;
		virtual void ClearColor(const glm::vec3& color) = 0;
		virtual void Clear() = 0;

		virtual void SetViewport(int32_t x, int32_t y, int32_t width, int32_t height) = 0;
	protected:
		RendererAPI() = default;
	};

}
