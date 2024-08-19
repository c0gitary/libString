#include <stdio.h>
#include "libstring.h"


int main() {
	String_t st;

	string_init(&st);

	string_append(&st, "1234567890");

	printf("%s\n", st.str);

	printf("%s\n", st.str);

	string_deinit(&st);

	return 0;
}