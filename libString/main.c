#include <stdio.h>
#include "libstring.h"

int main() {

	String_t* str = string_init("HelloWorld");
	String_t* str2 = string_init("ello");
	// string_replace_all_char(str, 'l', '0');

	printf("%i\n", string_find_string(str, str2));

	string_free(str);
	string_free(str2);
	return 0;
}
