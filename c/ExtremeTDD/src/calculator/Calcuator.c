#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#include "Display.h"
#include "Calculator.h"
#include "OperationType.h"

IsConnected_ptr Display_IsConnected = 0;
Show_ptr Display_Show = 0;

char display[10];
OperationType lastOperation;
int lastArgument = 0;
bool newArgument = false;
bool shouldReset = false;

bool Init()
{
	memset(display, 0, 10);
	display[0] = '\0';
}

void InitWithDisplay(IsConnected_ptr isConnectedFunc, Show_ptr show)
{
	Init();
	Display_IsConnected = isConnectedFunc;
	Display_Show = show;
}

char* GetDisplay()
{
	return display;
}

void Press(char key)
{
	if (key == 'C')
		display[0] = '\0';
	else
	{
		if (key == '+')
		{
			lastOperation = Plus;
			lastArgument = atoi(display);
			newArgument = true;
		}
		else
		{
			if (key == '/')
			{
				lastOperation = Div;
				lastArgument = atoi(display);
				newArgument = true;
			}
			else
			{
				if (key == '=')
				{
					int currentArgument = atoi(display);
					if (lastOperation == Plus)
					{
						sprintf(display, "%d", lastArgument + currentArgument);
					}
					shouldReset = false;
				}
				else
				{
					if (shouldReset)
					{
						display[0] = "\0";
						shouldReset = false;
					}
					if (newArgument)
					{
						display[0] = "\0";
						newArgument = false;
					}
					AddKeyToDisplay(key);
				}

			}
		}
	}

	if (Display_IsConnected != 0)
		if (Display_IsConnected())
			Display_Show(display);

}

void AddKeyToDisplay(char key)
{
	char buffer[2];
	memset(buffer, 0, 2);
	memcpy(buffer, &key, 1);
	strcat(display, buffer);

}