#pragma once

#include <inttypes.h>


#define SIZE 128
#define NULL_CHAR '\0'
#define MAX(a, b) ((a)>(b)?(a):(b))
#define MIN(a, b) ((a)>(b)?(b):(a))

typedef enum {false, true} bool;

typedef struct String{
	uint16_t length;
	char str[SIZE];
}String_t;

void string_init(String_t* string);

void string_append_char(String_t* string, const char ch);
void string_append_string(String_t* string, const char* string2);

//void string_replace(String_t* string, const char ch, const char ch2);
//void string_replace(String_t* string, const char ch, const char* string2);
//void string_replace(String_t* string, const char* string2, const char ch);
//void string_replace(String_t* string, const char* string1, const char* string2);
//

bool string_eq(String_t* string1, String_t* string2);
//bool string_eq_chars(const char* string1, const char* string2);

uint8_t string_find_char(String_t* string, const char ch);
uint8_t string_find_string(String_t* string, const char* string2);