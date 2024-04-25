#ifndef STRING_H
#define STRING_H

#include <stddef.h>
#include "object.h"

typedef CLASS(String);

struct StringVTable {
	FPTR_T(size_t, getLen, (String* this));
	FPTR_T(const char*, asCStr, (String* this));
};

struct String {
	EXTENDS(Object);
	VTABLE(String);
	size_t len;
	const char* cStr;
};

DEF_METHOD(size_t, getLen, String)(String* this);
DEF_METHOD(const char*, asCStr, String)(String* this);

CONSTRUCTOR(String)(const char* cStr);

#endif