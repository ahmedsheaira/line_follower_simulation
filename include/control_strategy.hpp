/// @file control_strategy.hpp
/// @brief Provides abstract and concrete control strategies (Basic, PID).

#ifndef CONTROL_STRATEGY_HPP
#define CONTROL_STRATEGY_HPP

#pragma once
#include <algorithm>
#include "sensor_array.hpp"
#include "motor_controller.hpp"

/**
 * @brief Intergfaces for control strategy.
 */
class ControlStrategy {
public:
    virtual ~ControlStrategy() = default;

    /**
     * @brief Executes one control loop step.
     */
    virtual void control(const SensorArray& sensors, MotorController& motors) = 0;
};

/**
 * @brief Basic if-else logic for line following.
 */
class BasicLogicStrategy : public ControlStrategy {
public:
    void control(const SensorArray& sensors, MotorController& motors) override;
};

/**
 * @brief PID control strategy for smoother tracking.
 */
class PIDStrategy : public ControlStrategy {
private:
    double kp, ki, kd;
    double integral;
    int lastError;
public:
    /**
     * @brief Initializes PID parameters.
     */
    PIDStrategy(double kp_, double ki_, double kd_);

    void control(const SensorArray& sensors, MotorController& motors) override;
};

#endif
