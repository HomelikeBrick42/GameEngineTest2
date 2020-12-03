#pragma once

#include "BrickEngine/Core/Base.hpp"

#include "BrickEngine/Renderer/Mesh.hpp"

namespace BrickEngine {

	class MeshFactory
	{
	public:
		MeshFactory() = delete;

		static Ref<Mesh> CreateCube(const glm::vec3& size = glm::vec3(1.0f));
	};

}
