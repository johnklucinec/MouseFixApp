#include <iostream>
#include "markC.h"

int main()
{
    MouseScaleFix testFix;
    testFix.setScale(Scale::Scale100); // Set the scale to 150%
    testFix.applyMouseFix(); // Apply the mouse fix
    return 0;
}
