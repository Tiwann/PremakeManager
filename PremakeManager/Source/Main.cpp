#include "Application.h"
#include "Core.h"
#include <memory>

#ifdef PREMAN_WINDOWS
#include <Windows.h>
INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine, INT nCmdShow)
{
    const std::unique_ptr<Application> application = std::make_unique<Application>(Application("Premake Manager", 1024, 576));
    application->Initialize();
	application->Loop();
    application->End();
	return 0;
}
#else
int main(int argc, const char** argv)
{
	const std::unique_ptr<Application> application = std::make_unique<Application>(Application("Premake Manager", 1024, 576));
	application->Initialize();
	application->Loop();
	application->End();
	return 0;
}
#endif