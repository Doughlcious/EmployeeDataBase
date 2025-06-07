#include <iostream>
#include <string>
#include "Employee.h"
using namespace std;

Employee::Employee(){
	lastName = "Doe";
	firstName = "John";
	nameID = "ID";
}

Employee::Employee(string last, string first, string id){
	lastName = last;
	firstName = first;
	nameID = id;
}

double Employee::monthlyEarning(){
	return 0;
}

void Employee::putData(){
	cout << "Employee Name: " << firstName << " " << lastName << endl;	cout << "Employee ID: " << nameID << endl;
	cout << endl;
}

