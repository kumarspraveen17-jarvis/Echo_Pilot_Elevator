#include "elevator.h"
#include <thread>
#include <chrono>

int main() {
    Elevator lift(0, 1);

    lift.addCall(5, 1);
    lift.addCall(2, 1);
    lift.addCall(8, 3); // Emergency priority
    lift.addCall(6, 2);

    while (lift.hasPendingCalls()) {
        lift.step();
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

    return 0;
}