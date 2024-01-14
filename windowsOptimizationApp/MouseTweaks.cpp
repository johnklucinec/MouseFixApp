#include "MouseTweaks.h"
#include "RegistryManager.h"
#include <string>
#include <Windows.h>

void MouseTweaks::applyDataQueue(DWORD buffer)
{
    // [HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Services\mouclass\Parameters]
    // Make sure key is created and accessible.
    RegistryManager regManager(HKEY_LOCAL_MACHINE);
    regManager.createKey("SYSTEM\\CurrentControlSet\\Services\\mouclass\\Parameters\\test");

    // Set values
    regManager.createVal("SYSTEM\\CurrentControlSet\\Services\\mouclass\\Parameters\\test", buffer,
        "MouseDataQueueSize");
    regManager.createVal("SYSTEM\\CurrentControlSet\\Services\\mouclass\\Parameters\\test", DWORD(31),
        "ThreadPriority");
}

void MouseTweaks::applyBoostCsrss()
{
    RegistryManager regManager(HKEY_LOCAL_MACHINE);
    regManager.createKey("SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Image File Execution Options\\csrss.exe\\PerfOptions\\test");

    // Set values
    regManager.createVal("SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Image File Execution Options\\csrss.exe\\PerfOptions\\test", DWORD(4),
        "CpuPriorityClass");
    regManager.createVal("SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Image File Execution Options\\csrss.exe\\PerfOptions\\test", DWORD(3),
        "IoPriority");
}

void MouseTweaks::revertDataQueue()
{
    RegistryManager regManager(HKEY_LOCAL_MACHINE);

    // Delete keys and values to revert data queue tweak
    regManager.deleteKey("SYSTEM\\CurrentControlSet\\Services\\mouclass\\Parameters\\test");
}

void MouseTweaks::revertBoostCsrss()
{
    RegistryManager regManager(HKEY_LOCAL_MACHINE);

    // Delete keys and values to revert csrss tweak
    regManager.deleteKey("SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Image File Execution Options\\csrss.exe\\PerfOptions\\test");
}
