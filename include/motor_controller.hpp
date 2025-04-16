/// @file motor_controller.hpp
/// @brief Controls virtual motor speeds for left and right wheels.

#ifndef MOTOR_CONTROLLER_HPP_
#define MOTOR_CONTROLLER_HPP_

#pragma once
#include <iostream>

/**
 * @brief Controls the movement of the robot by setting left and right motor speeds.
 */
class MotorController {
private:
    double leftSpeed;   ///< Current speed of left motor
    double rightSpeed;  ///< Current speed of right motor
public:
    MotorController();

    /**
     * @brief Updates motor speeds.
     * @param left New left motor speed (-1.0 to 1.0).
     * @param right New right motor speed (-1.0 to 1.0).
     */
    void setSpeed(double left, double right);

    /**
     * @brief Prints the current motor speeds (for simulation output).
     */
    void printStatus() const;
};

#endif
