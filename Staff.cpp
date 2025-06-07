#include <iostream>
#include <string>
#include "Staff.h"
using namespace std;

// argument constructor
Staff::Staff(string last, string first, string id, double rate){
	lastName = last;
	firstName = first;
	nameID = id;
	setHourlyRate(rate);
}

// setter
void Staff::setHourlyRate(double rate){
	hourlyRate = rate;
}
// getter
double Staff::getHourlyRate() const{
	return hourlyRate;
}
// vritual function
double Staff::monthlyEarning(){
	return getHourlyRate()*STAFF_MONTHLY_HOURS_WORKED;
}
// virtual function
void Staff::putData(){
	cout << "Employee ID: " << nameID << endl;
	cout << "Employee Name: " << firstName << " " << lastName << endl;
	cout << "Full time" << endl;
	cout << "Monthly Salary: $" << monthlyEarning() << endl;
	cout << endl;
}
