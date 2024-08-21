#include <stdio.h>
#include "libString.h"




int main() {

	String_t* str = string_init("hello");
	String_t* str2 = string_init("World");
	// Вывод массива src на консоль
	//printf("%s\n", str->data);

	String_t* str3 = string_concat(str, str2);

	string_println(str3);

	string_free(str);
	string_free(str2);
	string_free(str3);

	return 0;
}