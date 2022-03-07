#include <iostream>
#include "PriorityQueue.h"

int main() {
    PriorityQueue pq;
    if (pq.is_empty()) {
        std::cout << "pq is empty!" << '\n';
    } else std::cout << "pq is not empty! " << '\n';

    pq.push_high(1);
    pq.push_high(1);
    pq.push_high(1);
    pq.push_high(1);
    pq.push_low(3);
    pq.push_medium(2);
    pq.push_low(3);
    pq.push_medium(2);
    pq.push_low(3);
    pq.push_low(3);
    pq.push_low(3);
    pq.push_medium(2);
    pq.push_high(1);
    pq.push_medium(2);
    pq.push_low(3);
    pq.Print();
    std::cout << pq.frontInfo();
    std::cout << "H: " << pq.GetSizeH() << '\n'
              << "M: " << pq.GetSizeM() << '\n'
              << "L: " << pq.GetSizeL() << '\n'
              << "ALL: " << pq.GetSize() << '\n';
    PriorityQueue pq2;
    pq2 = pq;
    pq2.pop();
    pq2.pop();
    pq2.pop();
    pq2.pop();
    pq2.pop();
    pq2.pop();
    pq2.pop();
    pq2.pop();
    pq2.pop();
    pq2.Print();
    std::cout << "H: " << pq2.GetSizeH() << '\n'
              << "M: " << pq2.GetSizeM() << '\n'
              << "L: " << pq2.GetSizeL() << '\n'
              << "ALL: " << pq2.GetSize() << '\n';
    pq2.push_high(1);
    pq2.push_medium(2);
    pq2.Print();
    PriorityQueue pq3(pq2);
    pq3.Print();
    pq3.pop();
    pq3.Print();
    pq2.Print();
}
