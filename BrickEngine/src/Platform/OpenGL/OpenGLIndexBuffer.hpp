#pragma once

#include "BrickEngine/GraphicsObjects/IndexBuffer.hpp"

namespace BrickEngine {

	class OpenGLIndexBuffer : public IndexBuffer
	{
	public:
		OpenGLIndexBuffer(const uint32_t* data, uint32_t count);
		~OpenGLIndexBuffer();

		virtual void Bind() const override;
		virtual void UnBind() const override;

		virtual void SetData(const uint32_t* data, uint32_t count) override;
		virtual uint32_t GetCount() const override { return m_Count; }
	private:
		uint32_t m_RendererID;
		uint32_t m_Count;
	};

}
