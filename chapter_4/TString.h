//
// Created by simplehe on 2018/9/6.
//

#ifndef CHAPTER_4_TSTRING_H
#define CHAPTER_4_TSTRING_H

#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
/*
 * 写时复制：
 * 1.共享资源不应该导致太多额外的成本
 * 2.应该清楚地并控制所有可以修改资源的途径
 * 3.设计的实现必须在任何情况下都能追踪共享资源的对象数目
 * */
class TString {
public:
    TString();

    TString(const char *s);

    TString(char aChar);

    TString(const TString &arg);

    ~TString();

    TString &operator=(const TString &arg);

    TString &operator=(const char *s);

    TString &operator=(char s);

    int Size() const;

    TString operator()(unsigned posn, unsigned len) const;

    char operator()(unsigned n) const;

    const char &operator[](unsigned n) const;

    const char *c_str() const { return _str; }

    TString &operator+=(const TString &other);

    TString &ToLower();

    TString &ToUpper();

private:
    unsigned _length;
    char     *_str;
};

TString operator+(const TString &one, const TString &two);

std::ostream &operator<<(std::ostream &o, const TString &s);

std::istream &operator>>(std::istream &stream, TString &s);

bool operator==(const TString &first, const TString &second);

bool operator!=(const TString &first, const TString &second);

bool operator>(const TString &first, const TString &second);

bool operator<(const TString &first, const TString &second);

bool operator>=(const TString &first, const TString &second);

bool operator<=(const TString &first, const TString &second);

#endif //CHAPTER_4_TSTRING_H
