//
// Created by simplehe on 2018/8/29.
//
#include "TIntStack.h"
#include <iostream>

TIntStack::TIntStack(unsigned int stackSize) {
    if (stackSize > 0) {
        _size = stackSize;
        _sp   = new int[_size];
        for (int i = 0; i < _size; ++i) {
            _sp[i] = 0;
        }
    } else {
        _sp   = 0;
        _size = 0;
    }
    _count = 0;
}

TIntStack::TIntStack(const TIntStack &that) {

    _size = that._size;
    if (_size > 0) {
        _sp    = new int[_size];
        _count = that._count;
        for (int i = 0; i < _size; ++i) {
            _sp[i] = that._sp[i];
        }
    } else {
        _size  = 0;
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
        
    }

    return <#initializer#>;
}

