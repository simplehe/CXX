//
// Created by simplehe on 2018/8/29.
//

#ifndef STUDY_TINTSTACK_H
#define STUDY_TINTSTACK_H
#define DEFAULT_SIZE 100

class TIntStack {
public:
    TIntStack(unsigned int stackSize = DEFAULT_SIZE);

    TIntStack(const TIntStack &that);

    TIntStack &operator=(const TIntStack &assign);

    ~TIntStack();

    void Push(int thisValue);

    int Pop();

    unsigned int HowMany() const;

private:
    int      *_sp;
    unsigned _count;
    unsigned _size;
};

#endif //STUDY_TINTSTACK_H
