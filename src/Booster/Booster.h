#pragma once
#include <windows.h>
#include <stdio.h>
int Error(const char* msg)
{
	printf("%s (error= %d)", msg, GetLastError());
}