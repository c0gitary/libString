#include <stdio.h>
#include "libstring.h"


int main() {
	String_t st, st2;

	string_init(&st, "hello");
	//string_init(&st2);

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
	//string_append(&st, &st2);
	

	printf(">> %s\n", st.str);
	return 0;
}