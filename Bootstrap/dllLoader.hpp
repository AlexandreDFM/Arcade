///*
//** EPITECH PROJECT, 2023
//** B-OOP-400-NCE-4-1-arcade-roman.lopes
//** File description:
//** dllLoader
//*/
//
//#ifndef DLL_LOADER_HPP
//    #define DLL_LOADER_HPP
//
//    #include <dlfcn.h>
//    #include <string.h>
//    #include <iostream>
//
//class DLLoader {
//    public:
//        DLLoader() {handle = nullptr;}
//        DLLoader(const std::string& path) {
//            handle = dlopen(path.c_str(), RTLD_LAZY);
//            if (!handle) {
//                std::cout << dlerror() << std::endl;
//            }
//        }
//        ~DLLoader() {
//            if (handle) {
//                dlclose(handle);
//                handle = nullptr;
//            }
//        }
//        template<typename T>
//        T* getFunction(const std::string& symbol) const {
//            T* (*symbolPtr)() = dlsym(handle, symbol.c_str());
//            if (!symbolPtr) {
//                std::cerr << "Failed to get symbol: " << symbol << '\n';
//                return nullptr;
//            }
//
//            return symbolPtr();
//        }
//    private:
//        void* handle;
//};
//
//#endif // DLL_LOADER_HPP
//
//// IGraphic *g = dll.getInstance<IGraphic*>("create");
