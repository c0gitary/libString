#pragma once

#include <stdlib.h>

#define SIZE 255
#define NULL_CHAR '\0'
#define MAX(a, b) ((a)>(b)?(a):(b))
#define MIN(a, b) ((a)>(b)?(b):(a))

typedef enum { false, true } bool;
typedef unsigned short uint16_t;
typedef unsigned char  uint8_t;
typedef signed   char  int8_t;

typedef struct String {
	char *data;
	size_t length;
	size_t cap;
} String_t;

//======================[ HEADER ]========================//

String_t* string_init(const char* string);

void string_free(String_t* string);

String_t* string_copy(const String_t* string);

String_t* string_concat(String_t* string1, String_t* string2);

String_t* string_uppercase(String_t* string);

String_t* stirng_lowercase(String_t* string);

int8_t string_find_char(const String_t* string, const char ch);

int8_t string_find_string(const String_t* main_string, const String_t* find_string);

size_t string_get_length(const String_t* string);

size_t string_get_capacity(const String_t* string);

bool string_eq(const String_t* string1, const String_t* string2);

void string_replace_char(String_t* string, const char ch1, const char ch2);

void string_replace_all_char(String_t* string, const char ch1, const char ch2);


//===================[ PRIVATE FUNC ]=====================//

static size_t _string_len(const char* string) {
	size_t len = 0;
	for (; *string != NULL_CHAR; ++len, ++string);
	return len;
}

static void _string_copy(char* src, const char* str) {
	while ((*src++ = *str++) != '\0');
}

static void* _mem_copy(char* dst, char* src, size_t count) {
	void* ret = dst;
	while (count--) *dst++ = *src++;
	return (ret);
}

static int8_t _mem_cmp(void* string1, void* string2, size_t count) {
	register const uint8_t* str1 = (const uint8_t*)string1;
	register const uint8_t* str2 = (const uint8_t*)string2;
	while (count-- > 0) {
		if (*str1++ != *str2++) {
			return str1[-1] < str2[-1] ? -1 : 1;
		}
	}
	return 0;
}


//========================================================//


String_t* string_init(const char* string) {
	String_t* __string = malloc(sizeof(String_t));

	if (__string == NULL) return NULL;
	
	__string->length = _string_len(string);
	__string->cap = __string->length+1;
	__string->data = malloc(sizeof(__string->cap));

	if (__string->data == NULL) {
		free(__string);
		return NULL;
	}
	_string_copy(__string->data, string);
	return __string;
}

void string_free(String_t* string) {
	if (string != NULL) {
		free(string->data);
		free(string);
		string = NULL;
	}
}

size_t string_get_length(const String_t* string) {
	return string->length;
}

size_t string_get_capacity(const String_t* string) {
	return string->cap;
}

String_t* string_concat(String_t* string1, String_t* string2) {
	size_t len_new_string = string1->length + string2->length;
	String_t* new_string = string_init("");
	new_string->length = len_new_string;
	new_string->cap = len_new_string + 1;
	new_string->data = malloc(new_string->cap);
	if (new_string->data == NULL) {
		return NULL;
	}
	_mem_copy(new_string->data, string1->data, string1->length);
	_mem_copy(new_string->data + string1->length, string2->data, string2->length);
	new_string->data[len_new_string] = NULL_CHAR;
	return new_string;
}

String_t* string_copy(const String_t* string) {
	return string_init(string->data);
}

int8_t string_find_char(const String_t* string, const char ch) {
	for (int8_t pos = 0; string->data[pos] != NULL_CHAR; ++pos) {
		if (string->data[pos] == ch) {
			return pos;
		}
	}
	return -1;
}

int8_t string_find_string(const String_t* main_string, const String_t* find_string){
	for (uint8_t i = 0; i < main_string->length; ++i) {
		if (main_string->data[i] == find_string->data[0]) {
			for (uint8_t j = 0, k = i; j < find_string->length + 1; ++j, ++k) {
				if (main_string->data[k] == find_string->data[find_string->length - 1]) {
					return i;
				}
				if (!(main_string->data[k] == find_string->data[j])) {
					break;
				}
			}
		}
	}
	return -1;
}

void string_replace_char(String_t* string, const char ch1, const char ch2) {
	string->data[string_find_char(string, ch1)] = ch2;
}

void string_replace_all_char(String_t* string, const char ch1, const char ch2) {
	for (char* ptr = string->data; *ptr != NULL_CHAR; ++ptr) {
		if (*ptr == ch1) {
			*ptr = ch2;
		}
	}
}

bool string_eq(const String_t* string1, const String_t* string2) {
	if (string1->length != string2->length) return false;
	return _mem_cmp(string1->data, string2->data, string1->length) == 0;
}