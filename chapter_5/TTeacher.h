//
// Created by simplehe on 2018/9/24.
//

#ifndef CHAPTER_5_TTEACHER_H
#define CHAPTER_5_TTEACHER_H

class TPerson{

};


class TTeacher : public TPerson{
public:
    TTeacher(const char theName[], unsigned long theSSN, const char theBirthDate, const char theAddresss[], ERANK theRank, EDepartment theDepartMent);
    TTeacher(const TTeacher)

};

#endif //CHAPTER_5_TTEACHER_H
