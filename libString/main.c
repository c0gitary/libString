#include <stdio.h>
#include "libstring.h"


int main() {
	String_t st, st2;

	string_init(&st);
	string_init(&st2);

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
	string_append_string(&st, "11131");
	//string_append(&st, &st2);
	

	printf(">> %i\n", string_find_string(&st, &st2));
	return 0;
}