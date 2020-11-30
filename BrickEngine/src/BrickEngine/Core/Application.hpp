#pragma once

#include "BrickEngine/Core/Base.hpp"

#include "BrickEngine/Core/LayerStack.hpp"
#include "BrickEngine/Core/Window.hpp"
#include "BrickEngine/GraphicsObjects/GraphicsContext.hpp"

namespace BrickEngine {

	class ImGuiLayer;

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
		Scope<GraphicsContext> m_GraphicsContext;
		LayerStack m_LayerStack;
#if BRICKENGINE_ENABLE_IMGUI
		ImGuiLayer* m_ImGuiLayer = nullptr;
#endif
		bool m_Running = true;
	protected:
		Application();
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}
