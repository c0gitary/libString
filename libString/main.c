#include <stdio.h>

#define len(ARR) (sizeof(&ARR)/sizeof(&ARR[0]))
#define SIZE_STRING 128

typedef struct String {
	char str[SIZE_STRING];
	unsigned short length;
}String_t;

unsigned short length_string(const char* _str) {
	unsigned short _len = 0;
	while (_str[_len] != '\0') {
		_len++;
	}
	return _len;
}

void string_init(String_t* str) {
	str->length = 0;
	str->str[0] = '\0';
}

void string_deinit(String_t* string) {
	free(string->str);
	free(string);
}

void string_append_char(String_t* str, const char ch) {
	if (str->length < SIZE_STRING - 1) {
		str->str[str->length] = ch;
		str->length++;
		str->str[str->length] = '\0';
	}
}

void string_append(String_t* string, const char* string2) {
	unsigned short len_str2 = length_string(string2);

	for (unsigned short i = 0; i < len_str2; ++i) {
		if (string->length > SIZE_STRING-1)return; // SIZE_STRING = 128

		string->str[string->length] = string2[i];
		string->length++;
	}
	string->str[string->length] = '\0';			// warn
	//*(str->str + str->length) = '\0';		// no warn ??

	return;
}

unsigned short string_find_char(String_t* string, char* ch){
	for (short i = 0; i < string->length; ++i) {
		if (string->str[i] == ch) {
			return i;
		}
	}
}

void string_replace_char(String_t* string, char* ch1, char* ch2) {
	string->str[string_find_char(string, ch1)] = ch2;
}


int main() {
	String_t st;

	string_init(&st);

	string_append(&st, "1234567890");

	printf("%s\n", st.str);

	string_replace_char(&st, '2', '5');

	printf("%s\n", st.str);

	string_deinit(&st);

	return 0;
}