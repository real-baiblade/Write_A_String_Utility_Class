#include "String.h"
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

String::String() {
	str = new char[1];
	str[0] = '\0';
	temp = new char[1];
	temp[0] = '\0';
	at_index = new char[1];
	at_index[0] = '\0';
}

String::String(const char* _str) {
	if (_str == nullptr) {
		str = new char[1];
		str[0] = '\0';
		temp = new char[1];
		temp[0] = '\0';
		at_index = new char[1];
		at_index[0] = '\0';
	}
	else {
		str = new char[strlen(_str) + 1];

		strcpy(str, _str);
		str[strlen(_str)] = '\0';

		cout << "The string passed is : " << str << endl;

		temp = new char[1];
		temp[0] = '\0';
		at_index = new char[1];
		at_index[0] = '\0';
	}
}

String::String(const String& _other) {
	str = new char[strlen(_other.str) + 1];
	strcpy(str, _other.str);
	str[strlen(_other.str)] = '\0';

	temp = new char[1];
	temp[0] = '\0';
	at_index = new char[1];
	at_index[0] = '\0';
}

String::~String() {
	str = nullptr;
	temp = nullptr;
	at_index = nullptr;
	delete str;
	delete temp;
	delete at_index;
}

size_t String::Length() const {
	int len = 0;
	int i = 0;
	while (str[i] != '\0') { // iterates through the string until str[i] is the null terminator
		len += 1; // if not the null terminator, len is increased by 1
		i += 1;
	}
	return len;
}

char& String::CharacterAt(size_t _index) {
	if ((_index < 0) || (_index > Length())) { // checks if index passed is within the bounds
		char null = '\0';
		return null;
	}
	else {
		char item = str[_index];
		return item;
	}
}

const char& String::CharacterAt(size_t _index) const {
	if ((_index < 0) || (_index > Length())) {
		char null = '\0';
		return null;
	}
	else {
		char item = str[_index];
		return item;
	}
}

bool String::EqualTo(const String& _other) const {
	if (this->str == _other.str) {
		return true;
	}
	else {
		return false;
	}
}

String& String::Append(const String& _str) {
	int len;
	len = Length();
	for (int i = 0; i < _str.Length(); i++) {
		str[i + len] = _str.str[i]; // assigns the _str string to the end of str
	}
	str[len + _str.Length()] = '\0';
	return *this;
}

String& String::Prepend(const String& _str) {
	int len;
	len = Length();
	int len2;
	len2 = _str.Length();
	temp = _str.str;
	for (int j = 0; j < len; j++) {
		temp[j + len2] = str[j];
	}
	str = temp;
	str[len + len2] = '\0';
	return *this;
}

const char* String::CStr() const {
	const char* c_str = str; // assigns the value of str to a char pointer, returning a cstring
	return c_str;
}

String& String::ToLower() {
	for (int i = 0; i < Length(); i++) {
		if (65 <= str[i] && str[i] <= 90) { // checks if the value of an index is a capital letter
			str[i] += 32; // assigns the lowercase version of the character to the index
		}
	}
	return *this;
}

String& String::ToUpper() {
	for (int i = 0; i < Length(); i++) {
		if (97 <= str[i] && str[i] <= 122) { // checks if the value of an index is a lowercase letter
			str[i] -= 32; // assigns the uppercase version of the character to the index
		}
	}
	return *this;
}

int String::Find(const String& _str) {
	int start = 0;
	for (int i = 0; i < Length(); i++) {
		if (str[i] == _str.str[0]) { // checks if the value in str[i] is the same as the first character in the find string
			start = i;
			for (int j = 0; j < _str.Length(); j++) {
				if (str[i + j] == _str.str[j]) {
					temp[j] = _str.str[j]; // adds every letter that is the same as the find string within str to temp
				}
			}
			for (int k = 0; k < _str.Length(); k++) {
				if (temp[k] != _str.str[k]) { // checks if temp is the same as the find string
					return -1;
				}
			}
			return start;
		}
	}
	return -1;
}

int String::Find(size_t _startIndex, const String& _str) {
	int start = 0;
	for (int i = _startIndex; i < Length(); i++) { // same as other find function, but starts at the start index
		if (str[i] == _str.str[0]) {
			start = i;
			for (int j = 0; j < _str.Length(); j++) {
				if (str[i + j] == _str.str[j]) {
					temp[j] = _str.str[j];
				}
			}
			for (int k = 0; k < _str.Length(); k++) {
				if (temp[k] != _str.str[k]) {
					return -1;
				}
			}
			return start;
		}
	}
	return -1;
}

String& String::Replace(const String& _find, const String& _replace) {
	int start;
	int len;
	int len2;
	int len3;
	start = Find(_find.str);
	len = _find.Length();
	len2 = _replace.Length();
	len3 = Length();
	if (start != -1) {
		for (int j = start + len; j < len3; j++) {
			temp[j] = str[j]; // goes through the string from the start index + the length of the find string and sets temp to the values in str
		}
		for (int i = start; i < start + len2; i++) {
			str[i] = _replace.str[i - start]; // replaces the find string with the replace string
		}
		for (int k = start + len2; k < (len3 - len + len2); k++) {
			str[k] = temp[k - len2 + len]; // adds the values after the find string back into str after the replace string
			str[k + 1] = '\0';
		}
	}
	return *this;
}

String& String::ReadFromConsole() {
	cin >> temp; // gets input from user
	str = temp; // sets str to temp
	return *this;
}

String& String::WriteToConsole() {
	cout << str << endl; // outputs str
	return *this;
}

bool String::operator == (const String& _other) {
	int len = Length();
	int len2 = _other.Length();
	if (len == len2) { // checks if the lengths are equal, if not then false
		for (int i = 0; i < len; i++) {
			if (str[i] != _other.str[i]) { // checks if any value is different between the strings, if so, then false
				return false;
			}
		}
		return true; // returns true only in the instance that the strings are the same length, and all values are equivalent
	}
	return false;
}

bool String::operator != (const String& _other) {
	int len = Length();
	int len2 = _other.Length();
	if (len == len2) { // checks if the lengths are equal, if not then true
		for (int i = 0; i < len; i++) {
			if (str[i] != _other.str[i]) { // checks if any value is different between the strings, if so, then true
				return true;
			}
		}
		return false; // returns false only in the instance that the strings are the same length, and all values are equivalent
	}
	return true;
}

String& String::operator = (const String& _str) {
	str = _str.str; // sets str to the passed string
	return *this;
}

char& String::operator [] (size_t _index) {
	at_index[0] = str[_index]; // sets the char to the value at index in str
	at_index[1] = '\0'; // ends the string with null terminator after the character
	return *at_index;
}

const char& String::operator [] (size_t _index) const {
	at_index[0] = str[_index]; // sets the char to the value at index in str
	at_index[1] = '\0'; // ends the string with null terminator after the character
	return *at_index;
}

bool String::operator < (const String& _other) {
	int len = Length();
	int len2 = _other.Length();
	for (int i = 0; i < len; i++) {
		if (str[i] < _other.str[i]) { // checks if the value in str[i] is less than the value in the other string at index i
			return true;
		}
		if (str[i] > _other.str[i]) {
			return false;
		}
	}
	return false;
}

bool String::operator > (const String& _other) {
	int len = Length();
	int len2 = _other.Length();
	for (int i = 0; i < len; i++) {
		if (str[i] > _other.str[i]) { // checks if the value in str[i] is greater than the value in the other string at index i
			return true;
		}
		if (str[i] < _other.str[i]) {
			return false;
		}
	}
	return false;
}