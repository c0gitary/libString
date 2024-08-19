#include "libstring.h"

static uint8_t _length_str(const char* str) {
	uint8_t len = 0;
	while (str[len] != NULL_CHAR) {
		len++;
	}
	return len;
	//do {
	//	
	//} while (str[len] == NULL_CHAR);
}

void string_init(String_t* string) {
	string->length = 0;
	*string->str = NULL_CHAR;
}

void string_append(String_t* string, const char ch) {
	if (string->length < SIZE - 1) {
		string->str[string->length] = ch;
		string->length++;
		string->str[string->length] = NULL_CHAR;
	}
}

void string_append(String_t* string, const char* string2) {
	for (uint8_t i = 0; i < _length_str(string2); ++i) {
		string->str[string->length] = string2[i];
		string->length++;
	}
	string->str[string->length] = NULL_CHAR;
}