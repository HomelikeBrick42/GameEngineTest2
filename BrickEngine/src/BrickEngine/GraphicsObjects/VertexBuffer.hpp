#pragma once

#include "BrickEngine/Core/Base.hpp"

#include "BrickEngine/Renderer/BufferLayout.hpp"

namespace BrickEngine {

	class VertexBuffer
	{
	public:
		virtual ~VertexBuffer() = default;

		virtual void SetLayout(const BufferLayout& layout) = 0;
		virtual const BufferLayout& GetLayout() const = 0;

		virtual void Bind() const = 0;
		virtual void UnBind() const = 0;

		virtual void SetData(void* data, uint32_t size) = 0;

		static Ref<VertexBuffer> Create(const void* data, uint32_t size, const BufferLayout& layout);
	protected:
		VertexBuffer() = default;
	};

}
