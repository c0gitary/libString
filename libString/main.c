#include <stdio.h>
#include "libstring.h"


int main() {
	String_t st;

	string_init(&st);

	//printf("%i\n", string_find_char(&st, 'a'));

	//double nc = 0;

	/*while ((getchar()) != EOF) {
		nc++;
	}*/

	//for (int i = 0; i < 3; i++) {
	//	//printf(">> %s\n", nc);
	//	string_append_char(&st, getchar());
	//
	//}

	string_append_string(&st, "hellfdsfsdfsdoWorld");

	printf(">> %i\n", string_find_string(&st, "World"));
	return 0;
}