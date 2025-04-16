// src/main.cpp
#include <memory>
#include "robot.hpp"

int main() {
    std::unique_ptr<ControlStrategy> strategy;

    // Unvomment one of these:
    strategy = std::make_unique<BasicLogicStrategy>();
    // strategy = std::make_unique<PIDStrategy>(0.2, 0.01, 0.05);

    Robot robot(strategy.get());
    robot.run(20);  // Run 20 steps of simulation

    return 0;
}