#include "brickpch.hpp"
#include "BrickEngine/GraphicsObjects/VertexBuffer.hpp"

#include "Platform/OpenGL/OpenGLVertexBuffer.hpp"

namespace BrickEngine {

    Ref<VertexBuffer> VertexBuffer::Create(const void* data, uint32_t size, const BufferLayout& layout)
    {
        return CreateRef<OpenGLVertexBuffer>(data, size, layout);
    }

}
