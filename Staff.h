#ifndef STAFF_H
#define STAFF_H
#include <iostream>
#include <string>
#include "Employee.h"
using namespace std;

class Staff : public Employee {
	protected:
		double hourlyRate;
	public:
		// constructors
		Staff() : hourlyRate(0) {};
		Staff(string last, string first, string id, double rate);
		// data members
		void setHourlyRate(double rate);
		double getHourlyRate() const;
		// virtual functions
		double monthlyEarning();
		void putData();
};

#endif
