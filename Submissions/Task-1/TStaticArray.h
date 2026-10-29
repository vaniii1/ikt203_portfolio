//
// Created by Ivan Hromovyi on 31/08/2026.
//

#ifndef TEMPLATES_CALLBACKS_TSTATICARRAY_H
#define TEMPLATES_CALLBACKS_TSTATICARRAY_H

#include <iostream>

template <typename T, int Size>
class TStaticArray
{
public:
    void SetElement(int index, T value)
    {
        elements[index] = value;
    }

    void GetElements() const
    {
        for (int i = 0; i < Size; ++i)
        {
            std::cout << elements[i] << ", ";
        }
        std::cout << std::endl;
    }

private:
    T elements[Size];
};

#endif //TEMPLATES_CALLBACKS_TSTATICARRAY_H