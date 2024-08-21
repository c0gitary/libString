#include <stdio.h>
#include "libString.h"




int main() {

	String_t* str = string_init("hel2lo");
	String_t* str2 = string_init("hello");
	// Вывод массива src на консоль
	//printf("%s\n", str->data);

	//string_replace_all_char(str, 'l', '1');

	printf("%i\n", string_eq(str,str2));

	string_free(str);
	string_free(str2);

	return 0;
}