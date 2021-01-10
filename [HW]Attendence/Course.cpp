#include <iostream>
#include <string>
#include "Course.h"
#include "Date.h"
#include "AttendanceRecord.h"

using std::string, std::ostream, std::endl, std::cout;
Course::Course(string id, string title, Date startTime, Date endTime): id(id), title(title), startTime(startTime), endTime(endTime){}
string Course::getID() const
{
    return id;
}
string Course::getTitle() const
{
    return title;
}
Date Course::getStartTime() const
{
    return startTime;
}
Date Course::getEndTime() const
{
    return endTime;
}
void Course::addAttendanceRecord(AttendanceRecord ar)
{
    if(!(ar.getDate() >= startTime && ar.getDate() < endTime))
    {
        throw std::invalid_argument("Time is invalid");
    }
    else
    {
        attendanceRecords.push_back(ar);
    }
    
}
void Course::outputAttendance(std::ostream& os) const
{
    if(attendanceRecords.size() == 0)
    {
        os << "No records" << endl;
    }
    for(size_t i = 0; i < attendanceRecords.size(); ++i)
    {
        Date date = attendanceRecords[i].getDate();
        os << date.getDateTime() << "," << attendanceRecords[i].getCourseID() << ","<< attendanceRecords[i].getStudentID() << endl;
    }
}
void Course::outputAttendance(std::ostream& os, std::string student_id) const
{
    if(attendanceRecords.size() == 0)
    {
        os << "No records" << endl;
        return;
    }
    bool hasEntry = false;
    for(size_t i = 0; i < attendanceRecords.size(); ++i)
    {
        if(attendanceRecords[i].getStudentID() == student_id)
        {
            Date date = attendanceRecords[i].getDate();
            os << date.getStudentDateTime() << "," << id <<"," << student_id << endl;
            hasEntry = true;
        }
    }
    if(!hasEntry)
    {
        os << "No records" << endl;
    }
}
