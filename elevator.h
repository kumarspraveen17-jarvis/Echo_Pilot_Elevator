#ifndef ELEVATOR_H
#define ELEVATOR_H

#include <vector>

enum class Direction {
    UP,
    DOWN,
    IDLE
};

enum class DoorState {
    CLOSED,
    OPENING,
    OPEN,
    CLOSING
};

struct ElevatorCall {
    int floor;
    int priority;
};

class Elevator {
private:
    int currentFloor;
    int speed; // floors per step
    Direction direction;
    DoorState doorState;

    std::vector<ElevatorCall> calls;

    bool isCallAcceptable(const ElevatorCall& call) const;
    int selectBestCallIndex() const;

    void moveOneStep(int targetFloor);
    void handleDoors();

public:
    Elevator(int initialFloor = 0, int speed = 1);

    void addCall(int floor, int priority);
    void step();
    bool hasPendingCalls() const;
};

#endif
