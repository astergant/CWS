
#ifndef WIN32
	#include <dlfcn.h>
#else
	#include <windows.h>
#endif

#include "load.h"

void load_run(char *s)
{
	void *lib;
	void (*function)(void);

	#ifndef WIN32
		lib = dlopen(s, RTLD_LAZY);
	#else
		lib = LoadLibrary(s);
	#endif

	if (!lib)
	{
		printf("library not open '%s'\n", s);
		return;
	}

	#ifndef WIN32
		function = (void (*)(void))dlsym(lib, "function");
	#else
		function = (void (*)(void))GetProcAddress((HINSTANCE)lib, "function");
	#endif

	if (!function)
		printf("function not load\n");
	else
		function();

	#ifndef WIN32
		dlclose(lib);
	#else
		FreeLibrary((HINSTANCE)lib);
	#endif
}

