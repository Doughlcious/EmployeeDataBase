#ifndef FACULTY_H
#define FACULTY_H
#include <iostream>
#include <string>
#include "Employee.h"
#include "Education.h"
using namespace std;

enum Level {AS, AO, FU};

class Faculty : public Employee {
	private:
		Level level;
		Education object;
	public:
		// constructors
		Faculty();
		Faculty(string last, string first, string id, string deg, string maj, int num, Level lvl);
		
		void setLevel(Level lvl);	
		Level getLevel() const;
		
		double monthlyEarning();
		void putData();
};

#endif
