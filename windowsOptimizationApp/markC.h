#ifndef MARKC_H
#define MARKC_H

// Declaration of an enum class named Scale
// Each member represents a different scaling factor
enum class Scale {Default, Scale100, Scale125, Scale150, Scale175, Scale200, Scale225, Scale250, Scale300, Scale350};

class MouseScaleFix
{
public:
    MouseScaleFix() : scale(Scale::Default) {} // Default constructor
    void applyMouseFix();
    void setScale(Scale newScale) { scale = newScale; }
private:
    // Member variable to store the current scale
    Scale scale;
};

#endif // MARKC_H
