#include <functional>
#include <stdio.h>
#include <semaphore>
#include <thread>
using namespace std;

class FooBar {
private:
    int n;
    std::binary_semaphore fooSem = binary_semaphore(1);
    std::binary_semaphore barSem = binary_semaphore(0);

public:
    FooBar(int n) { this->n = n; }

    void printFoo() { printf("foo"); };
    void printBar() { printf("bar"); };

    void foo(function<void()> printFoo) {
        for (int i = 0; i < n; i++) {
            fooSem.acquire();
            printFoo();
            barSem.release();
        }
    }

    void bar(function<void()> printBar) {
        for (int i = 0; i < n; i++) {
            barSem.acquire();
            printBar();
            fooSem.release();
        }
    }
};