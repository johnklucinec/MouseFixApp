#ifndef REGISTRY_MANAGER_H
#define REGISTRY_MANAGER_H

#include <iostream>
#include <vector>
#include <Windows.h>

class RegistryManager {
public:
    explicit RegistryManager(HKEY rootKey = HKEY_CURRENT_USER); // Constructor with default root key
    void createKey(const std::string& path);
    void createVec(const std::string& path, const std::vector<BYTE>& data, const std::string& valName = "");
    void createVal(const std::string& path, const std::string& exepath, const std::string& valName = "");

private:
    HKEY m_rootKey; // Member variable to store the root key
    LONG openKey(const std::string& subKey, REGSAM rights, HKEY* resultKey);
    void closeKey(HKEY hKey);
};

#endif // REGISTRY_MANAGER_H
