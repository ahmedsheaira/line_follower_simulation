/// @file sensor_array.hpp
/// @brief Defines a virtual IR sensor array used for line dtection

#ifndef SENSOR_ARRAY_HPP_
#define SENSOR_ARRAY_HPP_

#pragma once
#include <vector>
#include <cmath>

/**
 * @brief Simulates an array of infrared sensor for line tracking
 */
class SensorArray {
private:
    std::vector<int> sensors;    ///< Vector of sensor readings (0 = white, 1 = black).
public:
    /**
     * @brief Constructs a sensor array with a given number of sensors.
     * @param count Number of sensors in the array.
     */
    SensorArray(int count = 5);

    /**
     * @brief Simulate new readings based on robot's alignment.
     * @param linePosition Simulated offset of the line (-1.0 to 1.0).
     */
    void update(double linePosition);

    /**
     * @brief Returns current sensor readings.
     */
    const std::vector<int>& getReadings() const;

    /**
     * @brief Computes an error value for control (e.g. -2 to +2 for a 5-sensor setup).
     */
    int computeError() const;
};

#endif
