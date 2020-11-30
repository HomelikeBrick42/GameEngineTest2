#pragma once

#ifdef BRICKENGINE_PLATFORM_WINDOWS

extern BrickEngine::Application* BrickEngine::CreateApplication();

int WinMain(HINSTANCE /*hInstance*/, HINSTANCE /*hPrevInstance*/, LPSTR /*lpCmdLine*/, int /*nShowCmd*/)
{
	BrickEngine::Log::Init();

	BrickEngine::Application* app = BrickEngine::CreateApplication();
	app->Run();
	delete app;

	return 0;
}

int main(int /*argc*/, char** /*argv*/)
{
	BrickEngine::Log::Init();

	BrickEngine::Application* app = BrickEngine::CreateApplication();
	app->Run();
	delete app;

	return 0;
}

#else
	#error BrickEngine only supports Windows!
#endif
