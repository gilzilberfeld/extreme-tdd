#include <stdbool.h>
#include <stdlib.h>
#include "MockDisplay.h"


bool Mock_IsConnected()
{
	return true;
}

void Mock_Show(char* display)
{
	memset (externalDisplay, 0, 100);
	memcpy (externalDisplay, display, 10);
}

