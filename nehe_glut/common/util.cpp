
#include "util.h"
#include <stdio.h>
#include <stdarg.h>

void
QUtil::log(const char* format, ...)
{
    char logStr[256] = {0};

	va_list va;
	va_start(va, format);
	vsprintf(logStr, format, va);
	va_end(va);

	printf("%s\n", logStr);
}
