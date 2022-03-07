////
//// Created by Kirill on 02.03.2022.
////

#include "PriorityQueue.h"

bool PriorityQueue::is_empty() const {
    return first_ == nullptr;
}

PriorityQueue::PriorityQueue() {
    first_ = nullptr;
    lastM_ = nullptr;
    lastM_ = nullptr;
    lastL_ = nullptr;
}

void PriorityQueue::push_high(const int &num) {
    QValue *el = new QValue(num, "High");
    sizeH_++;
    if (is_empty()) {
        first_ = el;
        lastH_ = el;
        return;
    }
    if (lastH_ == nullptr) {
        el->next = first_;
        first_ = el;
        lastH_ = el;
        return;
    }
    el->next = lastH_->next;
    lastH_->next = el;
    lastH_ = el;
}

void PriorityQueue::push_medium(const int &num) {
    QValue *el = new QValue(num, "Medium");
    sizeM_++;
    if (is_empty()) {
        first_ = el;
        lastM_ = el;
        return;
    }
    if (lastH_ == nullptr && lastM_ == nullptr) {
        el->next = first_;
        first_ = el;
        lastM_ = el;
    }
    if (lastM_ == nullptr) {
        el->next = lastH_->next;
        lastH_->next = el;
        lastM_ = el;
        return;
    }
    el->next = lastM_->next;
    lastM_->next = el;
    lastM_ = el;
}

void PriorityQueue::push_low(const int &num) {
    QValue *el = new QValue(num, "Low");
    sizeL_++;
    if (is_empty()) {
        first_ = el;
        lastL_ = el;
        return;
    }
    if (lastL_ == nullptr && lastM_ == nullptr) {
        lastH_->next = el;
        lastL_ = el;
        return;
    }
    if (lastL_ == nullptr && lastH_ == nullptr) {
        lastM_->next = el;
        lastL_ = el;
        return;
    }
    if (lastL_ == nullptr) {
        lastM_->next = el;
        lastL_ = el;
        return;
    }
    lastL_->next = el;
    lastL_ = el;
}

void PriorityQueue::Print() const {
    QValue *location = first_;
    std::cout << "Priority queue:";
    while (location != nullptr) {
        std::cout << ' ' << location->value_;
        location = location->next;
    }
    std::cout << std::endl;
}

int PriorityQueue::GetSizeH() const {
    return sizeH_;
}

int PriorityQueue::GetSizeM() const {
    return sizeM_;
}

int PriorityQueue::GetSizeL() const {
    return sizeL_;
}

int PriorityQueue::GetSize() const {
    return sizeL_ + sizeM_ + sizeH_;
}

void PriorityQueue::pop() {
    if (first_ == nullptr) {
        return;
    }
    if (first_->priority_ == "High")
        sizeH_--;
    if (first_->priority_ == "Medium")
        sizeM_--;
    if (first_->priority_ == "Low")
        sizeL_--;
    if (sizeH_ == 0)
        lastH_ = nullptr;
    if (sizeM_ == 0)
        lastM_ = nullptr;
    if (sizeL_ == 0)
        lastL_ = nullptr;
    QValue *newEl = first_->next;
    delete first_;
    first_ = newEl;
}

std::string PriorityQueue::frontInfo() {
    std::string info;
    info = "First element: " + std::to_string(first_->value_)
           + "; Priority: " + first_->priority_ + '\n';
    return info;
}

void PriorityQueue::operator=(const PriorityQueue &pq) {
    QValue *location = pq.first_;

    if (this == &pq) {
        return;
    }
    Clear();

    while (location != pq.lastH_->next) {
        push_high(location->value_);
        location = location->next;
    }
    while (location != pq.lastM_) {
        push_medium(location->value_);
        location = location->next;
    }
    while (location != nullptr) {
        push_low(location->value_);
        location = location->next;
    }
}

void PriorityQueue::Clear() {
    while (first_ != nullptr) {
        pop();
    }
}

void PriorityQueue::operator=(PriorityQueue &&pq) {
    if (this == &pq) {
        return;
    }
    Clear();

    first_ = pq.first_;
    lastH_ = pq.lastH_;
    lastM_ = pq.lastM_;
    lastL_ = pq.lastL_;
    sizeH_ = pq.sizeH_;
    sizeM_ = pq.sizeM_;
    sizeL_ = pq.sizeL_;

    pq.first_ = nullptr;
    pq.lastH_ = nullptr;
    pq.lastM_ = nullptr;
    pq.lastL_ = nullptr;
    pq.sizeH_ = 0;
    pq.sizeM_ = 0;
    pq.sizeL_ = 0;
}

PriorityQueue::PriorityQueue(PriorityQueue &pq) {
    if (this == &pq) {
        return;
    }
    Clear();

    QValue *el = pq.first_;
    while (el != pq.lastH_->next) {
        push_high(el->value_);
        el = el->next;
    }
    while (el != pq.lastM_) {
        push_medium(el->value_);
        el = el->next;
    }
    while (el != nullptr) {
        push_low(el->value_);
        el = el->next;
    }
}
