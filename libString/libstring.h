#pragma once

#include <inttypes.h>

#define SIZE 128
#define NULL_CHAR '\0'

typedef struct String{
	uint16_t length;
	char str[SIZE];
}String_t;

void string_init(String_t* string);

void string_append(String_t* string, const char ch);
void string_append(String_t* string, const char* string2);

void string_replace(String_t* string, const char ch, const char ch2);
void string_replace(String_t* string, const char ch, const char* string2);
void string_replace(String_t* string, const char* string2, const char ch);
void string_replace(String_t* string, const char* string1, const char* string2);

void string_find(String_t* string, const char ch);
void string_find(String_t* string, const char* string2);