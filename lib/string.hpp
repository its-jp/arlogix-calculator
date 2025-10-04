#pragma once

#include "stdlib.h"
#include <ostream>

class String {
    private:
        char* data;
        unsigned int _size;
    public:
        String();
        String(const char* str);
        String(const String&);
        ~String();
        String& operator=(String&);
        String& operator+=(const String&);
        String& operator+=(const char& outra);
        String& operator+(const String&);
        bool operator==(const String&) const;
        char operator[](unsigned int) const;
        friend std::ostream& operator<< ( std::ostream& os, const String& c );

        void clear();
        bool empty() const;
        unsigned int size() const;
        unsigned int length() const;
        char* c_str() const;
};
