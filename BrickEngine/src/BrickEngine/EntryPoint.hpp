#pragma once

int main(int /*argc*/, char** /*argv*/)
{
	BrickEngine::Log::Init();

	BrickEngine::Application* app = BrickEngine::CreateApplication();
	app->Run();
	delete app;

	return 0;
}

#ifdef BRICKENGINE_PLATFORM_WINDOWS

extern BrickEngine::Application* BrickEngine::CreateApplication();

int WinMain(HINSTANCE /*hInstance*/, HINSTANCE /*hPrevInstance*/, LPSTR /*lpCmdLine*/, int /*nShowCmd*/)
{
	return main(0, nullptr);
}

#else
	#error BrickEngine only supports Windows!
#endif
