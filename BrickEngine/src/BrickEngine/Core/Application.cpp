#include "brickpch.hpp"
#include "BrickEngine/Core/Application.hpp"

namespace BrickEngine {

	Application::Application()
	{
	}

	void Application::Run()
	{
		while (true)
		{
			for (auto& layer : m_LayerStack)
				layer->OnUpdate(0.0f);

			for (auto& layer : m_LayerStack)
				layer->OnRender();
		}
	}

}
