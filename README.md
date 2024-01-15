# Registry Editor | Mouse Tweaks | MarkC Fix

I have created some classes for a new Qt program that I am developing. 

My goal was to ensure that the end-users could apply and undo any adjustments they make as nothing should be permanent. Therefore, I have designed these frameworks keeping this requirement in mind.
 

## Features
**Registry Editor**
  * Create registry keys
  * Create registry values
    * only REG_SZ and REG_DWORD currently
  * Delete registry keys
  * Delete registry values
  * Helpful error handling
    * returns error in LONG variable

**Mouse Tweeks**
  * Change mouse buffer size
  * Change Csrss priority to real time (safe)
  * Revert mouse buffer size to defult
  * Revert Csrss buffer size to default
  * Uses my registry editor and implements the same error handling

**MarkC Fix**
  * Apply popular MarkC mouse acceleration for set scaling factors
    * Scale Options: Default, 100%, 125%, 150%, 175%, 200%, 225%, 250%, 300%, and 350%
  * Revert to default windows mouse acceleration values
  * Uses my registry editor and implements the same error handling



## Examples - Registry Editor
### Create Registry Key and Value (REG_SZ)
```cpp
    [HKEY_CURRENT_USER\Control Panel\Mouse]
    // Make sure key is created and accessible. If not, create one. 

    RegistryManager regManager; // Defaults to HKEY_CURRENT_USER
    regManager.createKey("Control Panel\\Mouse");

    // Set/Create a value (REG_SZ)
    regManager.createVal("Control Panel\\Mouse", "10", "MouseSensitivity");
```

### Create Registry Key and Value (DWORD)
```cpp
    [HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\\Windows NT\CurrentVersion\Image File Execution Options\csrss.exe\PerfOptions]

    // Make sure key is created and accessible.
    RegistryManager regManager(HKEY_LOCAL_MACHINE);
    regManager.createKey("SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Image File Execution Options\\csrss.exe\\PerfOptions");

    // Set/Create a value (DWORD)
    regManager.createVal("SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Image File Execution Options\\csrss.exe\\PerfOptions" DWORD(4), "CpuPriorityClass");
```

### Create Registry Key and Vector of Values (REG_SZ)
```cpp
    [HKEY_CURRENT_USER\Control Panel\Mouse]

    // Curve data
    const std::vector<BYTE> xData = {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x15, 0x6e,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x01, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x29, 0xdc, 0x03, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00
    };

    // Make sure key is created and accessible.
    RegistryManager regManager;

    regManager.createKey("Control Panel\\Mouse");

    // Set/Create a value (Vec of REG_SZ)
    regManager.createVec("Control Panel\\Mouse", xData, "SmoothMouseXCurve");
```

### Create Registry Key and Vector of Values (REG_SZ)
```cpp
    [HKEY_CURRENT_USER\Control Panel\Mouse]

    // Curve data
    const std::vector<BYTE> xData = {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x15, 0x6e,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x01, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x29, 0xdc, 0x03, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00
    };

    // Make sure key is created and accessible.
    RegistryManager regManager;

    regManager.createKey("Control Panel\\Mouse");

    // Set/Create a value (Vec of REG_SZ)
    regManager.createVec("Control Panel\\Mouse", xData, "SmoothMouseXCurve");
```
## Examples - Mouse Tweaks
### Apply Mouse Tweaks 
```cpp
    MouseTweaks tweak;

    LONG statusCode = tweak.applyDataQueue();   // Defaults to a buffer of 20
    LONG statusCode = tweak.applyDataQueue(40); // Set a custom buffer
    LONG statusCode = tweak.applyBoostCsrss();
```

### Revert Mouse Tweaks 
```cpp
    MouseTweaks tweak;

    LONG statusCode = tweak.revertDataQueue();   
    LONG statusCode = tweak.revertBoostCsrss();
```

## Examples - MarkC Fix
### Apply MarkC Fix at a set Scale
```cpp
    MouseScaleFix fix;
    fix.setScale(Scale::Scale100);
    LONG returnValue = fix.applyMouseFix();
```
*or*
```cpp
    MouseScaleFix fix(Scale::Scale100);
    LONG returnValue = fix.applyMouseFix();
```

### Revert MarkC fix (applies defualt settings)
```cpp
    MouseScaleFix fix;
    fix.setScale(Scale::Default);
    LONG returnValue = fix.applyMouseFix();
```
*or*
```cpp
    MouseScaleFix fix(Scale::Default);
    LONG returnValue = fix.applyMouseFix();
```
*or*
```cpp
    MouseScaleFix fix();
    LONG returnValue = fix.applyMouseFix();
```

## Future Versions/Features
  * Create GUI (coming soon!)
  * Add more mouse tweaks
  * Add more MarkC scale options
  * Limit buffer size options (potential bug)
  * Add more registry value options

## Questions/Suggestions/Bug Reports
Add me on Discord: DaddyJuanito
