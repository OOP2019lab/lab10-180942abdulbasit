#include <string>
using namespace std;

class Student;

#ifndef COURSE_H
#define COURSE_H

class Course
{

private:
	string course_name;
	string course_number;
	Student **Slist;
	int noOfStudents;
	int maxStudents;

	void Course::addStudent(Student *s);
	void Course::dropStudent(Student *s);

public:
	Course::Course(string,string);
	Course::~Course();
	string Course::getCourseName();
	void Course::addStudent2(Student *s);

    friend ostream& operator<<(ostream& out, const Course& c1);
	friend class Student;
};

#endif
