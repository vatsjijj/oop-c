#include <stdlib.h>
#include "include/number.h"
#include "include/exception.h"

DEF_METHOD(bool, isDouble, Number)(Number* this) {
	return MEMBER(type) == Number_DOUBLE;
}

DEF_METHOD(bool, isInt, Number)(Number* this) {
	return MEMBER(type) == Number_INT;
}

DEF_METHOD(double, asDouble, Number)(Number* this) {
	if (METHOD(isInt)(this)) {
		THROW("Value is not a double.");
	}
	return MEMBER(as).d;
}

DEF_METHOD(int, asInt, Number)(Number* this) {
	if (METHOD(isDouble)(this)) {
		THROW("Value is not an integer.");
	}
	return MEMBER(as).i;
}

OL_CONSTRUCTOR(Number, NumberD)(double d) {
	INIT(Number);
	THIS(baseObject) = NEW(Object)();
	THIS(baseObject).name = "Number";
	THIS(vt) = vt;
	THIS(type) = Number_DOUBLE;
	THIS(as).d = d;
	return this;
}

OL_CONSTRUCTOR(Number, NumberI)(int i) {
	INIT(Number);
	THIS(baseObject) = NEW(Object)();
	THIS(baseObject).name = "Number";
	THIS(vt) = vt;
	THIS(type) = Number_INT;
	THIS(as).i = i;
	return this;
}

CONSTRUCTOR(Number)(uint8_t type, void* number) {
	Number this;
	if (type == Number_DOUBLE) {
		this = NEW(NumberD)(*(double*)number);
	}
	else if (type == Number_INT) {
		this = NEW(NumberI)(*(int*)number);
	}
	else {
		THROW("Expected an integer or a double.");
	}
	OVERLOAD(this, isDouble, isDoubleNumberMethod);
	OVERLOAD(this, isInt, isIntNumberMethod);
	OVERLOAD(this, asDouble, asDoubleNumberMethod);
	OVERLOAD(this, asInt, asIntNumberMethod);
	return this;
}