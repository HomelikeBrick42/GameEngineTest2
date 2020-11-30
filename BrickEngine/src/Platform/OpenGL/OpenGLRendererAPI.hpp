#pragma once

#include "BrickEngine/Renderer/RendererAPI.hpp"

namespace BrickEngine {

	class OpenGLRendererAPI : public RendererAPI
	{
	public:
		virtual void Init() override;
		virtual void ClearColor(const glm::vec3& color) override;
		virtual void Clear() override;
	};

}
