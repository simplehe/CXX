//
// Created by simplehe on 2018/9/13.
//

#include "TStudent.h"

namespace {
    const char *departmentNames[] = {"Accounting", "Business", "Engineering", "Mathematics", "Physics", "Chemistry",
                                     "Arts", "Unknown"};
}

const char *statusLabels[] = {"full time ", "part time", "exchange", "unknown"};

TStudent::TStudent(const char *theName, unsigned long theSSn, const char theBirthDate, const char *theAddress,
                   EStudentStatus theStatus, EDepartment theDepartment) : _name(theName), _address(theAddress),
                                                                          _birthDate(theBirthDate), _ssn(theSSn),
                                                                          _status(theStatus),
                                                                          _department(theDepartment), _numCourses(0) {
    for (int i = 0; i < MAX_COURSES_FOR_STUDENT; ++i) {
        _enrooled[i] = 0;
    }
}

TStudent::TStudent(const TStudent &source) : _name(source._name), _address(source._address),
                                             _birthDate(source._birthDate), _ssn(source._ssn), _status(source._status),
                                             _department(source._department), _numCourses(source._numCourses) {
    for (int i = 0; i < MAX_COURSES_FOR_STUDENT; ++i) {
        if (source._enrooled[i] != 0) {
            this->_enrooled[i] = new TCourse(*(source._enrooled[i]));
        } else {
            this->_enrooled[i] = 0;
        }
    }
}

void TStudent::SetName(const char *theName) {
    _name = theName;
}

void TStudent::SetAddress(const char *theAddress) {
    _address = theAddress;

}

bool TStudent::EnrollForCourse(const TCourse &aCourse) {
    if (_numCourses >= MAX_COURSES_FOR_STUDENT)
        return false;

    for (int i = 0; i < MAX_COURSES_FOR_STUDENT; ++i) {
        if (_enrooled[i] == 0) {
            _enrooled[i] = new TCourse(aCourse);
            _numCourses++;
            return true;
        }
    }
    return false;
}

bool TStudent::DropFromCourse(const TCourse &theCourse) {
    for (int i = 0; i < MAX_COURSES_FOR_STUDENT; ++i) {
        if (_enrooled[i] != 0) {
            if (*_enrooled[i] == theCourse) {
                delete _enrooled[i];
                _enrooled[i] = 0;
                _numCourses--;
                return true;
            }
        }
    }

    return false;
}


void TStudent::Print() const {
    std::cout << "Name:" << _name << std::endl;
    std::cout << "Address: " << _address << std::endl;
    std::cout << "This persion is a " << statusLabels[int(_status)] << "student in the department of "
              << departmentNames[int(_department)] << std::endl;

}