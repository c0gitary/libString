#include "libstring.h"

static uint8_t _length_str(const char* string) {
	for (uint8_t length = 0;;length++) {
		if (string[length] == NULL_CHAR) {
			return length;
		}
	}
}

void string_init(String_t* string) {
	string->length = 0;
	*string->str = NULL_CHAR;
}

void string_append_char(String_t* string, const char ch) {
	if (string->length < SIZE - 1) {
		string->str[string->length] = ch;
		string->length++;
		string->str[string->length] = NULL_CHAR;
	}
	return;
}

void string_append_string(String_t* string, const char* string2) {
	for (uint8_t i = 0; i < _length_str(string2); ++i) {
		string->str[string->length] = string2[i];
		string->length++;
	}
	string->str[string->length] = NULL_CHAR;
}

bool string_eq(String_t* string1, String_t* string2){
	if (string1->length != string2->length) {
		return false;
	}

	for (uint8_t i = 0; i < string1->length; ++i) {
		if (string1->str[i] != string2->str[i]){
			return false;
		}
	}
	return true;
}

int8_t string_find_char(String_t* string, const char ch){
	uint8_t position = 0;
	while (position < string->length) {
		if (string->str[position] == ch) {
			return position;
		}
		position++;
	}
	return position;
}

int8_t string_find_string(String_t* string, const char* string2) {
	uint8_t len_string2 = _length_str(string2);

	for (uint8_t i = 0; i < string->length; ++i) {
		if (string->str[i] == *string2) {
			for (uint8_t j = 0, k = i; j < len_string2 + 1; ++j, ++k) {
				if (string->str[k] == string2[len_string2 - 1]) {
					return i;
				}
				if (!(string->str[k] == string2[j])) {
					break;
				}
			}
		}
		
	}
	return -1;
}
