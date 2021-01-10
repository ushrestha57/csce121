#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include "School.h"
#include "AttendanceRecord.h"
#include "Date.h"
using std::string, std::vector, std::ostream, std::ifstream, std::istringstream, std::stringstream, std::endl, std::cout, std::ifstream, std::invalid_argument;
void School::addCourses(std::string filename){
    ifstream ifs(filename);
    if(!ifs.is_open())
    {
        throw invalid_argument("Invalid filename");
    }
    while(!ifs.eof())
    {
        int startHour;
        int startMinute;
        int endHour;
        int endMinute;
        string course_id;
        string name;
        
        string line;
        getline(ifs,line);
        stringstream ss(line);
        string input;
        if(ss.fail())
        {
            break;
        }
        if(line == "")
        {
            break;
        }
        getline(ss,input,',');
        course_id = input;
        getline(ss,input,':');
        startHour = stoi(input);
        getline(ss,input,',');
        startMinute = stoi(input);
        getline(ss,input,':');
        endHour = stoi(input);
        getline(ss,input,',');
        endMinute = stoi(input);
        getline(ss,input);
        name = input;
        Date startTime(startHour,startMinute);
        Date endTime(endHour,endMinute);

        Course course(course_id,name,startTime,endTime);
        bool exists = false;
        for(size_t i = 0; i < courses.size(); ++i)
        {
            if(courses[i].getID() == course.getID())
            {
                exists = true;
                break;
            }
        }
        if(!exists)
        {
            courses.push_back(course);
        }


    }

    
}
void School::outputCourseAttendance(std::ostream& os, std::string course_id) const{
    bool found = false;
    for(size_t i = 0; i < courses.size(); ++i)
    {
        if(courses[i].getID() == course_id)
        {
            courses[i].outputAttendance(os);
            found = true;
        }
    }
    if(!found)
    {
        os << "No records" << endl;
    }



}
void School::outputStudentAttendance(ostream& os, string student_id, string course_id) const{
    for(size_t i = 0; i < courses.size(); ++i)
    {
        if(courses[i].getID() == course_id)
        {
            courses[i].outputAttendance(os,student_id);
        }
    }

}
unsigned int School::addAttendanceData(std::string filename)
{
    unsigned int numInvalid = 0;
    string data;
	ifstream ifs(filename);
	int year;
	int month;
	int day;
	int hour;
	int minute;
	int second;
	string course_id;
	string student_id;
	if(!ifs.is_open())
	{
		throw invalid_argument("Invalid file");
	}
    while(!ifs.eof())
    {
        string line;
        getline(ifs,line);
        stringstream ss(line);
        string input;
        if(ss.fail())
        {
            break;
        }
        if(line == "")
        {
            break;
        }
        getline(ss,input,'-');
        year = stoi(input);
        getline(ss,input,'-');
        month = stoi(input);
        getline(ss,input,' ');
        day = stoi(input);
        getline(ss,input,':');
        hour = stoi(input);
        getline(ss,input,':');
        minute = stoi(input);
        getline(ss,input,',');
        second = stoi(input);
        getline(ss,input,',');
        course_id = input;
        getline(ss,input);
        student_id = input;
        Date attendanceDate(year,month,day,hour,minute,second);
        if(!attendanceDate.isValid())
        {
            numInvalid++;
            continue;
        }
    	AttendanceRecord record = AttendanceRecord(course_id, student_id,attendanceDate);
        bool matchingCourse = false;
        bool matchingStudent = false;
        for(size_t i = 0; i < courses.size(); ++i)
        {
            if(courses[i].getID() == course_id)
            {
                matchingCourse = true;
                courses[i].addAttendanceRecord(record);
            }
        }
        for(size_t i = 0; i < students.size(); ++i)
        {
            if(students[i].get_id() == student_id)
            {
                matchingStudent = true;
            }
        }
        if(!(matchingStudent && matchingCourse))
        {
            numInvalid++;
            continue;
        }

	}
	 return numInvalid;
}
void School::listCourses(std::ostream& os) const
{
    if(courses.size() == 0)
    {
        os << "No courses" << endl;
    }
    else
    {
        for(size_t i = 0; i < courses.size(); ++i)
        {
            os << courses[i].getID() << "," << courses[i].getStartTime().getTime(false) << "," 
            << courses[i].getEndTime().getTime(false) << "," << courses[i].getTitle() << endl;
        }
    }
    
}
void School::listStudents(std::ostream& os) const{
    if(students.size() == 0)
    {
        os << "No students" << endl;
    }
    else
    {
        for(size_t i = 0; i < students.size(); ++i)
        {
            os << students[i].get_id() << "," <<  students[i].get_name() << endl;
        }
    }
}
bool School::isEnrolled(std::string student_id) const{
    for(size_t i  =0; i < students.size(); ++i)
    {
        if(student_id == students[i].get_id())
        {
            return true;
        }
    }
    return false;
}
// one method is provided to students; students implement all other methods
void School::addStudents(string filename) {
  ifstream ifs(filename);
  if (!ifs.is_open()) {
    throw std::invalid_argument("addStudents: can't open file");
  }
  while (!ifs.eof()) {
    string line;
    getline(ifs, line);
    istringstream ss(line);
    string uin;
    getline(ss, uin, ',');
    string name;
    getline(ss, name);
    if (!ss.fail()) {
        Student student(uin, name);
        bool exists = false;
        for (Student s : students) {
            if (s == student) {
                exists = true;
                break;
            }
        }
        if (!exists) {
            students.push_back(student);
        }
    }
  }
}
