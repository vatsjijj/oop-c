#ifndef NUMBER_H
#define NUMBER_H

#include <stdbool.h>
#include <stdint.h>
#include "object.h"

typedef CLASS(Number);

struct NumberVTable {
	FPTR_T(bool, isDouble, (Number* this));
	FPTR_T(bool, isInt, (Number* this));
	FPTR_T(double, asDouble, (Number* this));
	FPTR_T(int, asInt, (Number* this));
};

struct Number {
	EXTENDS(Object);
	VTABLE(Number);
	enum {
		Number_DOUBLE,
		Number_INT,
	} type;
	union {
		double d;
		int i;
	} as;
};

DEF_METHOD(bool, isDouble, Number)(Number* this);
DEF_METHOD(bool, isInt, Number)(Number* this);
DEF_METHOD(double, asDouble, Number)(Number* this);
DEF_METHOD(int, asInt, Number)(Number* this);

OL_CONSTRUCTOR(Number, NumberD)(double d);
OL_CONSTRUCTOR(Number, NumberI)(int i);

CONSTRUCTOR(Number)(uint8_t type, void* number);

#endif