#include <functional>
#include <stdio.h>
#include <semaphore>
#include <thread>
using namespace std;

class Foo {
    std::binary_semaphore secondSemaphore = binary_semaphore(0);
    std::binary_semaphore thirdSemaphore = binary_semaphore(0);
public:
    Foo() {}

    void printFirst()  { printf("first"); }    
    void printSecond() { printf("second"); }
    void printThird()  { printf("third"); }

    void first(function<void()> printFirst) {
        printFirst();
        secondSemaphore.release();
    }

    void second(function<void()> printSecond) {
        secondSemaphore.acquire();
        printSecond();
        thirdSemaphore.release();
    }

    void third(function<void()> printThird) {
        thirdSemaphore.acquire();
        printThird();
    }
};