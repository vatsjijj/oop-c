#include <stdio.h>
#include "include/number.h"
#include "include/string.h"
#include "include/exception.h"

int main() {
	Object o = NEW(Object)();
	printf("%s\n", CALL(o, className));
	printf("%lu\n", CALL(o, toHash));

	double d = 10.2;
	Number n1 = NEW(Number)(Number_DOUBLE, &d);
	int i = 10;
	Number n2 = NEW(Number)(Number_INT, &i);
	printf("n1 int? %d\n", CALL(n1, isInt));
	printf("n2 int? %d\n", CALL(n2, isInt));
	printf("n1 val %g\n", CALL(n1, asDouble));
	printf("n2 val %d\n", CALL(n2, asInt));
	Object n1o = CAST(n1, Object);
	printf("%s\n", CALL(n1o, className));

	String s = NEW(String)("i am a string");
	printf("str len %zu\n", CALL(s, getLen));
	printf("str content %s\n", CALL(s, asCStr));

	double d2 = 157.3;
	Number good = NEW(Number)(Number_DOUBLE, &d2);
	double res = CALL(good, asDouble);
	printf("%g\n", res);
	return 0;
}