#include <stdio.h>
#include "libString.h"




int main() {

	String_t* str = string_init("hello");
	String_t* str2 = string_init(" World");
	// Вывод массива src на консоль
	//printf("%s\n", str->data);

	string_replace_all_char(str, 'l', '1');

	printf("%s\n", str->data);

	string_free(str);
	string_free(str2);

	return 0;
}