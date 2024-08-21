#pragma once

#include <stdio.h>
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
	uint8_t *data;
	size_t length;
	size_t cap;
} String_t;

//======================[ HEADER ]========================//

String_t* string_init(const char* string);

void string_free(String_t* string);

void string_print(const String_t* string);

String_t* string_copy(const String_t* string);

String_t* string_concat(String_t* string1, String_t* string2);

String_t* string_uppercase(String_t* string);

String_t* stirng_lowercase(String_t* string);

size_t string_get_length(const String_t* string);

size_t string_get_capacity(const String_t* string);


//===================[ PRIVATE FUNC ]=====================//

static size_t _string_len(const char* string) {
	size_t len = 0;
	while (*string != NULL_CHAR) {
		len++;
		string++;
	}
	return len;
}

static void _string_copy(char* src, char* str) {
	while ((*src++ = *str++) != '\0');
}

static void _mem_copy(void* dest, void* src, size_t count) {
	char* __dst = (char*)dest;
	char* __src = (char*)src;
	while (count--) {
		*__dst++ = *__src++;
	}
	return dest;
}

//========================================================//


String_t* string_init(const char* string) {
	String_t* __string = malloc(sizeof(String_t));

	if (__string == NULL) {
		return NULL;
	}

	__string->length = _string_len(string);
	__string->cap = __string->length++;
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

void string_println(const String_t* string){
	printf("%s\n", string->data);
}

size_t string_get_length(const String_t* string) {
	return string->length;
}

size_t string_get_capacity(const String_t* string) {
	return string->cap;
}

String_t* string_concat(String_t* string1, String_t* string2) {
	size_t len_new_string = string1->length + string2->length;
	String_t* new_string = string_init(NULL);
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

//String_t* string_uppercase(String_t* string) {
//	for (size_t i = 0; i < string->length; ++i) {
//
//	}
//}


//typedef struct String {
//	uint16_t length;
//	char str[SIZE];
//} String_t;
//
//static uint8_t _length_str(const char* string) {
//	for (uint8_t length = 0;;length++) {
//		if (string[length] == NULL_CHAR) {
//			return length;
//		}
//	}
//}
//
////void* memcopy(void* _dest, const void* _src, size_t _count) {
////	
////}
//
//void string_init(String_t* string, const char* _string) {
//	string->length = 0;
//	for (uint8_t i = 0; i < _length_str(_string); ++i) {
//		string->str[i] = _string[i];
//		string->length++;
//	}
//	string->str[string->length+1] = NULL_CHAR;
//}
//
//int8_t string_find_char(String_t* string, const char ch) {
//	uint8_t position = 0;
//	while (position < string->length) {
//		if (string->str[position] == ch) {
//			return position;
//		}
//		position++;
//	}
//	return position;
//}
//
//int8_t string_find_string(String_t* string, String_t* string2) {
//	uint8_t len_string2 = _length_str(string2);
//
//	for (uint8_t i = 0; i < string->length; ++i) {
//		if (string->str[i] == string2->str[0]) {
//			for (uint8_t j = 0, k = i; j < len_string2 + 1; ++j, ++k) {
//				if (string->str[k] == string2->str[len_string2 - 1]) {
//					return i;
//				}
//				if (!(string->str[k] == string2->str[j])) {
//					break;
//				}
//			}
//		}
//	}
//	return -1;
//}
//
//int8_t string_find_all_char(String_t* string, const char ch) {
//	int8_t incr = 0;
//	for (uint8_t i = 0; i < string->length; ++i) {
//		if (string->str[i] == ch) {
//			++incr;
//		}
//	}
//	return incr;
//}
//
//void string_replace_char(String_t* string, const char ch1, const char ch2) {
//	int8_t position = string_find_char(string, ch1);
//	string->str[position] = ch2;
//}
//
//void string_append_char(String_t* string, const char ch) {
//	if (string->length < SIZE - 1) {
//		string->str[string->length] = ch;
//		string->length++;
//		string->str[string->length] = NULL_CHAR;
//	}
//	return;
//}
//
//void string_append_string(String_t* string1, String_t* string2) {
//	for (uint8_t i = 0; i < string2->length; ++i) {
//		string_append_char(string1, string2->str[i]);
//	}
//	return;
//}
//
//void string_replace_all_char(String_t* string, const char ch1, const char ch2) {
//	for (uint8_t i = 0; i < string->length; i++) {
//		if (string->str[i] == ch1) {
//			string->str[i] = ch2;
//		}
//	}
//}
//
//void string_lowercase(String_t* string) {
//
//}
//
//bool string_eq(String_t* string1, String_t* string2) {
//	if (string1->length != string2->length) {
//		return false;
//	}
//
//	for (uint8_t i = 0; i < string1->length; ++i) {
//		if (string1->str[i] != string2->str[i]) {
//			return false;
//		}
//	}
//	return true;
//}