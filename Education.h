#ifndef EDUCATION_H
#define EDUCATION_H
#include <iostream>
#include <string>
using namespace std;

class Education{
	private:
		string degree;
		string major;
		int researchNum;
	public:
		// constructors
		Education();
		Education(string deg, string maj, int num);
		// setters
		void setDegree(string deg);
		void setMajor(string maj);
		void setResearchNum(int num);
		// getters
		string getDegree() const;
		string getMajor() const;
		int getResearchNum() const;
};

#endif
