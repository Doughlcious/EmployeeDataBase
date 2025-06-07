#ifndef PARTIME_H
#define PARTIME_H
#include <iostream>
#include <string>
#include "Employee.h"
#include "Staff.h"
using namespace std;

class Partime : public Staff {
	private:
		int weekHours;
	public:
		// constructors
		Partime() : weekHours(0) {};
		Partime(string last, string first, string id, double rate, int hrs);
		// data functions
		void setHours(int hrs);
		int getHours() const;
		// virtual functions
		double monthlyEarning();
		void putData();
};

#endif
