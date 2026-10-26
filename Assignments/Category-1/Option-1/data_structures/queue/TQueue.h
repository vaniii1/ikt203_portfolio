//
// Created by Ivan Hromovyi on 26/10/2026.
//

#ifndef IKT203_ALGORITHMS_DATASTRUCTURE_TQUEUE_H
#define IKT203_ALGORITHMS_DATASTRUCTURE_TQUEUE_H
#include <string>

struct TJob {
    int index;
    std::string text;
};

const int MAX_SIZE_QUEUE = 10;

class TQueue {
private:
    TJob* arr[MAX_SIZE_QUEUE];
    int front = 0;
    int back = -1;
    int jobCount = 0;
public:
    TQueue();
    ~TQueue();
    bool IsEmpty();
    bool Enqueue(TJob* job);
    TJob* Dequeue();
    TJob* Peek();
    void Clear();
};


#endif //IKT203_ALGORITHMS_DATASTRUCTURE_TQUEUE_H