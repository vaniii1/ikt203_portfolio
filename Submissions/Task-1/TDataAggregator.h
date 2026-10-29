//
// Created by Ivan Hromovyi on 31/08/2026.
//

#ifndef TEMPLATES_CALLBACKS_TDATAAGGREGATOR_H
#define TEMPLATES_CALLBACKS_TDATAAGGREGATOR_H

template <typename T>
class TDataAggregator {
    public:
    TDataAggregator() : stateTotal(T()) {}

    T GetStateTotal() {
        return stateTotal;
    }

    static void StaticCallback(T& val, void* context) {
        TDataAggregator* dataPointer = (TDataAggregator*)context;
        dataPointer->Accumulate(val);
    }

    private:
    T stateTotal;
    void Accumulate(T& val) {
        this->stateTotal += val;
        val*=2;
    }
};
#endif //TEMPLATES_CALLBACKS_TDATAAGGREGATOR_H