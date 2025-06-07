#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>
#include <string>
using namespace std;

// constants
const double FACULTY_MONTHLY_SALARY = 5000.00;
const int STAFF_MONTHLY_HOURS_WORKED = 160;

class Employee {
	protected:
		string lastName;
		string firstName;
		string nameID;
	public:
		// constructors
		Employee();
		Employee(string last, string first, string id);
		// setters
		void setLastName(string last){lastName=last;};
		void setFirstName(string first){firstName=first;};
		void setNameID(string id){nameID=id;};
		// getters
		string getLastName(){return lastName;};
		string getFirstName(){return firstName;};
		string getNameID(){return nameID;};
		// virtual functions
		virtual double monthlyEarning();
		virtual void putData();
};

#endif
