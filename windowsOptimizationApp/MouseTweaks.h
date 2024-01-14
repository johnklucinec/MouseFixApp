#ifndef MOUSETWEAKS_H
#define MOUSETWEAKS_H

#include "RegistryManager.h"
#include <string>
#include <Windows.h>

class MouseTweaks {
public:
    // Default/Recommended Data Queue size is 20
    void applyDataQueue(DWORD buffer = 20);
    void applyBoostCsrss();
    void revertDataQueue();
    void revertBoostCsrss();
};

#endif // MOUSETWEAKS_H
