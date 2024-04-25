#include "include/object.h"

DEF_METHOD(const char*, className, Object)(Object* this) {
	return MEMBER(name);
}

DEF_METHOD(uint64_t, toHash, Object)(Object* this) {
	if (MEMBER(hash)) return MEMBER(hash);
	MEMBER(hash) = (uint64_t)this;
	return MEMBER(hash);
}

CONSTRUCTOR(Object)() {
	INIT(Object);
	THIS(vt) = vt;
	THIS(hash) = 0;
	THIS(name) = "Object";
	OVERLOAD(this, className, classNameObjectMethod);
	OVERLOAD(this, toHash, toHashObjectMethod);
	return this;
}