/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-arcade-roman.lopes
** File description:
** dllLoader
*/

#ifndef DLL_LOADER_HPP
    #define DLL_LOADER_HPP

    #include <dlfcn.h>
    #include "IDisplay.hpp"

    typedef IDisplayModule* (*create_instance_t)();

    template<typename T>

class DLLoader {
    public:
        DLLoader(const std::string& path) {
            handle = dlopen(path.c_str(), RTLD_LAZY);
            if (!handle) {
                std::cout << dlerror() << std::endl;
            }
        }

        ~DLLoader() {
            if (handle) {
                dlclose(handle);
                handle = nullptr;
            }
        }

        T* getInstance(const std::string& symbol) const {
            void* symbolPtr = dlsym(handle, symbol.c_str());
            if (!symbolPtr) {
                std::cerr << "Failed to get symbol: " << symbol << '\n';
                return nullptr;
            }
            create_instance_t createInstance = reinterpret_cast<create_instance_t>(symbolPtr);
            return createInstance();
        }
    private:
        void* handle;
};

#endif // DLL_LOADER_HPP
