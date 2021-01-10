#include <string>
#include <iostream>
#include "AttendanceRecord.h"
#include "Date.h"

using std::cout, std::string;
AttendanceRecord::AttendanceRecord(string course_id, string student_id, Date time) : course_id(course_id), student_id(student_id), time(time){}
string AttendanceRecord::getCourseID() const
{
    return course_id;
}
string AttendanceRecord::getStudentID() const
{
    return student_id;
}
Date AttendanceRecord::getDate() const
{
    return time;
}
