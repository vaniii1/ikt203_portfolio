#include <iostream>

#include "TStudent.h"
#include "TemplateProvider.h"
#include "GlobalFunctionProvider.h"
#include "TDataAggregator.h"
#include "TDataPack.h"

int main() {
    // Basic Template Functions
    PrintTypeSize(10);
    PrintTypeSize(10.1);

    TStudent student1{5};
    int &grade1 = student1.grade;
    TStudent student2{7};
    int &grade2 = student2.grade;

    std::cout << "What grade is higher? "
        << grade1 << " or " << grade2 << "? Answer: "
        << GetMax(grade1, grade2)<< std::endl;

    // Advanced Templates (Variadic and Non-Type):
    TDataPack pack(5, 2.5, "car");
    std::cout << "TDataPack: "
        << std::get<0>(pack.values) << ", "
        << std::get<1>(pack.values) << ", "
        << std::get<2>(pack.values) << std::endl;

    TStaticArray<int, 5> arr{};
    for (int i = 0; i < 5; ++i) {
        arr.SetElement(i, i * i);
    }
    std::cout << "TStaticArray: ";
    arr.GetElements();

    std::cout << "PrintContainer: ";
    PrintContainer(arr);

    // Global Callbacks (No Templates)
    int (*addPointer)(int, int) = Add;

    std::cout << addPointer(1, 4) << std::endl;
    std::cout << (*addPointer)(9, 1) << std::endl;

    GreetPointer gp = Greet;
    std::cout << gp("Bob") << std::endl;

    int callbackNumbers[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    FilterAndPrint(callbackNumbers, 10, IsEven);
    FilterAndPrint(callbackNumbers, 10, IsOdd);

    void (*actions[3])() = {Play, Pause, Quit};
    for (auto & action : actions)
    {
        action();
    }

    // The Bridge (Callbacks + Templates)
    int bridgeNumbers[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    char bridgeChars[10] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
    PrintArray(bridgeNumbers, 10);
    PrintArray(bridgeChars, 10);

    ProcessArray(bridgeNumbers, 10, DoubleInt);
    ProcessArray(bridgeChars, 10, CapitalizeChar);

    PrintArray(bridgeNumbers, 10);
    PrintArray(bridgeChars, 10);

    // The OOP Template Class & Context Pointers
    TDataAggregator<int> dataAggregator;
    int dataArray[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    ProcessWithContext(dataArray, 10,
        TDataAggregator<int>::StaticCallback, &dataAggregator);
    PrintArray(dataArray, 10);
    std::cout << "Aggregator total: " << dataAggregator.GetStateTotal() << std::endl;
    return 0;
}
