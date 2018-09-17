//
// Created by simplehe on 2018/9/13.
//

#ifndef CHAPTER_5_TCOURSE_H
#define CHAPTER_5_TCOURSE_H
#include "../chapter_4/TString.h"
typedef long CourseId;

class TCourse {
public:
    TCourse(const char name[], long id);

    TCourse(const TCourse &other);

    TCourse &operator=(const TCourse &other);

    bool operator==(const TCourse &other);

    bool operator!=(const TCourse &other);

    TString GetCourserName() const;

    void SetCourseName(const char name[]);

    CourseId GetCourseId() const;

    void SetCourseId(CourseId newId);

private:
    TString _courseName;
    CourseId _courseId;
};

#endif //CHAPTER_5_TCOURSE_H
