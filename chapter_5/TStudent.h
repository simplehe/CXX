//
// Created by simplehe on 2018/9/13.
//

#ifndef CHAPTER_5_TSTUDENT_H
#define CHAPTER_5_TSTUDENT_H

#include "TCourse.h"

enum EStudentStatus {
    eFullTime,
    ePartTime,
    eExchange
};

enum EDepartment {
    eAccounting,
    eBusiness,
    eEngineering,
    eMathematics,
    ePhysics,
    eChemistry,
    eArts,
    eUnknown
};

const short MAX_COURSES_FOR_STUDENT = 5;

class TStudent {
private:
    TString _name;
    TStudent _address;
    unsigned long _ssn;
    const TDate _birthDate;
    EStudentStatus _status;
    EDepartment _department;
    TCourse *_enrooled[MAX_COURSES_FOR_STUDENT];
    int _numCourses;


};


#endif //CHAPTER_5_TSTUDENT_H
