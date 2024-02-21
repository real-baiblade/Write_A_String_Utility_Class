#include "String.h"
#include <string.h>

size_t String::Length(char* _arr) {
	int len;
	len = strlen(_arr);
	len -= 1;
	return len;
}

char& String::CharacterAt(char* _arr, size_t _index) {
	char character;
	character = _arr[_index];
	return character;
}