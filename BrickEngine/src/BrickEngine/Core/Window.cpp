#include "brickpch.hpp"
#include "BrickEngine/Core/Window.hpp"

#ifdef BRICKENGINE_PLATFORM_WINDOWS
    #include "Platform/Windows/WindowsWindow.hpp"
#endif

namespace BrickEngine {

    Scope<Window> Window::Create(const WindowProps& props)
    {
#ifdef BRICKENGINE_PLATFORM_WINDOWS
        return CreateScope<WindowsWindow>(props);
#else
        return nullptr;
#endif
    }

}
