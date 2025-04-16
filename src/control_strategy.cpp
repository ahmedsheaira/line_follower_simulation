// src/control_strategy.cpp
#include "control_strategy.hpp"

// ===== Basic Stategy =====
void BasicLogicStrategy::control(const SensorArray& sensors, MotorController& motors) {
    int error = sensors.computeError();
    if (error < 0) {
        motors.setSpeed(0.4, 0.6);
    } else if (error > 0) {
        motors.setSpeed(0.6, 0.4);
    } else {
        motors.setSpeed(0.5, 0.5);
    }
}

// ===== PID Strategy =====
PIDStrategy::PIDStrategy(double kp_, double ki_, double kd_)
    : kp(kp_), ki(ki_), kd(kd_), integral(0), lastError(0) {}

void PIDStrategy::control(const SensorArray& sensors, MotorController& motors) {
    int error = sensors.computeError();
    integral += error;
    int derivative = error - lastError;
    lastError = error;

    double output = kp * error + ki * integral + kd * derivative;
    output = std::clamp(output, -1.0, 1.0);

    double base = 0.5;
    motors.setSpeed(base - output, base + output);
}
