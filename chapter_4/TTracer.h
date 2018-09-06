//
// Created by simplehe on 2018/9/6.
//

#ifndef CHAPTER_4_TTRACER_H
#define CHAPTER_4_TTRACER_H

#include <iostream>


class TTracer {
public:
#ifdef DEBUG
    TTracer(const char message[]) : _msg(message) {
        std::cout << " >> enter " << _msg << std::endl;
    }
    ~TTracer(){std::cout<<" >> exit " << _msg <<std::endl;}

private:
    const char *_msg;
#else

    TTracer(const char message[]) {}

    ~TTracer() {}

#endif
};

#endif //CHAPTER_4_TTRACER_H
