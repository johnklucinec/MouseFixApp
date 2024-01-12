#include "markC.h"
#include "iostream"
#include "Windows.h"
#include "string"
#include <vector>
#include "RegistryManager.h"

// Windows_10+8.x_MouseFix_ItemsSize=100%_Scale=1-to-1_@6-of-11
void setScale100() {
	
	// [HKEY_CURRENT_USER\Control Panel\Mouse]

	RegistryManager regManager;
	regManager.createKey("Control Panel\\Mouse\\test");

	std::vector<BYTE> xData = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
							  0xC0, 0xCC, 0x0C, 0x00, 0x00, 0x00, 0x00, 0x00,
							  0x80, 0x99, 0x19, 0x00, 0x00, 0x00, 0x00, 0x00,
							  0x40, 0x66, 0x26, 0x00, 0x00, 0x00, 0x00, 0x00,
							  0x00, 0x33, 0x33, 0x00, 0x00, 0x00, 0x00, 0x00 };
	regManager.createVec("Control Panel\\Mouse\\test", xData, "SmoothMouseXCurve");

	std::vector<BYTE> yData = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
								0x00, 0x00, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00,
								0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00,
								0x00, 0x00, 0xA8, 0x00, 0x00, 0x00, 0x00, 0x00,
								0x00, 0x00, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00 };
	regManager.createVec("Control Panel\\Mouse\\test", yData, "SmoothMouseYCurve");

	regManager.createVal("Control Panel\\Mouse\\test", "10", "MouseSensitivity");

	RegistryManager regManagerUsers(HKEY_USERS); // Use HKEY_USERS

	// [HKEY_USERS\.DEFAULT\Control Panel\Mouse]
	regManagerUsers.createKey(".DEFAULT\\Control Panel\\Mouse\\test");

	regManagerUsers.createVal(".DEFAULT\\Control Panel\\Mouse\\test", "0", "MouseSpeed");
	regManagerUsers.createVal(".DEFAULT\\Control Panel\\Mouse\\test", "0", "MouseThreshold1");
	regManagerUsers.createVal(".DEFAULT\\Control Panel\\Mouse\\test", "0", "MouseThreshold2");

	std::cout << "The mouse fix was set (scale 100)" << std::endl;
}

void setScale125() {
	std::cout << "The mouse fix was set (scale 125)" << std::endl;
}

void setScale150() {
	std::cout << "The mouse fix was set (scale 150)" << std::endl;
}

void setScale175() {
	std::cout << "The mouse fix was set (scale 175)" << std::endl;
}

void setScale200() {
	std::cout << "The mouse fix was set (scale 200)" << std::endl;
}

void setScale225() {
	std::cout << "The mouse fix was set (scale 225)" << std::endl;
}

void setScale250() {
	std::cout << "The mouse fix was set (scale 250)" << std::endl;
}

void setScale300() {
	std::cout << "The mouse fix was set (scale 300)" << std::endl;
}

void setScale350() {
	std::cout << "The mouse fix was set (scale 350)" << std::endl;
}

void setScaleDefault() {
	std::cout << "The mouse fix was set to Default" << std::endl;
}

void MouseScaleFix::applyMouseFix() {
	switch (scale) {
		case Scale::Scale100:
			setScale100();
			break;
		case Scale::Scale125:
			setScale125();
			break;
		case Scale::Scale150:
			setScale150();
			break;
		case Scale::Scale175:
			setScale175();
			break;
		case Scale::Scale200:
			setScale200();
			break;
		case Scale::Scale225:
			setScale225();
			break;
		case Scale::Scale250:
			setScale250();
			break;
		case Scale::Scale300:
			setScale300();
			break;
		case Scale::Scale350:
			setScale350();
			break;
		case Scale::Default:
			setScale350();
			break;
	}
}
