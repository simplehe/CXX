//
// Created by simplehe on 2018/9/6.
//

#ifndef CHAPTER_4_TSEMAPHORE_H
#define CHAPTER_4_TSEMAPHORE_H


class TSemaphore {
public:
    TSemaphore();

    bool Acquire();

    void Release();

    unsigned GetWaiters() const;

private:
    //TSemaphore对象不能赋值或赋值
    TSemaphore(const TSemaphore &other);

    TSemaphore &operator=(const TSemaphore &other);

};


class TAutoSemaphore {
public:
    TAutoSemaphore(TSemaphore &sem) : _semaphore(sem) {
        _semaphore.Acquire();
    }

    ~TAutoSemaphore() { _semaphore.Release(); }

private:
    TSemaphore &_semaphore;
};


class X {
public:
    void f();

private:
    TSemaphore _sem;
};

void X::f() {
    TAutoSemaphore autosem(_sem);
}

#endif //CHAPTER_4_TSEMAPHORE_H
