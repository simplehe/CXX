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
public:
    TStudent(const char theName[], unsigned long theSSn, const char theBirthDate, const char theAddress[],
             EStudentStatus theStatus, EDepartment theDepartment);

    TStudent(const TStudent &source);

    TStudent &operator=(const TStudent &source);

    ~TStudent();

    void SetName(const char theName[]);

    TString GetName() const;

    void SetAddress(const char theAddress[]);

    void SetAddress(const TString &newAddress);

    TString GetAddress() const;

    void SetDepartment(EDepartment dept);

    EDepartment GetDepartment() const;


    bool EnrollForCourse(const TCourse &aCourse);

    bool DropFromCourse(const TCourse &theCourse);

    void ListCourseRegisteredFor() const;

    void SetStudentIdentification(unsigned long newId);

    unsigned long GetStudentIdentification() const;

    void Print() const;

private:
    TString        _name;
    TStudent       _address;
    unsigned long  _ssn;
    const TDate    _birthDate;
    EStudentStatus _status;
    EDepartment    _department;
    TCourse        *_enrooled[MAX_COURSES_FOR_STUDENT];
    int            _numCourses;


};


#endif //CHAPTER_5_TSTUDENT_H
