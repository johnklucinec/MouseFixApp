#include "markC.h"
#include "MouseTweaks.h"
#include "RegistryManager.h"
#include <iostream>

// This is just for testing code :)
int main()
{
    RegistryManager regManager;
    regManager.createKey("Control Panel\\Mouse\\Test");

    // Set values
    regManager.createVal("Control Panel\\Mouse\\Test", "20",
        "TestMouseSensitivity");
    regManager.createVal("Control Panel\\Mouse\\Test", DWORD(20),
        "MouseSensitivity");
    regManager.createVal("Control Panel\\Mouse\\Test", "20");

    MouseTweaks tweak;

    tweak.revertBoostCsrss();

    return 0;
}
