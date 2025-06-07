#include <iostream>
#include <string>
#include "Education.h"
using namespace std;

Education::Education(){
	degree = "NULL";
	major = "NULL";
	researchNum = 0;
}

Education::Education(string deg, string maj, int num){
	degree = deg;
	major = maj;
	researchNum = num;
}
// setters
void Education::setDegree(string deg){
	degree = deg;
}
void Education::setMajor(string maj){
	major = maj;
}
void Education::setResearchNum(int num){
	researchNum = num;
}
// getters
string Education::getDegree() const{
	return degree;
}
string Education::getMajor() const{
	return major;
}
int Education::getResearchNum() const{
	return researchNum;
}
