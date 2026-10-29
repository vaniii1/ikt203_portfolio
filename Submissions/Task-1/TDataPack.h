//
// Created by Ivan Hromovyi on 31/08/2026.
//

#ifndef TEMPLATES_CALLBACKS_TDATAPACK_H
#define TEMPLATES_CALLBACKS_TDATAPACK_H
#include <tuple>

template <typename... Args>
struct TDataPack
{
    std::tuple<Args...> values;

    TDataPack(Args... args) : values(args...) {}
};

#endif //TEMPLATES_CALLBACKS_TDATAPACK_H