#include "brickpch.hpp"
#include "Platform/Windows/WindowsWindow.hpp"

#include "BrickEngine/Events/KeyEvent.hpp"
#include "BrickEngine/Events/MouseEvent.hpp"
#include "BrickEngine/Events/WindowEvent.hpp"

#ifdef BRICKENGINE_PLATFORM_WINDOWS

namespace BrickEngine {

    static int32_t s_WindowCount = 0;

    WindowsWindow::WindowsWindow(const WindowProps& props)
    {
        if (s_WindowCount <= 0)
        {
            int32_t status = glfwInit();
            BRICKENGINE_CORE_ASSERT(status, "Unable to initalize GLFW!");
        }

        GLFWmonitor* monitor = glfwGetPrimaryMonitor();
        const GLFWvidmode* mode = glfwGetVideoMode(monitor);
        m_Data.Width = props.Width == -1 ? mode->width : props.Width;
        m_Data.Height = props.Height == -1 ? mode->height : props.Height;

        glfwWindowHint(GLFW_FOCUSED, GLFW_TRUE);
        glfwWindowHint(GLFW_RESIZABLE, props.Resizeable ? GLFW_TRUE : GLFW_FALSE);
        
        m_Window = glfwCreateWindow(m_Data.Width, m_Data.Height, props.Title.c_str(), props.Fullscreen ? monitor : nullptr, nullptr);
        BRICKENGINE_CORE_ASSERT(m_Window, "Unable to create window '{0}'", props.Title);
        if (m_Window)
            Log::CoreInfo("Created Window '{0}' ({1}, {2})", props.Title, m_Data.Width, m_Data.Height);

        glfwGetWindowPos(m_Window, &m_Data.XPos, &m_Data.XPos);
    }

    WindowsWindow::~WindowsWindow()
    {
        glfwDestroyWindow(m_Window);
        s_WindowCount--;
        if (s_WindowCount <= 0)
            glfwTerminate();
    }

    void WindowsWindow::SetSize(const glm::uvec2& size)
    {
        glfwSetWindowSize(m_Window, (int32_t)size.x, (int32_t)size.y);
    }

    void WindowsWindow::SetPos(const glm::ivec2& pos)
    {
        glfwSetWindowPos(m_Window, pos.x, pos.y);
    }

    void WindowsWindow::Focus() const
    {
        glfwFocusWindow(m_Window);
    }

    void WindowsWindow::SetVisible(bool visible)
    {
        if (visible)
            glfwShowWindow(m_Window);
        else
            glfwHideWindow(m_Window);
    }

    void WindowsWindow::SetTitle(const std::string& title)
    {
        glfwSetWindowTitle(m_Window, title.c_str());
    }

    void WindowsWindow::PollEvents() const
    {
        glfwPollEvents();
    }

    void* WindowsWindow::GetNativeWindowHandle()
    {
        return m_Window;
    }

    void WindowsWindow::SetEventCallbackFn(EventCallbackFn fn)
    {
        m_Data.EventCallback = fn;
        glfwSetWindowUserPointer(m_Window, &m_Data);

        glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window)
            {
                WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
                WindowCloseEvent event;
                data.EventCallback(event);
            });

        glfwSetWindowFocusCallback(m_Window, [](GLFWwindow* window, int32_t focused)
            {
                switch (focused)
                {
                    case GLFW_TRUE:
                    {
                        WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
                        WindowFocusEvent event;
                        data.EventCallback(event);
                    } break;
                    case GLFW_FALSE:
                    {
                        WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
                        WindowLostFocusEvent event;
                        data.EventCallback(event);
                    } break;
                }
            });

        glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int32_t width, int32_t height)
            {
                WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
                WindowResizeEvent event((uint32_t)width, (uint32_t)height);
                data.EventCallback(event);
            });

        glfwSetWindowPosCallback(m_Window, [](GLFWwindow* window, int32_t xPos, int32_t yPos)
            {
                WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
                WindowMovedEvent event(xPos, yPos);
                data.EventCallback(event);
            });

        glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int32_t key, int32_t scancode, int32_t action, int32_t mods)
            {
                WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

                switch (action)
                {
                    case GLFW_PRESS:
                    {
                        KeyPressedEvent event((KeyCode)key, 0);
                        data.EventCallback(event);
                    } break;
                    case GLFW_REPEAT:
                    {
                        KeyPressedEvent event((KeyCode)key, 1);
                        data.EventCallback(event);
                    } break;
                    case GLFW_RELEASE:
                    {
                        KeyReleasedEvent event((KeyCode)key);
                        data.EventCallback(event);
                    } break;
                }
            });

        glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int32_t button, int32_t action, int32_t mods)
            {
                WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

                switch (action)
                {
                    case GLFW_PRESS:
                    {
                        MouseButtonPressedEvent event((MouseButton)button);
                        data.EventCallback(event);
                    } break;
                    case GLFW_REPEAT:
                    {
                        MouseButtonPressedEvent event((MouseButton)button);
                        data.EventCallback(event);
                    } break;
                    case GLFW_RELEASE:
                    {
                        MouseButtonReleasedEvent event((MouseButton)button);
                        data.EventCallback(event);
                    } break;
                }
            });

        glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xPos, double yPos)
            {
                WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
                MouseMovedEvent event((float)xPos, (float)yPos);
                data.EventCallback(event);
            });

        glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xOffset, double yOffset)
            {
                WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
                MouseScrolledEvent event((float)xOffset, (float)yOffset);
                data.EventCallback(event);
            });
    }

}

#endif
