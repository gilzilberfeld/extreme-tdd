#pragma once
bool InitCalculator();
void InitCalculatorWithDisplay(IsConnected_ptr isConnectedFunc, Show_ptr show);
char* GetDisplay();
void Press(char key);
void AddKeyToDisplay(char key);

