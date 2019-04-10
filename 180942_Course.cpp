#include "180942_Student.h"
#include "180942_Course.h"
#include <iostream>

using namespace std;

ostream& operator<<(ostream& out, const Course& c1)
{
	out<<"Course Name: "<<c1.course_name<<endl;
	out<<"Course ID: "<<c1.course_number<<endl;
	out<<"Students taking this course: "<<endl;
	for (int i=0; i<c1.noOfStudents;i++)
	{
		out<<c1.Slist[i]->getName()<<"  ";
	}
	out<<endl;
	return out;

}
Course::Course(string n,string i)
{
	course_name=n;
	course_number=i;
	noOfStudents=0;
	maxStudents=4;
	Slist=new Student*[maxStudents];
}

Course::~Course()
{
	for(int i=0; i<maxStudents;i++)
		delete Slist[i];
	delete[] Slist;
}

void Course::addStudent(Student *s)
{
	if(noOfStudents<maxStudents && noOfStudents>=0)
	{
		bool flag=false;
		for(int i=0;i<noOfStudents;i++)
		{
			if(Slist[i]==s)
				flag=true;
		}
		if(flag==false)
		{
			Slist[noOfStudents++]=s;
		}
		else
			cout<<"This student is already added"<<endl;
	}
	else
	{
		cout<<"4 students have already been added"<<endl;
	}

}

string Course::getCourseName()
{
	return course_name;
}

void Course::dropStudent(Student *s)
{
	if(noOfStudents>0)
	{
		bool flag=false;
		for(int i=0;i<noOfStudents;i++)
		{
			if(Slist[i]==s)
			{
				flag=true;
				if(i!=3)
				{
					for(int j=i;j<noOfStudents-1;j++)
					{
						Slist[j]=Slist[j+1];
					}
					Slist[3]=nullptr;
					noOfStudents--;
					break;
				}
				else
				{
					Slist[3]=nullptr;
					noOfStudents--;
					break;
				}
			}
		}
		if(!flag)
		{
			cout<<"Student not found"<<endl;
		}

	}
	else
	{
		cout<<"No students are registered"<<endl;
	}
}

void Course::addStudent2(Student *s)
{
	if(noOfStudents<maxStudents)
	{
		bool flag=false;
		for(int i=0;i<noOfStudents;i++)
		{
			if(Slist[i]==s)
			{
				flag=true;
				cout<<"This student is already added"<<endl;
				break;
			}
		}
		if(flag==false)
		{
			Slist[noOfStudents++]=s;
			s->addCoursedummy(this);
		}
	}
	else
	{
		cout<<"4 students have already been added"<<endl;
	}
}