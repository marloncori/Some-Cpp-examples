#ifndef SPEED_VALUE_H_
#define SPEED_VALUE_H_

constexpr long MAX_INT16 =  255;
constexpr long MIN_INT16 = -255;

enum SpeedValue {
	INITIAL      = 0,
	MAX_FORWARD  = MAX_INT16,
	MAX_BACKWARD = MIN_INT16,
};

#endif // speed_value.h
