#include <string>

using namespace std;

class Course;

#ifndef STUDENT_H
#define STUDENT_H

class Student
{
private:
	string username;
	string name;
	string roll_number;
	Course **Clist;
	int noOfCourses;
	int maxCourses;
protected:
	void Student::addCoursedummy(Course *c);

public:
	Student::Student(string,string,string);
	Student::~Student();
	void Student::addCourse(Course *c);
	void Student::dropCourse(Course *c);
	void Student::addCourse2(Course *c);
	string Student::getName();

	friend ostream& operator<<(ostream& out, const Student& s1);
	friend class Course;
};

#endif