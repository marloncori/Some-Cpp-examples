#ifndef SPEED_VALUE_H
#define SPEED_VALUE_H

constexpr unsigned int MAX_INT16 = 255;
constexpr unsigned int MIN_INT16 = -255;

enum SpeedValue {
    INITIAL        =  0,
    MAX_FORWARD    =  MAX_INT16,
    MAX_BACKWARD   =  MIN_INT16,
};

#endif // speed_direction.h