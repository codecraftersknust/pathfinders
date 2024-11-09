#ifndef BICDRIVE_ARDUINO_STEERING_HPP
#define BICDRIVE_ARDUINO_STEERING_HPP

#include <string>
#include <cmath>

class Steering
{
public:
    std::string name = "";
    double pos = M_PI_2;

    Steering() = default;

    Steering(const std::string &steering_name)
    {
        setup(steering_name);
    }

    void setup(const std::string &steering_name)
    {
        name = steering_name;
    }
};


#endif // BICDRIVE_ARDUINO_STEERING_HPP