#pragma once

bool IsConnected();
void Show(char*);

typedef bool(*IsConnected_ptr)();
typedef void (*Show_ptr)(char*);