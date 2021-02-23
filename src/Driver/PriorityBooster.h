#pragma once
NTSTATUS DriverEntry(_In_ PDRIVER_OBJECT DriverObject, _In_ PUNICODE_STRING RegistryPath);
void UnloadDriver(_In_ PDRIVER_OBJECT DriverObject);
NTSTATUS DriverCreateClose(_In_ PDEVICE_OBJECT DeviceObject, _In_ PIRP Irp);
NTSTATUS DriverDeviceControl(_In_ PDEVICE_OBJECT DeviceObject, _In_ PIRP Irp);