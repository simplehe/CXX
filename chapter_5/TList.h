//
// Created by simplehe on 2018/10/4.
//

#ifndef CHAPTER_5_TLIST_H
#define CHAPTER_5_TLIST_H

class TListNode;

class TList {
public:
    TList(void *storeThistElement);

    TList(const TList &copy);

    TList &operator=(const TList &assign);

    virtual  ~TList();

    virtual bool Append(void *newElementToAdd);

    virtual void *Remove(void *_elementToRemove);

private:


};

#endif //CHAPTER_5_TLIST_H
