//
// Created by simplehe on 2018/8/29.
//
#include "TIntStack.h"
#include <iostream>
using namespace std;

TIntStack::TIntStack(unsigned int stackSize) {
    if (stackSize > 0) {
        _size = stackSize;
        _sp = new int[_size];
        for (int i = 0; i < _size; ++i) {
            _sp[i] = 0;
        }
    } else {
        _sp = 0;
        _size = 0;
    }
    _count = 0;
}

TIntStack::TIntStack(const TIntStack &that) {
    _size = that._size;
    if (_size > 0) {
        _sp = new int[_size];
        _count = that._count;
        for (int i = 0; i < _size; ++i) {
            _sp[i] = that._sp[i];
        }
    } else {
        _size = 0;
        _count = 0;
    }
}

TIntStack::~TIntStack() {
    std::cout << "Executing the destructor for IntStack\n";
    delete[] _sp;
}

TIntStack &TIntStack::operator=(const TIntStack &assign) {
    if (this == &assign) { ;
        return *this;
    }
    if (assign._count > this->_count) {
        delete[] _sp;
        this->_size = assign._size;
        _sp = new int[this->_size];
    }
    for (int i = 0; i < assign._count; ++i) {
        this->_sp[i] = assign._sp[i];
    }
    this->_count = assign._count;
    return *this;
}

void TIntStack::Push(int thisValue) {
    if (_count < _size) {
        _sp[_count++] = thisValue;
    } else {
        std::cout << "stack is full. cannot push value" << thisValue << std::endl;
    }
}

int TIntStack::Pop() {
    if (_count <= 0) {
        std::cout << "Stack is EMPTY\n";
        exit(1);
    }
    _count--;
    return _sp[_count];
}

unsigned int TIntStack::HowMany() const {
    return _count;
}





