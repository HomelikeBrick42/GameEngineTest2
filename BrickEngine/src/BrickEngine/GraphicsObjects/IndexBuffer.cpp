#include "brickpch.hpp"
#include "BrickEngine/GraphicsObjects/IndexBuffer.hpp"

#include "Platform/OpenGL/OpenGLIndexBuffer.hpp"

namespace BrickEngine {

    Ref<IndexBuffer> IndexBuffer::Create(const uint32_t* data, uint32_t count)
    {
        return CreateRef<OpenGLIndexBuffer>(data, count);
    }

}
