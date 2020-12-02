#pragma once

#include "BrickEngine/GraphicsObjects/VertexBuffer.hpp"

namespace BrickEngine {

	class OpenGLVertexBuffer : public VertexBuffer
	{
	public:
		OpenGLVertexBuffer(const void* data, uint32_t size, const BufferLayout& layout);
		~OpenGLVertexBuffer();

		virtual void SetLayout(const BufferLayout& layout) override;
		virtual const BufferLayout& GetLayout() const override { return m_Layout; }

		virtual void Bind() const override;
		virtual void UnBind() const override;

		virtual void SetData(void* data, uint32_t size) override;
	private:
		uint32_t m_VertexArrayRendererID;
		uint32_t m_RendererID;
		BufferLayout m_Layout;
	};

}
