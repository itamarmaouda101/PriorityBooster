// Booster.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <windows.h>
#include <stdio.h>
#include "Booster.h"
#include "..\PriorityBooster\Common.h"
int main(int argc, const char* argv[])
{
    if (argc < 3)
    {
        printf("Usage: Booster <Thread Id> <Priority>\n");
        return 0;
    }
    HANDLE hDevice = CreateFile(L"\\\\.\\PriorityBooster", GENERIC_WRITE, FILE_SHARE_WRITE, nullptr, OPEN_EXISTING, 0, nullptr);
    if (hDevice == INVALID_HANDLE_VALUE)
    {
        return Error("Failed to open device");
    }
    ThreadData data;
    data.Priority = atoi(argv[1]);
    data.ThreadId = atoi(argv[2]);
    DWORD returnd;
    BOOL Status = DeviceIoControl(
        hDevice,
        IOCTL_DRIVER_SET_PRIORITY,
        &data,
        sizeof(data),
        nullptr,
        0,
        &returnd,
        nullptr);
    if (Status)
    {
        printf("Priority Changend Secessfully!\n");
    }
    else
    {
        Error("Priority Changend Failed!");
    }
    CloseHandle(hDevice);
    return (int)Status;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
