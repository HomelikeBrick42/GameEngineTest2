#pragma once

#include "BrickEngine/Core/Base.hpp"

namespace BrickEngine {

	class IndexBuffer
	{
	public:
		virtual ~IndexBuffer() = default;

		virtual void Bind() const = 0;
		virtual void UnBind() const = 0;

		virtual void SetData(const uint32_t* data, uint32_t count) = 0;
		virtual uint32_t GetCount() const = 0;

		static Ref<IndexBuffer> Create(const uint32_t* data, uint32_t count);
	protected:
		IndexBuffer() = default;
	};

}
