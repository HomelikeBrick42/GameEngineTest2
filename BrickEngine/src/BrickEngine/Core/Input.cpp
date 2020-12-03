#include "brickpch.hpp"
#include "BrickEngine/Core/Input.hpp"

#include "BrickEngine/Events/KeyEvent.hpp"
#include "BrickEngine/Events/MouseEvent.hpp"

namespace BrickEngine {

    struct InputData
    {
        std::array<bool, 350> Keys;
        std::array<bool, 350> KeysUp;
        std::array<bool, 350> KeysDown;
    };
    static Scope<InputData> s_Data = nullptr;

    void Input::Init()
    {
        s_Data = CreateScope<InputData>();
        for (uint32_t i = 0; i < 350; i++)
        {
            s_Data->Keys[i] = false;
            s_Data->KeysUp[i] = false;
            s_Data->KeysDown[i] = false;
        }
    }

    void Input::EndFrame()
    {
        for (uint32_t i = 0; i < 350; i++)
        {
            s_Data->KeysUp[i] = false;
            s_Data->KeysDown[i] = false;
        }
    }

    bool Input::GetKey(KeyCode key)
    {
        return s_Data->Keys[(int32_t)key];
    }

    bool Input::GetKeyUp(KeyCode key)
    {
        return s_Data->KeysUp[(int32_t)key];
    }

    bool Input::GetKeyDown(KeyCode key)
    {
        return s_Data->KeysDown[(int32_t)key];
    }

    void Input::OnEvent(Event& e)
    {
        EventDispatcher dispatcher(e);
        dispatcher.Dispatch<KeyPressedEvent>([](KeyPressedEvent& e)
            {
                if (!s_Data->Keys[(int32_t)e.GetKeyCode()])
                    s_Data->KeysDown[(int32_t)e.GetKeyCode()] = true;
                s_Data->Keys[(int32_t)e.GetKeyCode()] = true;
                return false;
            });
        dispatcher.Dispatch<KeyReleasedEvent>([](KeyReleasedEvent& e)
            {
                if (s_Data->Keys[(int32_t)e.GetKeyCode()])
                    s_Data->KeysUp[(int32_t)e.GetKeyCode()] = true;
                s_Data->Keys[(int32_t)e.GetKeyCode()] = false;
                return false;
            });
    }

}
