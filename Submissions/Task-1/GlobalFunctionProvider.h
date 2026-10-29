//
// Created by Ivan Hromovyi on 31/08/2026.
//

#ifndef TEMPLATES_CALLBACKS_GLOBALFUNCTION_H
#define TEMPLATES_CALLBACKS_GLOBALFUNCTION_H
#include <string>

int Add(int a, int b);

using GreetPointer = std::string(*)(const std::string&);
std::string Greet(const std::string &name);

bool IsEven(int number);
bool IsOdd(int number);
void FilterAndPrint(const int numbers[], int size, bool (*predicate)(int number));

void Play();
void Pause();
void Quit();

void DoubleInt(int& val);
void CapitalizeChar(char& val);

#endif //TEMPLATES_CALLBACKS_GLOBALFUNCTION_H