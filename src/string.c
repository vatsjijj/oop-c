#include <string.h>
#include "include/string.h"

DEF_METHOD(size_t, getLen, String)(String* this) {
	return MEMBER(len);
}

DEF_METHOD(const char*, asCStr, String)(String* this) {
	return MEMBER(cStr);
}

CONSTRUCTOR(String)(const char* cStr) {
	INIT(String);
	THIS(baseObject) = NEW(Object)();
	THIS(baseObject).name = "String";
	THIS(vt) = vt;
	THIS(len) = strlen(cStr);
	THIS(cStr) = cStr;
	OVERLOAD(this, getLen, getLenStringMethod);
	OVERLOAD(this, asCStr, asCStrStringMethod);
	return this;
}