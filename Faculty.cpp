#include <iostream>
#include <string>
#include "Education.h"
#include "Faculty.h"
using namespace std;

// default constructor
Faculty::Faculty(){
	level = AS;
}

Faculty::Faculty(string last, string first, string id, string deg, string maj, int num, Level lvl){
	// Employee information
	lastName = last;
	firstName = first;
	nameID = id;
	// Education information
	object.setDegree(deg);
	object.setMajor(maj);
	object.setResearchNum(num);
	// level
	setLevel(lvl);
}

void Faculty::setLevel(Level lvl){
	level = lvl;
}

Level Faculty::getLevel() const{
	return level;
}

double Faculty::monthlyEarning(){
	switch(getLevel()){
		case AS:
			return FACULTY_MONTHLY_SALARY;
		case AO:
			return FACULTY_MONTHLY_SALARY*1.2;
		case FU:
			return FACULTY_MONTHLY_SALARY*1.4;
	}
}

void Faculty::putData(){
	cout << "Employee ID: " << nameID << endl;
	cout << "Employee Name: " << firstName << " " << lastName << endl;	string prof = (getLevel()==AS) ? "Assistant Professor" : (getLevel()==AO) ? "Associate Professor" : "Fulltime Professor";
	cout << prof << endl;
	cout << "Monthly Salary: $" << monthlyEarning() << endl;
	cout << endl;
}
