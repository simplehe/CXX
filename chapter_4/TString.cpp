//
// Created by simplehe on 2018/9/6.
//

#include "TString.h"

TString::TString() {
    _rp = new StringRep;
    _rp->_refCount = 1;
    _rp->_length = 0;
    _rp->_str = 0;
}

TString::TString(const char *s) {
    _rp = new StringRep;
    _rp->_refCount = 1;
    _rp->_length = strlen(s);
    _rp->_str = new char[_rp->_length + 1];
    strcpy(_rp->_str, s);
}

TString::TString(char aChar) {
    _rp = new StringRep;
    _rp->_length = 1;
    _rp->_str = new char[2];
    _rp->_str[0] = aChar;
    _rp->_str[1] = 0;
    _rp->_refCount = 1;
}

TString::TString(const TString &arg) {
    arg._rp->_refCount++;
    this->_rp = arg._rp;
}

TString::~TString() {
    if (--_rp->_refCount == 0) {
        delete[]_rp->_str;
        delete _rp;
    }
}

TString &TString::operator=(const TString &arg) {
    if (this == &arg)return *this;
    arg._rp->_refCount++;
    //递减和测试，是否仍然再使用
    if (--this->_rp->_refCount == 0) {
        delete[] this->_rp->_str;
        delete[] this->_rp;
    }
    this->_rp = arg._rp;
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
    char *p;
    if (_rp->_refCount > 1) {
        unsigned len = this->_rp->_length;
        p = new char[len + 1];
        strcpy(p, this->_rp->_str);
        this->_rp->_refCount--;
        this->_rp = new StringRep;
        this->_rp->_refCount = 1;
        this->_rp->_length = len;
        this->_rp->_str = p;
    }

    if (p != 0) {
        while (*p) {
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





