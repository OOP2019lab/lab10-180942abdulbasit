#include "180942_Student.h"
#include "180942_Course.h"
#include <iostream>

using namespace std;

Student::Student(string u,string n, string r):username(u),name(n),roll_number(r)   //overloaded constructor which takes name and roll number
{
maxCourses=2;
noOfCourses=0;
Clist=new Course*[maxCourses];
}

Student::~Student()
{
	for(int i=0; i<maxCourses;i++)
		delete Clist[i];
	delete[] Clist;
}

void Student::addCourse(Course *c) //to add courses in student
{
	if(noOfCourses<maxCourses && noOfCourses>=0)
	{
		bool flag=false;
		for(int i=0;i<noOfCourses;i++)
		{
			if(Clist[i]==c)
				flag=true;
		}
		if(flag==false)
		{
			Clist[noOfCourses++]=c;
			c->addStudent(this);
		}
		else
			cout<<"This course is already added"<<endl;
	}
	else
	{
		cout<<"2 courses have already been added"<<endl;
	}

}

ostream& operator<<(ostream& out, const Student& s1)
{
	out<<"Username: "<<s1.username<<endl;
	out<<"Name: "<<s1.name<<endl;
	out<<"Roll number: "<<s1.roll_number<<endl;
	for (int i=0; i<s1.noOfCourses;i++)
	{
		out<<s1.Clist[i]->getCourseName()<<"  ";
	}
	out<<endl;
	return out;

}
string Student::getName()
{
	return name;
}

void Student::dropCourse(Course *c)
{
	bool flag=false;
	if(noOfCourses>0)
	{
		for(int i=0; i<noOfCourses;i++)
		{
			if(Clist[i]==c)
			{
				flag=true;
				if(i==0)
				{
					Clist[i]=Clist[i+1];
					Clist[i+1]=nullptr;
					noOfCourses--;
					break;
				}
				else
				{
					Clist[i]=nullptr;
					noOfCourses--;
					break;
				}
			}
		}
		if(!flag)
		{
			cout<<"Course not found"<<endl;
			return;
		}
	}
	else
	{
		cout<<"Student has not opted any course"<<endl;
	}
}

void Student::addCourse2(Course *c)
{
	if(noOfCourses<maxCourses && noOfCourses>=0)
	{
		bool flag=false;
		for(int i=0;i<noOfCourses;i++)
		{
			if(Clist[i]==c)
				flag=true;
		}
		if(flag==false)
		{
			Clist[noOfCourses++]=c;
			c->addStudent(this);
		}
		else
			cout<<"This course is already added"<<endl;
	}
	else
	{
		cout<<"2 courses have already been added"<<endl;
	}

}

void Student::addCoursedummy(Course *c) //it will be call by addStudent2(task 2) and it will not call any other function again
{
	if(noOfCourses<maxCourses && noOfCourses>=0)
	{
		bool flag=false;
		for(int i=0;i<noOfCourses;i++)
		{
			if(Clist[i]==c)
				flag=true;
		}
		if(flag==false)
		{
			Clist[noOfCourses++]=c;
		}
		else
			cout<<"This course is already added"<<endl;
	}
	else
	{
		cout<<"2 courses have already been added"<<endl;
	}
}