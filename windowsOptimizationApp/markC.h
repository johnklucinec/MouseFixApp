#ifndef MARKC_H
#define MARKC_H
#include "markC.h"
#include "RegistryManager.h"
#include <string>
#include <vector>
#include <Windows.h>

// Declaration of an enum class named Scale
// Each member represents a different scaling factor
enum class Scale {
    Default,
    Scale100,
    Scale125,
    Scale150,
    Scale175,
    Scale200,
    Scale225,
    Scale250,
    Scale300,
    Scale350
};

class MouseScaleFix {
public:
    MouseScaleFix()
        : scale(Scale::Default)
    {
    } // Default constructor
    void applyMouseFix();
    void setScale(Scale newScale) { scale = newScale; }

private:
    // Member variable to store the current scale
    Scale scale;

    void setScale100();
    void setScale125();
    void setScale150();
    void setScale175();
    void setScale200();
    void setScale225();
    void setScale250();
    void setScale300();
    void setScale350();
    void setScaleDefault();
    void applyMarkC(const std::vector<BYTE>& xData,
        const std::vector<BYTE>& yData);
};

#endif // MARKC_H
