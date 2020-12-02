#pragma once

#include "BrickEngine/Core/Base.hpp"

#include "BrickEngine/Renderer/ShaderDataTypes.hpp"

namespace BrickEngine {

	struct BufferLayoutElement
	{
		ShaderDataType Type;
		std::string Name;
		bool Normalized;
		uint32_t Size;
		uint32_t Offset;

		BufferLayoutElement()
			: Type(ShaderDataType::Unknown), Name(""), Normalized(false), Size(0), Offset(0) {}
		BufferLayoutElement(ShaderDataType type, const std::string& name, bool normalized = false)
			: Type(type), Name(name), Normalized(normalized), Size(GetShaderDataTypeSize(type)), Offset(0) {}
	};

	class BufferLayout
	{
	public:
		BufferLayout() = default;
		BufferLayout(const std::vector<BufferLayoutElement>& elements)
			: m_Elements(elements) {
			CalculateOffsetAndStride();
		}
		BufferLayout(std::initializer_list<BufferLayoutElement> elements)
			: m_Elements(elements) {
			CalculateOffsetAndStride();
		}

		uint32_t GetStride() const { return m_Stride; }

		const std::vector<BufferLayoutElement>& GetElements() const { return m_Elements; }
	private:
		void CalculateOffsetAndStride()
		{
			uint32_t offset = 0;
			m_Stride = 0;
			for (auto& element : m_Elements)
			{
				element.Offset = offset;
				offset += element.Size;
				m_Stride += element.Size;
			}
		}
	private:
		std::vector<BufferLayoutElement> m_Elements;
		uint32_t m_Stride;
	};

}
