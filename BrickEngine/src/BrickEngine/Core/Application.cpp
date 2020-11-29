#include "brickpch.hpp"
#include "BrickEngine/Core/Application.hpp"

#include "BrickEngine/Events/WindowEvent.hpp"

namespace BrickEngine {

	Application::Application()
	{
		m_Window = Window::Create(WindowProps("BrickEngine Window", 1280, 720, false, false));
		m_Window->SetEventCallbackFn([&](Event& e)
			{
				EventDispatcher dispatcher(e);
				dispatcher.Dispatch<WindowCloseEvent>([&](WindowCloseEvent&)
					{
						m_Running = false;
						return false;
					});

				for (auto& layer : m_LayerStack)
					layer->OnEvent(e);
			});
	}

	void Application::Run()
	{
		std::chrono::steady_clock::time_point time, lastFrame = std::chrono::high_resolution_clock::now();
		float delta;
		while (m_Running)
		{
			time = std::chrono::high_resolution_clock::now();
			delta = std::chrono::duration<float>(time - lastFrame).count();
			lastFrame = time;

			for (auto& layer : m_LayerStack)
				layer->OnUpdate(delta);

			for (auto& layer : m_LayerStack)
				layer->OnRender();

			m_Window->PollEvents();
		}
	}

}
