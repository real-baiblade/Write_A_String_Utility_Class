#include "String.h"
#include <string.h>

size_t String::Length(char* _arr) {
	int len;
	len = strlen(_arr);
	return len;
}