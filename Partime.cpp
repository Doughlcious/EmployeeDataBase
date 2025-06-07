#include <iostream>
#include <string>
#include "Partime.h"
using namespace std;

// argument constructor
Partime::Partime(string last, string first, string id, double rate, int hrs){
	lastName = last;
	firstName = first;
	nameID = id;
	setHourlyRate(rate);
	setHours(hrs);
}

// setter
void Partime::setHours(int hrs){
	weekHours = hrs;
}
// getter
int Partime::getHours() const{
	return weekHours;
}
// virtual function
double Partime::monthlyEarning(){
	return (getHours()*4)*getHourlyRate();
}
// virtual function
void Partime::putData(){
	cout << "Employee ID: " << nameID << endl;
	cout << "Employee Name: " << firstName << " " << lastName << endl;	cout << "Hours worked per month: " << getHours()*4 << endl;
	cout << "Monthly Salary: $" << monthlyEarning() << endl;
	cout << endl;
}
