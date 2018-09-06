//
// Created by simplehe on 2018/8/30.
//

#ifndef CHAPTER_3_TPERSON_H
#define CHAPTER_3_TPERSON_H

class TPerson {
public:
    TPerson(const char theName, const char theAddress[] = 0);

    const char *GetName() const;

private:
    char *_name;
    char *_address;
};

class TlistNode;

class TListIterator;

class TList {
public:
    TList();

    unsigned HowMany() const;

private:
    TlistNode *_head;
    TlistNode *_previous;

    friend class TListIterator;
};

class TStopWatch {
public:
    TStopWatch();

private:
    static long &_systemClock;
};

#endif //CHAPTER_3_TPERSON_H
