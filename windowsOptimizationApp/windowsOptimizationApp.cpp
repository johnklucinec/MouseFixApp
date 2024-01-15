#include "markC.h"
#include "MouseTweaks.h"
#include <iostream>
#include <Windows.h>

// This is just for testing code :)
int main()
{

    // RegistryManager regManager;

    // regManager.createVal("Control Panel\\Mouse\\Test", "20",
    //     "TestMouseSensitivity");
    // regManager.createVal("Control Panel\\Mouse\\Test", DWORD(20),
    //     "MouseSensitivity");
    // regManager.createVal("Control Panel\\Mouse\\Test", "20");

    // RegistryManager regManager;

    // regManager.createVal("Control Panel\\Mouse\\Test", "20",
    //     "TestMouseSensitivity");
    // regManager.createVal("Control Panel\\Mouse\\Test", DWORD(20),
    //     "MouseSensitivity");
    // regManager.createVal("Control Panel\\Mouse\\Test", "20");

    // MouseScaleFix fix(Scale::Scale100);
    // fix.setScale(Scale::Scale100);
    // LONG returnValue = fix.applyMouseFix();
    // std::cout << "The status code from the operation is: " << returnValue << std::endl;

    MouseTweaks tweak;
    LONG returnValue = tweak.applyDataQueue();
    std::cout << "The status code from the operation is: " << returnValue << std::endl;

    return 0;
}
