#include "String.h"
#include <cstring>
#include <iostream>
using namespace std;

String::String() : str{ nullptr }  {
	str = new char[1];
	str[0] = '\0';
}

String::String(const char* _str) {
	if (_str == nullptr) {
		str = new char[1];
		str[0] = '\0';
	}
	else {
		str = new char[strlen(_str) + 1];

		strcpy(str, _str);
		str[strlen(_str)] = '\0';

		cout << "The string passed is : " << str << endl;
	}
}

String::String(const String& _other) {
	str = new char[strlen(_other.str) + 1];
	strcpy(str, _other.str);
	str[strlen(_other.str)] = '\0';
}

String::~String() {
	delete str;
}

size_t String::Length() const {
	return strlen(str);
}

char& String::CharacterAt(rsize_t index) {
	if ((index < 0) || (index > Length())) {
		char null = '\0';
		return null;
	}
	else {
		char item = str[index];
		return item;
	}
}