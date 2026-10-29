//
// Created by Ivan Hromovyi on 31/08/2026.
//

#ifndef TEMPLATES_CALLBACKS_TEMPLATE_H
#define TEMPLATES_CALLBACKS_TEMPLATE_H
#include "TStaticArray.h"
#include <iostream>

template <typename T>
void PrintTypeSize(T v)
{
    std::cout << sizeof(v) << " bytes" << std::endl;
}

template <typename T>
T GetMax(T a, T b)
{
    return (a > b) ? a : b;
}

template <template <typename, int> class Container, typename T, int N>
void PrintContainer(const Container<T, N>& container)
{
    container.GetElements();
}

template <typename T>
using FActionFunc = void(*)(T&);
template <typename T>
void ProcessArray(T *arr, int size, FActionFunc<T> function) {
    for (int i = 0; i < size; i++) {
        function(arr[i]);
    }
}

template <typename T>
void PrintArray(T *arr, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << ", ";
    }
    std::cout << std::endl;
}

template <typename T>
using FContextFunc = void(*)(T&, void*);
template <typename T>
void ProcessWithContext(T *arr, int size, FContextFunc<T> function, void* context) {
    for (int i = 0; i < size; i++) {
        function(arr[i], context);
    }
}

#endif //TEMPLATES_CALLBACKS_TEMPLATE_H