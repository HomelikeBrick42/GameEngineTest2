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
	protected:
		RendererAPI() = default;
	};

}
