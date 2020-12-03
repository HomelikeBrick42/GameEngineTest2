#pragma once

#include "BrickEngine/Core/Base.hpp"

#include "BrickEngine/Renderer/Vertex.hpp"

#include "BrickEngine/GraphicsObjects/VertexBuffer.hpp"
#include "BrickEngine/GraphicsObjects/IndexBuffer.hpp"

namespace BrickEngine {

	class Mesh
	{
	public:
		Mesh(const std::vector<Vertex>& vertices, const std::vector<uint32_t>& indices);

		const std::vector<Vertex>& GetVertices() const { return m_Vertices; }
		std::vector<Vertex>& GetVertices() { m_BuffersNeedUpdating = true; return m_Vertices; }
		const std::vector<uint32_t>& GetIndices() const { return m_Indices; }
		std::vector<uint32_t>& GetIndices() { m_BuffersNeedUpdating = true; return m_Indices; }

		Ref<VertexBuffer> GetVertexBuffer() const { if (m_BuffersNeedUpdating) UpdateBuffers(); return m_VertexBuffer; }
		Ref<IndexBuffer> GetIndexBuffer() const { if (m_BuffersNeedUpdating) UpdateBuffers(); return m_IndexBuffer; }
	private:
		void UpdateBuffers() const;
	private:
		std::vector<Vertex> m_Vertices;
		std::vector<uint32_t> m_Indices;
		Ref<VertexBuffer> m_VertexBuffer;
		Ref<IndexBuffer> m_IndexBuffer;
		bool m_BuffersNeedUpdating = false;
	};

}
