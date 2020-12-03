#include "brickpch.hpp"
#include "BrickEngine/Renderer/Mesh.hpp"

namespace BrickEngine {

	Mesh::Mesh(const std::vector<Vertex>& vertices, const std::vector<uint32_t>& indices)
		: m_Vertices(vertices), m_Indices(indices)
	{
		m_VertexBuffer = VertexBuffer::Create(m_Vertices.data(), static_cast<uint32_t>(m_Vertices.size() * sizeof(Vertex)), Vertex::GetLayout());
		m_IndexBuffer = IndexBuffer::Create(m_Indices.data(), static_cast<uint32_t>(m_Indices.size()));
	}

	void Mesh::UpdateBuffers() const
	{
		m_VertexBuffer->SetData(m_Vertices.data(), static_cast<uint32_t>(m_Vertices.size() * sizeof(Vertex)));
		m_IndexBuffer->SetData(m_Indices.data(), static_cast<uint32_t>(m_Indices.size()));
	}

}
