#include <stdio.h>
#include "timer.hpp"

using namespace std::chrono_literals;

void long_operation()
{
    std::this_thread::sleep_for(1ms);
}

void fun() {
       TIMER(fun1);
        {   TIMER(fun2);
            long_operation();
        }
        long_operation();
        {   TIMER(fun3);
            long_operation();
        }
}

int main () {

    for (int i=0;i<10;i++) {
        fun();
    }
    for (avg_timer* i : avg_timer::all()){
        i->print();
    }

    return 0;
}
