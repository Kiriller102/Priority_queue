//
// Created by Kirill on 02.03.2022.
//

#ifndef PRIORITY_QUEUE_PRIORITYQUEUE_H
#define PRIORITY_QUEUE_PRIORITYQUEUE_H


#include <exception>
#include <iostream>
#include <string>
#include <utility>
#include <algorithm>

class PriorityQueue {
public:

    void Clear();

    PriorityQueue();

    PriorityQueue(PriorityQueue &);

    bool is_empty() const;

    std::string frontInfo();

    void push_high(const int &);

    void push_medium(const int &);

    void push_low(const int &);

    void pop();

    void Print() const;

    int GetSizeH() const;

    int GetSizeM() const;

    int GetSizeL() const;

    int GetSize() const;

    void operator=(const PriorityQueue &);

    void operator=(PriorityQueue &&);

    PriorityQueue(PriorityQueue &&pq) noexcept:
            first_(std::move(pq.first_)),
            lastH_(std::move(pq.lastH_)),
            lastM_(std::move(pq.lastM_)),
            lastL_(std::move(pq.lastL_)),
            sizeH_(std::move(pq.sizeH_)),
            sizeM_(std::move(pq.sizeM_)),
            sizeL_(std::move(pq.sizeL_)) {
        pq.first_ = nullptr;
        pq.lastH_ = nullptr;
        pq.lastM_ = nullptr;
        pq.lastL_ = nullptr;
        pq.sizeH_ = 0;
        pq.sizeM_ = 0;
        pq.sizeL_ = 0;
    };
private:
    struct QValue {
        int value_;
        QValue *next;
        std::string priority_;

        explicit QValue(int value, std::string priority) :
                value_(value), priority_(std::move(priority)), next(nullptr) {};
    };

    QValue *first_ = nullptr;
    QValue *lastH_ = nullptr;
    QValue *lastM_ = nullptr;
    QValue *lastL_ = nullptr;

    int sizeH_ = 0;
    int sizeM_ = 0;
    int sizeL_ = 0;
};

#endif //PRIORITY_QUEUE_PRIORITYQUEUE_H