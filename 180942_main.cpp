#include "180942_Student.h"
#include "180942_Course.h"
#include <iostream>

using namespace std;

void main()
{

	Student S1("S1","Anum","11-1351");
	Student S2("S2","Sara","12-6462");
	Student S3("S3","Sana","11-4531");
	Student S4("S4","Zara","12-4342");
	Student S5("S5","Hira","11-5940");
	Course C1("OOP","CS102");
	Course C2("PF","CS101");
	Course C3("AI","CS365");


	//////// TASK 1 /////////


	S1.addCourse(&C1);
	S1.addCourse(&C2);
	S1.addCourse(&C2);
	S1.addCourse(&C3);
	S2.addCourse(&C2);
	S3.addCourse(&C2);
	S4.addCourse(&C2);
	S5.addCourse(&C2);
	//C1.addStudent(&S5); //inaccessible
	cout<<S1<<endl;
	cout<<C2<<endl;
	cout<<C1<<endl;


	/////// TASK 2 /////////

	S5.addCourse2(&C1);
	C3.addStudent2(&S5);
	C1.addStudent2(&S5);
	cout<<S5<<endl;
	cout<<C1<<endl;
	cout<<C3<<endl;

	///////// TASK 3 ///////

	S5.dropCourse(&C1);
	S5.dropCourse(&C3);
	//C1.dropStudent(&S1); inaccessible


	system("PAUSE");
}