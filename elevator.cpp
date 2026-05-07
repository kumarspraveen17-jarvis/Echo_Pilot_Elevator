#include "elevator.h"
#include <iostream>
#include <cmath>

Elevator::Elevator(int initialFloor, int speed)
    : currentFloor(initialFloor),
      speed(speed),
      direction(Direction::IDLE),
      doorState(DoorState::CLOSED) {}

void Elevator::addCall(int floor, int priority) {
    calls.push_back({floor, priority});
    std::cout << "[CALL ACCEPTED] Floor: " << floor
              << " Priority: " << priority << "\n";
}

bool Elevator::isCallAcceptable(const ElevatorCall& call) const {
    if (direction == Direction::IDLE)
        return true;

    if (direction == Direction::UP && call.floor >= currentFloor)
        return true;

    if (direction == Direction::DOWN && call.floor <= currentFloor)
        return true;

    return call.priority >= 3; // Override for high priority
}

int Elevator::selectBestCallIndex() const {
    int bestIndex = -1;
    int bestScore = -100000;

    for (int i = 0; i < calls.size(); ++i) {
        if (!isCallAcceptable(calls[i]))
            continue;

        int distance = std::abs(calls[i].floor - currentFloor);
        int score = (calls[i].priority * 100) - distance;

        if (score > bestScore) {
            bestScore = score;
            bestIndex = i;
        }
    }
    return bestIndex;
}

void Elevator::moveOneStep(int targetFloor) {
    if (currentFloor < targetFloor) {
        direction = Direction::UP;
        currentFloor += speed;
    } else if (currentFloor > targetFloor) {
        direction = Direction::DOWN;
        currentFloor -= speed;
    }

    std::cout << "[MOVING] Current floor: " << currentFloor << "\n";
}

void Elevator::handleDoors() {
    switch (doorState) {
        case DoorState::CLOSED:
            doorState = DoorState::OPENING;
            std::cout << "[DOOR] Opening...\n";
            break;
        case DoorState::OPENING:
            doorState = DoorState::OPEN;
            std::cout << "[DOOR] Opened\n";
            break;
        case DoorState::OPEN:
            doorState = DoorState::CLOSING;
            std::cout << "[DOOR] Closing...\n";
            break;
        case DoorState::CLOSING:
            doorState = DoorState::CLOSED;
            std::cout << "[DOOR] Closed\n";
            direction = Direction::IDLE;
            break;
    }
}

void Elevator::step() {
    if (calls.empty()) {
        std::cout << "[IDLE] No calls\n";
        return;
    }

    int index = selectBestCallIndex();
    if (index == -1)
        return;

    int targetFloor = calls[index].floor;

    if (currentFloor != targetFloor) {
        moveOneStep(targetFloor);
    } else {
        handleDoors();
        if (doorState == DoorState::CLOSED) {
            calls.erase(calls.begin() + index);
        }
    }
}

bool Elevator::hasPendingCalls() const {
    return !calls.empty();
}