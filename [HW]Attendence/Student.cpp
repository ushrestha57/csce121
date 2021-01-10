#include <iostream>
#include <vector>
#include <string>
#include "Student.h"

using std::cout, std::endl, std::string, std::vector, std::invalid_argument;
Student::Student(std::string student_id, std::string name) : id(student_id), name(name){}
string Student::get_id() const
{
    return id;
}
string Student::get_name() const
{
    return name;
}
void Student::addCourse(std::string course_id)
{
    for(size_t i = 0; i < course_ids.size(); ++i)
    {
        if(course_id == course_ids[i])
        {
            throw invalid_argument("Student already has this course");
        }
    }
    course_ids.push_back(course_id);
}
void Student::listCourses(std::ostream& os) const
{
    os << "Courses for " << id << endl;
    if(course_ids.size() > 0)
    {
        for(size_t i = 0; i < course_ids.size(); ++i)
        {
            os << course_ids[i] << endl;
        }
    }
    else
    {
        os << "No courses" << endl;
    }
}
