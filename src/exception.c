#include <stdlib.h>
#include <stdio.h>
#include "include/exception.h"

DEF_METHOD(String, getMessage, Exception)(Exception* this) {
	return MEMBER(message);
}

DEF_METHOD(void, throw, Exception)(Exception* this) {
	fprintf(stderr, "Uncaught exception:\n\t");
	fprintf(stderr, "%s\n", CALL(MEMBER(message), asCStr));
	exit(EXIT_FAILURE);
}

CONSTRUCTOR(Exception)(String message) {
	INIT(Exception);
	THIS(baseObject) = NEW(Object)();
	THIS(baseObject).name = "Exception";
	THIS(vt) = vt;
	THIS(message) = message;
	OVERLOAD(this, getMessage, getMessageExceptionMethod);
	OVERLOAD(this, throw, throwExceptionMethod);
	return this;
}