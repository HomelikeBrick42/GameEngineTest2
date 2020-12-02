#include "brickpch.hpp"
#include "BrickEngine/GraphicsObjects/Shader.hpp"

#include "Platform/OpenGL/OpenGLShader.hpp"

namespace BrickEngine {

    Ref<Shader> Shader::Create(const std::string& vertexSrc, const std::string& fragmentSrc)
    {
        return CreateRef<OpenGLShader>(vertexSrc, fragmentSrc);
    }

    Ref<Shader> Shader::Create(const std::string& filePath)
    {
        return CreateRef<OpenGLShader>(filePath);
    }

}
