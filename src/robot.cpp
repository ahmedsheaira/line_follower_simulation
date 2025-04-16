// src/robot.cpp
#include "robot.hpp"

Robot::Robot(ControlStrategy* strategy)
    : sensors(5), strategy(strategy), linePosition(0.0) {}

void Robot::update() {
    sensors.update(linePosition);
    strategy->control(sensors, motors);
    motors.printStatus();

    // Simulate slight drift for demo
    linePosition += ((std::rand() % 3) - 1) * 0.5;
    linePosition = std::clamp(linePosition, -1.0, 1.0);
}

void Robot::run(int steps) {
    for (int itr=0 ; itr<steps ; ++itr) {
        std::cout << "Step " << itr + 1 << ":\n";
        update();
    }
}