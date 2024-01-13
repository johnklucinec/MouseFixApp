#include <iostream>
#include "markC.h"
#include "RegistryManager.h"

// This is just for testing code
int main()
{
    //MouseScaleFix testFix;
    //testFix.setScale(Scale::Scale100); // Set the scale to 100%
    //testFix.applyMouseFix(); // Apply the mouse fix
    
    //RegistryManager regManagerUsers(HKEY_USERS); // Use HKEY_USERS

    // [HKEY_USERS\.DEFAULT\Control Panel\Mouse]
    // Make sure key is created and accessible. 
    //regManagerUsers.deleteKey(".DEFAULT\\Control Panel\\Mouse\\test");

    //regManagerUsers.deleteVal(".DEFAULT\\Control Panel\\Mouse\\test", "MouseSpeed");

    RegistryManager regManager;
    regManager.createKey("Control Panel\\Mouse\\Test");

    // Set values
    regManager.createDWORDVal("Control Panel\\Mouse\\Test", DWORD32(20), "TestMouseSensitivity");

    return 0;
}
