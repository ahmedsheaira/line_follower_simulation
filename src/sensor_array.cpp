// src/sensor_array.cpp

#include "sensor_array.hpp"

SensorArray::SensorArray(int count) : sensors(count, 0) {}

void SensorArray::update(double linePosition) {
    int center = sensors.size() / 2;
    for (int itr=0 ; itr<sensors.size() ; ++itr) {
        double pos = static_cast<double>(itr - center) / center;
        sensors[itr] = (std::abs(pos - linePosition) < 0.4) ? 1 : 0;
    }
}

const std::vector<int>& SensorArray::getReadings() const {
    return sensors;
}

int SensorArray::computeError() const {
    int error = 0;
    int center = sensors.size() / 2;
    for (int itr=0 ; itr<sensors.size() ; ++itr) {
        if (sensors[itr] == 1) {
            error += (itr - center);
        }
    }
    return error;
}
