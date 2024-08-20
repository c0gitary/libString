#pragma once

#define SIZE 255
#define NULL_CHAR '\0'
#define MAX(a, b) ((a)>(b)?(a):(b))
#define MIN(a, b) ((a)>(b)?(b):(a))

typedef enum { false, true } bool;
typedef unsigned short uint16_t;
typedef unsigned char  uint8_t;
typedef signed   char  int8_t;

typedef struct String {
	uint16_t length;
	char str[SIZE];
} String_t;

static uint8_t _length_str(const char* string) {
	for (uint8_t length = 0;;length++) {
		if (string[length] == NULL_CHAR) {
			return length;
		}
	}
}

void string_init(String_t* string, const char* _string) {
	string->length = 0;
	for (uint8_t i = 0; i < _length_str(_string); ++i) {
		string->str[i] = _string[i];
		string->length++;
	}
	string->str[string->length] = NULL_CHAR;
}

int8_t string_find_char(String_t* string, const char ch) {
	uint8_t position = 0;
	while (position < string->length) {
		if (string->str[position] == ch) {
			return position;
		}
		position++;
	}
	return position;
}

int8_t string_find_string(String_t* string, String_t* string2) {
	uint8_t len_string2 = _length_str(string2);

	for (uint8_t i = 0; i < string->length; ++i) {
		if (string->str[i] == string2->str[0]) {
			for (uint8_t j = 0, k = i; j < len_string2 + 1; ++j, ++k) {
				if (string->str[k] == string2->str[len_string2 - 1]) {
					return i;
				}
				if (!(string->str[k] == string2->str[j])) {
					break;
				}
			}
		}
	}
	return -1;
}

int8_t string_find_all_char(String_t* string, const char ch) {
	int8_t incr = 0;
	for (uint8_t i = 0; i < string->length; ++i) {
		if (string->str[i] == ch) {
			++incr;
		}
	}
	return incr;
}

void string_replace_char(String_t* string, const char ch1, const char ch2) {
	int8_t position = string_find_char(string, ch1);
	string->str[position] = ch2;
}

void string_append_char(String_t* string, const char ch) {
	if (string->length < SIZE - 1) {
		string->str[string->length] = ch;
		string->length++;
		string->str[string->length] = NULL_CHAR;
	}
	return;
}

void string_append_string(String_t* string1, String_t* string2) {
	for (uint8_t i = 0; i < string2->length; ++i) {
		string_append_char(string1, string2->str[i]);
	}
	return;
}

void string_replace_all_char(String_t* string, const char ch1, const char ch2) {
	for (uint8_t i = 0; i < string->length; i++) {
		if (string->str[i] == ch1) {
			string->str[i] = ch2;
		}
	}
}

void string_lowercase(String_t* string) {

}

bool string_eq(String_t* string1, String_t* string2) {
	if (string1->length != string2->length) {
		return false;
	}

	for (uint8_t i = 0; i < string1->length; ++i) {
		if (string1->str[i] != string2->str[i]) {
			return false;
		}
	}
	return true;
}