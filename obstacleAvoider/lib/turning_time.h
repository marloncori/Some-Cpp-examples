#ifndef TURNING_TIME_H
#define TURNING_TIME_H

constexpr int MAX_ANGLE = 180;

enum TurningTime {
    MAX_ARRIVAL_TIME    = 800,
    ARRIVAL_TIME_OFFSET = MAX_ARRIVAL_TIME/MAX_ANGLE,
};

#endif // turning_time.h