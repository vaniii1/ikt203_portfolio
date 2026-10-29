//
// Created by Ivan Hromovyi on 31/08/2026.
//

#include "GlobalFunctionProvider.h"

#include <iostream>

int Add(int a, int b) {
    return a + b;
}

std::string Greet(const std::string &name) {
    return  "Hello, " + name;
}

bool IsEven(int number) {
    return number % 2 == 0;
}

bool IsOdd(int number) {
    return number % 2 == 1;
}

void FilterAndPrint(
    const int numbers[], int size, bool (*predicate)(int number)
) {
    for (int i = 0; i < size; i++) {
        if (predicate(numbers[i])) {
            std::cout << numbers[i] << ", ";
        }
    }
    std::cout << std::endl;
}

void Play() {
    std::cout << "Playing game..." << std::endl;
}

void Pause() {
    std::cout << "Game paused." << std::endl;
}

void Quit() {
    std::cout << "Quitting game." << std::endl;
}

void DoubleInt(int& val) {
    val*=2;
}

void CapitalizeChar(char& val) {
    val = std::toupper(val);
}
