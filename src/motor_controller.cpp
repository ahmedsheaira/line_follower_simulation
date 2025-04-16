// src/motor_controller.cpp

#include "motor_controller.hpp"

MotorController::MotorController() : leftSpeed(0.0), rightSpeed(0.0) {}

void MotorController::setSpeed(double left, double right) {
    leftSpeed = left;
    rightSpeed = right;
}

void MotorController::printStatus() const {
    std::cout << "[Motors] Left: " << leftSpeed << ", Right: " << rightSpeed << std::endl;
}
