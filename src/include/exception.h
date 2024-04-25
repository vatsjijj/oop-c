#ifndef EXCEPTION_H
#define EXCEPTION_H

#include "string.h"

#define THROW(message)                \
	String msg = NEW(String)(message); \
	Exception e = NEW(Exception)(msg); \
	CALL(e, throw)

typedef CLASS(Exception);

struct ExceptionVTable {
	FPTR_T(String, getMessage, (Exception* this));
	FPTR_T(void, throw, (Exception* this));
};

struct Exception {
	EXTENDS(Object);
	VTABLE(Exception);
	String message;
};

DEF_METHOD(String, getMessage, Exception)(Exception* this);
DEF_METHOD(void, throw, Exception)(Exception* this);

CONSTRUCTOR(Exception)(String message);

#endif