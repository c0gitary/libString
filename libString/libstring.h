#pragma once

#define SIZE 128
#define NULL_CHAR '\0'
#define MAX(a, b) ((a)>(b)?(a):(b))
#define MIN(a, b) ((a)>(b)?(b):(a))

typedef enum {false, true} bool;
typedef unsigned short uint16_t;
typedef unsigned char  uint8_t;
typedef signed   char  int8_t;

typedef struct String{
	uint16_t length;
	char str[SIZE];
} String_t;

void string_init	(String_t* string);

void string_append_char		(String_t* string, const char ch);
void string_append_string	(String_t* string1, const String_t* string2);

void string_replace_char		(String_t* string, const char ch1, const char ch2);
void string_replace_all_char	(String_t* string, const char ch1, const char ch2);

bool string_eq	(const String_t* string1, const String_t* string2);

int8_t string_find_char		(const String_t* string, const char ch);
int8_t string_find_string	(const String_t* string, String_t* string2);
int8_t string_find_all_char	(const String_t* string, const char ch);