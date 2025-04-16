/// @file robot.hpp
/// @brief The Robot class ties everything together into a complete simulation

#ifndef ROBOT_HPP_
#define ROBOT_HPP_

#pragma once
#include "control_strategy.hpp"

/**
 * @brief Simulates a line-following robot using sensors, motors, and control strategy.
 */
class Robot {
private:
    SensorArray sensors;
    MotorController motors;
    ControlStrategy* strategy;
    double linePosition;    ///< Simulated position of the black line
public:
    /**
     * @brief Constructs a robot with a given control strategy.
     */
    Robot(ControlStrategy* strategy);

    /**
     * @brief Simulates one time step.
     */
    void update();

    /**
     * @brief Runs the simulation for a number of steps.
     * @param steps Number of simulation steps to run.
     */
    void run(int steps);
};

#endif
