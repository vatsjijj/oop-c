#ifndef OBJECT_H
#define OBJECT_H

#include <stdint.h>
#include "class.h"

typedef CLASS(Object);

struct ObjectVTable {
	FPTR_T(const char*, className, (Object* this));
	FPTR_T(uint64_t, toHash, (Object* this));
};

struct Object {
	VTABLE(Object);
	const char* name;
	uint64_t hash;
};

DEF_METHOD(const char*, className, Object)(Object* this);
DEF_METHOD(uint64_t, toHash, Object)(Object* this);

CONSTRUCTOR(Object)();

#endif