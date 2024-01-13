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

// Creates a string value vector
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
            std::cout << "Failed to edit registry value. Error code: " << reg << std::endl;
        }
    }
    else {
        std::cout << "Failed to open registry key. Error code: " << reg << std::endl;
    }

    closeKey(hkey);
}

// Not passing T data as referance, since it is usally a small string or DWORD
// Still getting this to work
//template<typename T>
//void RegistryManager::createVal(const std::string& path, const T& data, const std::string& valName) {
//    HKEY hkey;
//    LONG reg = openKey(path, KEY_ALL_ACCESS, &hkey);
//    DWORD type;
//    LPCVOID pData;
//    DWORD dataSize;
//
//    if constexpr (std::is_same_v<T, std::string>) {
//        type = REG_SZ;
//        pData = reinterpret_cast<const BYTE*>(data.c_str());
//        dataSize = static_cast<DWORD>(data.size() + 1);
//    }
//    else if constexpr (std::is_same_v<T, DWORD>) {
//        type = REG_DWORD;
//        pData = reinterpret_cast<const BYTE*>(&data);
//        dataSize = sizeof(DWORD);
//    }
//    else {
//        // This will only cause a compile-time error if T is not std::string or DWORD
//        static_assert(std::is_same<T, std::string>::value || std::is_same<T, DWORD>::value,
//            "This value type is not supported.");
//    }
//
//    if (reg == ERROR_SUCCESS) {
//        reg = RegSetValueExA(hkey, valName.c_str(), 0, type, static_cast<const BYTE*>(pData), dataSize);
//
//        if (reg == ERROR_SUCCESS) {
//            std::cout << "Registry value has been edited successfully." << std::endl;
//        }
//        else {
//            std::cout << "Failed to edit registry value. Error code: " << reg << std::endl;
//        }
//    }
//    else {
//        std::cout << "Failed to open registry key. Error code: " << reg << std::endl;
//    }
//
//    closeKey(hkey);
//}


// Creates a string value
void RegistryManager::createVal(const std::string& path, const std::string& data, const std::string& valName) {
    HKEY hkey;
    LONG reg = openKey(path, KEY_ALL_ACCESS, &hkey);

    if (reg == ERROR_SUCCESS) {
        reg = RegSetValueExA(
            hkey,
            valName.c_str(),
            0,
            REG_SZ,
            reinterpret_cast<const BYTE*>(data.c_str()),
            static_cast<DWORD>(data.size() + 1)
        );

        if (reg == ERROR_SUCCESS) {
            std::cout << "Registry value has been edited successfully." << std::endl;
        }
        else {
            std::cout << "Failed to edit registry value. Error code: " << reg << std::endl;
        }
    }
    else {
        std::cout << "Failed to open registry key. Error code: " << reg << std::endl;
    }

    closeKey(hkey);
}

// Creates a DWORD value
void RegistryManager::createDWORDVal(const std::string& path, DWORD data, const std::string& valName) {
    HKEY hkey;
    LONG reg = openKey(path, KEY_ALL_ACCESS, &hkey);

    if (reg == ERROR_SUCCESS) {
        reg = RegSetValueExA(
            hkey,
            valName.c_str(),
            0,
            REG_DWORD,
            reinterpret_cast<const BYTE*>(&data),
            sizeof(DWORD)
        );

        if (reg == ERROR_SUCCESS) {
            std::cout << "Registry value has been edited successfully." << std::endl;
        }
        else {
            std::cout << "Failed to edit registry value. Error code: " << reg << std::endl;
        }
    }
    else {
        std::cout << "Failed to open registry key. Error code: " << reg << std::endl;
    }

    closeKey(hkey);
}

void RegistryManager::deleteVal(const std::string& path, const std::string& valName) {
    HKEY hkey;
    LONG reg = openKey(path, KEY_ALL_ACCESS, &hkey);

    if (reg == ERROR_SUCCESS) {
        reg = RegDeleteValueA(
            hkey,
            valName.c_str()
        );

        if (reg == ERROR_SUCCESS) {
            std::cout << "Registry value has been deleted successfully." << std::endl;
        }
        else {
            std::cout << "Failed to delete registry value. Is it already deleted? Error code: " << reg << std::endl;
        }
    }
    else {
        std::cout << "Failed to open registry key. Error code: " << reg << std::endl;
    }

    closeKey(hkey);
}

void RegistryManager::deleteKey(const std::string& path) {
    LONG reg = RegDeleteKeyA(
        m_rootKey,
        path.c_str()
    );

    if (reg == ERROR_SUCCESS) {
        std::cout << "Registry key has been deleted successfully." << std::endl;
    }
    else {
        std::cout << "Failed to delete registry key. Error code: " << reg << std::endl;
    }
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
