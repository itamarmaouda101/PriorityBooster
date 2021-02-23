#pragma once
#include <ntddk.h>
#define DeviceType 0x800
#define IOCTL_DRIVER_SET CTL_CODE(DeviceType, 0x800, METHOD_NEITHER, FILE_ANY_ACCESS)
struct ThreadData
{
	ULONG ThreadId;
	int Priority;
};