#include <stdio.h>
#include "libstring.h"




int main() {

	String_t* str = string_init("hel2lo");
	String_t* str2 = string_init("hello");

	printf("%i\n", string_eq(str,str2));

	string_free(str);
	string_free(str2);

	return 0;
}