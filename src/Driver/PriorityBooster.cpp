#include <ntddk.h>
#include "PriorityBooster.h"
extern "C"
NTSTATUS DriverEntry(_In_ PDRIVER_OBJECT DriverObject, _In_ PUNICODE_STRING RegistryPath)
{
	DriverObject->DriverUnload = UnloadDriver;
	DriverObject->MajorFunction[IRP_MJ_CREATE] = DriverCreateClose;
	DriverObject->MajorFunction[IRP_MJ_CLOSE] = DriverCreateClose;
	DriverObject->MajorFunction[IRP_MJ_DEVICE_CONTROL] = DriverDeviceControl;
	UNICODE_STRING DeviceName = RTL_CONSTANT_STRING(L"\\Device\\PriorityBooster");
	PDEVICE_OBJECT DeviceObject;
	NTSTATUS Status = IoCreateDevice(
		DriverObject,
		0,
		&DeviceName,
		FILE_DEVICE_UNKNOWN,
		0,
		FALSE,
		&DeviceObject);
	if (!NT_SUCCESS(Status)) {
		KdPrint(("Failed to create device object (0x%08X)\n", Status));
		return Status;
	}
	UNICODE_STRING symLink = RTL_CONSTANT_STRING(L"\\??\\PriorityBooster");
	Status = IoCreateSymbolicLink(&symLink, &DeviceName);
	if (!NT_SUCCESS(Status)) {
		KdPrint(("Failed to create symbolic link (0x%08X)\n", Status));
		IoDeleteDevice(DeviceObject);
		return Status;
	}
	return STATUS_SUCCESS;
}

void UnloadDriver(PDRIVER_OBJECT DriverObject)
{
	UNICODE_STRING symLink = RTL_CONSTANT_STRING(L"\\??\\PriorityBooster");
	IoDeleteSymbolicLink(&symLink);
	IoDeleteDevice(DriverObject->DeviceObject);
}

NTSTATUS DriverCreateClose(PDEVICE_OBJECT DeviceObject, PIRP Irp)
{
	return NTSTATUS();
}

NTSTATUS DriverDeviceControl(PDEVICE_OBJECT DeviceObject, PIRP Irp)
{
	
	return NTSTATUS();
}
