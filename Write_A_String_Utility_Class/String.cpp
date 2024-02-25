#include "String.h"
#include <cstring>
#include <iostream>
#include <vector>
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
	str = nullptr;
}

size_t String::Length() const {
	int len = 0;
	for (int i = 0; i = strlen(str); i++) {
		if (str[i] != '\0') {
			len += 1;
		}
	}
	return len;
}

char& String::CharacterAt(size_t _index) {
	if ((_index < 0) || (_index > Length())) {
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
	len = this->Length();
	for (int i = 0; i < _str.Length(); i++) {
		this->str[i + len] = _str.str[i];
	}
	return *this;
}

String& String::Prepend(const String& _str) {
	vector<char> temp;
	for (int i = 0; i < this->Length(); i++) {
		temp[i + _str.Length()] = str[i];
	}
	for (int j = 0; j < (this->Length() + _str.Length()); j++) {
		if (j < _str.Length()) {
			str[j] = _str.str[j];
		}
		else if (j >= _str.Length()) {
			str[j] = temp[j];
		}
	}
	return *this;
}

const char* String::CStr() const {
	const char* c_str = str;
	return c_str;
}

String& String::ToLower() {
	for (int i = 0; i < Length(); i++) {
		if (65 <= str[i] <= 90) {
			str[i] += 32;
		}
	}
	return *this;
}

String& String::ToUpper() {
	for (int i = 0; i < Length(); i++) {
		if (97 <= str[i] <= 122) {
			str[i] -= 32;
		}
	}
	return *this;
}

size_t String::Find(const String& _str) {
	char* temp = fix_temp;
	int start = 0;
	for (int i = 0; i < Length(); i++) {
		if (str[i] == _str.str[0]) {
			start = i;
			for (int j = 0; j < _str.Length(); j++) {
				if (str[i + j] == _str.str[j]) {
					temp[j] = _str.str[j];
				}
			}
			if (temp == _str.str) {
				return start;
			}
		}
	}
	return -1;
}

size_t String::Find(size_t _startIndex, const String& _str) {
	char* temp = fix_temp;
	int start = 0;
	for (int i = _startIndex; i < Length(); i++) {
		if (str[i] == _str.str[0]) {
			start = i;
			for (int j = 0; j < _str.Length(); j++) {
				if (str[i + j] == _str.str[j]) {
					temp[j] = _str.str[j];
				}
			}
			if (temp == _str.str) {
				return start;
			}
		}
	}
	return -1;
}

String& String::Replace(const String& _find, const String& _replace) {
	int start;
	int len;
	int len2;
	char* temp = fix_temp;
	start = Find(_find.str);
	len = _find.Length();
	len2 = _replace.Length();
	if (start != -1) {
		for (int j = start + len; j < Length(); j++) {
			temp[j] = str[j];
		}
		for (int i = start; i < _replace.Length(); i++) {
			str[i] = _replace.str[i];
		}
		for (int k = start + len2; k < (Length() - _find.Length() + _replace.Length()); k++) {
			str[k] = temp[k - len2 + len];
		}
	}
	return *this;
}

String& String::ReadFromConsole() {
	char* temp = fix_temp;
	cin >> temp;
	str = temp;
	return *this;
}

String& String::WriteToConsole() {
	cout << str << endl;
	return *this;
}

bool String::operator == (const String& _other) {
	int len = Length();
	int len2 = _other.Length();
	if (len == len2) {
		for (int i = 0; i < len; i++) {
			if (str[i] != _other.str[i]) {
				return false;
			}
		}
	}
	return true;
}

bool String::operator != (const String& _other) {
	int len = Length();
	int len2 = _other.Length();
	if (len == len2) {
		for (int i = 0; i < len; i++) {
			if (str[i] != _other.str[i]) {
				return true;
			}
		}
	}
	return false;
}

String& String::operator = (const String& _str) {
	str = _str.str;
	return *this;
}

char& String::operator [] (size_t _index) {
	char* at_index = fix_temp;
	at_index[0] = str[_index];
	at_index[1] = '\0';
	return *at_index;
}

const char& String::operator [] (size_t _index) const {
	char* at_index = fix_temp;
	at_index[0] = str[_index];
	at_index[1] = '\0';
	return *at_index;
}

bool String::operator < (const String& _other) {
	int len = Length();
	int len2 = _other.Length();
	for (int i = 0; i < len; i++) {
		if (str[i] < _other.str[i]) {
			return true;
		}
	}
	return false;
}

bool String::operator > (const String& _other) {
	int len = Length();
	int len2 = _other.Length();
	for (int i = 0; i < len; i++) {
		if (str[i] > _other.str[i]) {
			return true;
		}
	}
	return false;
}