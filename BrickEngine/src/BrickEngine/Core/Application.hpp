#pragma once

#include "BrickEngine/Core/Base.hpp"

#include "BrickEngine/Core/LayerStack.hpp"
#include "BrickEngine/Core/Window.hpp"

namespace BrickEngine {

	class Application
	{
	public:
		virtual ~Application() = default;

		void Run();

		void PushLayer(Layer* layer) { m_LayerStack.PushLayer(layer); }
		void PushOverlay(Layer* overlay) { m_LayerStack.PushOverlay(overlay); }
		void PopLayer(Layer* layer) { m_LayerStack.PopLayer(layer); }
		void PopOverlay(Layer* overlay) { m_LayerStack.PopOverlay(overlay); }
	private:
		Scope<Window> m_Window;
		LayerStack m_LayerStack;
		bool m_Running = true;
	protected:
		Application();
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}
