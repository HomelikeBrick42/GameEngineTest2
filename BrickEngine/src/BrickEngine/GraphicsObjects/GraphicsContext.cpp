#include "brickpch.hpp"
#include "BrickEngine/GraphicsObjects/GraphicsContext.hpp"

#ifdef BRICKENGINE_PLATFORM_WINDOWS
    #include "Platform/Windows/WindowsOpenGLContext.hpp"
#endif

namespace BrickEngine {

    Scope<GraphicsContext> GraphicsContext::Create(Window* window)
    {
#ifdef BRICKENGINE_PLATFORM_WINDOWS
        return CreateScope<WindowsOpenGLContext>((GLFWwindow*)window->GetNativeWindowHandle());
#else
        return nullptr;
#endif
    }

}
