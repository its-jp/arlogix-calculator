#include "string.hpp"
#include "lexer/token.hpp"
#include <stdio.h>
#include <iostream>
String::String() : _size(0), data(NULL) {}

String::String(const char* str) : _size(0), data(NULL) {
    for(int i = 0; str[i] != '\0'; i++){
        this->_size++;
    }
    this->data = new char[_size + 1];
    for(int i = 0; i < _size; i++){
        this->data[i] = str[i];
    }
    this->data[_size] = '\0';
    
}
String::String(const String& outra) {
    _size = outra._size;
    data = new char[_size+1];
    for (unsigned int i = 0; i < _size; i++) {
        data[i] = outra.data[i];
    }
    data[_size] = '\0';
}

String& String::operator+(const String& outra){
    char* nova = new char[_size + outra._size + 1];
    for (unsigned int i = 0; i < _size; i++) {
        nova[i] = data[i];
    }
    for (unsigned int j = 0; j < outra._size; j++) {
        nova[_size + j] = outra.data[j];
    }
    nova[_size + outra._size] = '\0';
    data = nova;
    _size = _size + outra._size;
    return *this;
}

String& String::operator=(String& outro) { 
    if (this != &outro) {
        delete[] data; 
        _size = outro._size;
        data = new char[_size + 1];
        for (unsigned int i = 0; i < _size; i++) {
            data[i] = outro.data[i];
        }
        data[_size] = '\0';
    }
    return *this; 
}
String& String::operator=(const char* other){
    delete[] data;
    int len = 0;
    while(other[len] != '\0'){
        len++;
    }
    _size = len;
    data = new char[_size + 1];
    for(unsigned int i = 0; i < _size; i++){
        data[i] = other[i];
    }
    data[_size] = '\0';
    return *this;
    
}
String& String::operator+=(const String& outra) { 
    return *this = *this + outra;
}

String& String::operator+=(const char& outra) { 
    char str[2] = {outra, '\0'};
    return *this = *this + String(str);
}

char String::operator[](unsigned int i) const { return data[i]; }
bool String::operator==(const String& outro) const {
    if (_size != outro._size) return false;
    for(unsigned int i = 0; i < _size; i++){
        if(data[i] != outro.data[i]) return false;
    }
    return true;
}

String::~String() { 
    delete[] data;
}

std::ostream& operator<< ( std::ostream& os, const String& c ){
    os << c.data;
    return os;
}

void String::clear(){
    for(unsigned int i = 0; i < _size; i++){
        data[i] = '\0';
    }
    _size = 0;
}

String String::to_string(int value){
    char buffer[32];
    snprintf(buffer, sizeof(buffer), "%d", value);
    return String(buffer);
}

String String::to_string(float value){
  char buffer[32];
  snprintf(buffer, sizeof(buffer), "%f", value);
  return String(buffer);
}

String String::to_string(double value){
  char buffer[64];
  snprintf(buffer, sizeof(buffer), "%f", value);
  return String(buffer);
}

String String::to_string(char value){
  char buffer[2];
  snprintf(buffer, sizeof(buffer), "%c", value);
  return String(buffer);
}

String String::to_string(Token value){
  if(value.type == NUMBER) return String::to_string(value.number);
  else return value.str;
}

void String::pop_back(){
    if(_size == 0) return;
    char* nova = new char[_size];

    for(unsigned int i = 0; i < _size - 1; i++){
        nova[i] = data[i];
    }
    
    nova[_size - 1] = '\0';
    delete[] data;
    data = nova;
    _size--;
}

bool String::empty() const { return _size == 0; }
unsigned int String::size() const { return _size;}
unsigned int String::length() const { return _size;}
char* String::c_str() const { return data; }
