#ifndef MOUSETWEAKS_H
#define MOUSETWEAKS_H

#include "string"
#include "RegistryManager.h"

class MouseTweaks
{
public:
	void applyDataQueue(DWORD32 buffer);
	void applyBoostCsrss();
	void revertDataQueue();
	void revertBoostCsrss();
};

#endif // MOUSETWEAKS_H

