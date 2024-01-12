#include "RegistryManager.h"

RegistryManager::RegistryManager(HKEY rootKey) : m_rootKey(rootKey) {

}

void RegistryManager::createKey(const std::string& path) {
    HKEY hkey;
    LONG reg = RegCreateKeyExA(
        m_rootKey, // Use the member variable m_rootKey instead of a hardcoded key
        path.c_str(),
        0,
        NULL,
        REG_OPTION_NON_VOLATILE,
        KEY_ALL_ACCESS,
        NULL,
        &hkey,
        NULL
    );

    if (reg == ERROR_SUCCESS) {
        std::cout << "Registry key created successfully." << std::endl;
    }
    else {
        std::cout << "Failed to create registry key. Error code: " << reg << std::endl;
    }

    RegCloseKey(hkey);
}

void RegistryManager::createVec(const std::string& path, const std::vector<BYTE>& data, const std::string& valName) {
    HKEY hkey;
    LONG reg = openKey(path, KEY_ALL_ACCESS, &hkey);

    if (reg == ERROR_SUCCESS) {
        reg = RegSetValueExA(
            hkey,
            valName.c_str(),
            0,
            REG_BINARY,
            data.data(),
            static_cast<DWORD>(data.size())
        );

        if (reg == ERROR_SUCCESS) {
            std::cout << "Registry value has been edited successfully." << std::endl;
        }
        else {
            std::cout << "Failed to edit registry value." << std::endl;
        }
    }
    else {
        std::cout << "Failed to open registry key." << std::endl;
    }

    closeKey(hkey);
}

void RegistryManager::createVal(const std::string& path, const std::string& exepath, const std::string& valName) {
    HKEY hkey;
    LONG reg = openKey(path, KEY_ALL_ACCESS, &hkey);

    if (reg == ERROR_SUCCESS) {
        reg = RegSetValueExA(
            hkey,
            valName.c_str(),
            0,
            REG_SZ,
            reinterpret_cast<const BYTE*>(exepath.c_str()),
            static_cast<DWORD>(exepath.size() + 1)
        );

        if (reg == ERROR_SUCCESS) {
            std::cout << "Registry value has been edited successfully." << std::endl;
        }
        else {
            std::cout << "Failed to edit registry value." << std::endl;
        }
    }
    else {
        std::cout << "Failed to open registry key." << std::endl;
    }

    closeKey(hkey);
}

LONG RegistryManager::openKey(const std::string& subKey, REGSAM rights, HKEY* resultKey) {
    return RegOpenKeyExA(
        m_rootKey, // Use the member variable m_rootKey instead of a hardcoded key
        subKey.c_str(),
        0,
        rights,
        resultKey
    );
}


void RegistryManager::closeKey(HKEY hKey) {
    RegCloseKey(hKey);
}
