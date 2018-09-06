//
// Created by simplehe on 2018/9/6.
//

#include "TString.h"

TString::TString() {
    _str    = 0;
    _length = 0;
}

TString::TString(const char *s) {
    if (s && *s) {
        _length = strlen(s);
        _str    = new char[_length + 1];
        strcpy(_str, s);
    } else {
        _str    = 0;
        _length = 0;
    }
}

TString::TString(char aChar) {
    if (aChar) {
        _str = new char[2];
        _str[0] = aChar;
        _str[1] = '\0';
        _length = 1;
    } else {
        _str    = 0;
        _length = 0;
    }
}

TString::TString(const TString &arg) {
    if (arg._str != 0) {
        this->_str = new char[strlen(arg._str) + 1];
        strcpy(this->_str, arg._str);
        _length = arg._length;
    } else {
        _str = 0, _length = 0;
    }
}

TString::~TString() {
    if (_str != 0) {
        delete[] _str;
        _length = 0;
    }
}

TString &TString::operator=(const TString &arg) {
    if (this == &arg)return *this;
    if (this->_length >= arg._length) {
        if (arg._str != 0) {
            strcpy(this->_str, arg._str);
        } else {
            this->_str = 0;
        }
        this->_length = arg._length;
        return *this;
    }
    delete[]_str;
    this->_length = arg.Size();
    if (_length) {
        _str = new char[_length + 1];
        strcpy(_str, arg._str);
    } else {
        _str = 0;
    }
    return *this;
}

TString &TString::operator=(const char *s) {
    if (s == 0 || *s == 0) {
        delete[] _str;
        _length = 0, _str = 0;
        return *this;
    }

    int slength = strlen(s);
    if (this->_length >= slength) {
        strcpy(this->_str, s);
        this->_length = slength;
        return *this;
    }
    delete[] _str;
    this->_length = slength;
    _str = new char[_length + 1];
    strcpy(_str, s);
    return *this;
}

TString &TString::operator=(char s) {
    char ss[2];
    ss[0] = s;
    ss[1] = '\0';
    return (*this = ss);
}

int TString::Size() const { return _length; }

TString &TString::operator+=(const TString &other) {
    if (other.Size()) {
        _length = other.Size() + this->Size();
        char *newstr = new char[_length + 1];
        if (this->Size()) {
            strcpy(newstr, _str);
        } else {
            *newstr = '\0';
        }
        strcat(newstr, other._str);
        delete[] _str;
        _str = newstr;
    }
    return *this;
}

char TString::operator()(unsigned n) const {
    if (n < this->Size())
        return this->_str[n];
    return 0;
}

const char &TString::operator[](unsigned n) const {
    if (n < this->Size())
        return this->_str[n];
    return _str[0];
}

TString &TString::ToLower() {
    if (_str && *_str) {
        char *p = _str;
        while (p) {
            *p = tolower(*p);
            ++p;
        }
    }
    return *this;
}

TString &TString::ToUpper() {
    if (_str && *_str) {
        char *p = _str;
        while (p) {
            *p = toupper(*p);
            ++p;
        }
    }
    return *this;
}

TString TString::operator()(unsigned posn, unsigned len) const {
    int sz = Size();
    if (posn > sz) return "";
    if (posn + len > sz)len = sz - posn;
    TString result;
    if (len) {
        result._str = new char[len + 1];
        strncpy(result._str, _str + posn, len);
        result._length = len;
        result._str[len] = '\0';
    }
    return result;
}


TString operator+(const TString &one, const TString &two) {
    TString result = one;
    result += two;
    return result;
}

bool operator==(const TString &first, const TString &second) {
    const char *fp = first.c_str();
    const char *sp = second.c_str();
    if (fp == 0 && sp == 0)return true;
    if (fp == 0 && sp) return false;
    if (fp && sp == 0)return false;
    return (strcmp(fp, sp) == 0);
}

bool operator!=(const TString &first, const TString &second) {
    const char *fp = first.c_str();
    const char *sp = second.c_str();
    if (fp == 0 && sp == 0)return false;
    if (fp == 0 && sp) return false;
    if (fp && sp == 0)return false;
    return (strcmp(fp, sp) != 0);
}

std::ostream &operator<<(std::ostream &o, const TString &s) {
    if (s.c_str())
        o << s.c_str();
    return o;
}

std::istream &operator>>(std::istream &stream, TString &s) {
    char c;
    s = "";
    while (stream.get(c) && isspace(c));//do nothing
    if (stream) {
        do {
            s += c;
        } while (stream.get(c) && !isspace(c));
        if (stream)//未读取额外字符
            stream.putback(c);
    }
    return stream;
}





