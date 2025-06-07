#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>
#include <fstream>
#include "Employee.h"
#include "Staff.h"
#include "Partime.h"
#include "Education.h"
#include "Faculty.h"
using namespace std;

void printMenu();
void addData(vector<Employee*>& emp);
void displayData(vector<Employee*>& emp);
void writeData(vector<Employee*>& emp);
void readData(vector<Employee*>& emp);

int main(){
	vector<Employee*> emp;
	char choice;
	
	// STAFF
	emp.push_back(new Staff("Allen", "Paita", "123", 50.00));
	emp.push_back(new Staff("Zapata", "Steven", "456", 35.00));
	emp.push_back(new Staff("Rios", "Enrique", "789", 40.00));
	// FACULTY
	emp.push_back(new Faculty("Johnson", "Anne", "243", "Ph.D", "Engineering", 3, FU));
	emp.push_back(new Faculty("Bouris", "William", "791", "Ph.D", "English", 1, AO));	
	emp.push_back(new Faculty("Andrade", "Christopher", "623", "MS", "Physical Education", 0, AS));
	// PART - TIME
	emp.push_back(new Partime("Guzman", "Augusto", "455", 35.00, 30));
	emp.push_back(new Partime("Depirro", "Martin", "678", 30.00, 15));	
	emp.push_back(new Partime("Aldaco", "Marque", "945", 20.00, 35));
	
	
	do{
		printMenu();
		cout << "What would you like to do? (a/d/w/r/q): ";
		cin >> choice; cout << endl;
		switch(choice) {
			case 'a':
				addData(emp); // FULLY FUNCTIONAL
				break;
			case 'd':
				displayData(emp); // FULLY FUNCTIONAL
				break;
			case 'w':
				writeData(emp);
				break;
			case 'r':
				readData(emp);
				break;
			case 'q':
				cout << "Goodbye!" << endl;
				break;
			default:
				cout << "Choice isn't available!" << endl;
				break;
		}
	} while(choice != 'q');
	
	return 0;
}

void printMenu(){
	cout << "------------ Menu ------------ " << endl;
	cout << "a -- add data for an employee" << endl;
	cout << "d -- display data for all employees" << endl;
	cout << "w -- write all employee data to file" << endl;	
	cout << "r -- read all employee data from file " << endl;
	cout << "q --- quit program " << endl;
	cout << endl;
}

void addData(vector<Employee*>& emp){
	char empType;
	string first;
	string last;
	string id;
	string deg;
	string maj;
	string levelStr;
	int userInput;
	
	cout << "New Staff, Faculty, or Partime? (s/f/p): "; cin >> empType; cout << endl;
	cout << "Input Employee's Last Name: "; cin >> last;
	cout << "Input Employee's First Name: "; cin >> first;
	cout << "Input Employee's Name ID: "; cin >> id; cout << endl;

	switch(empType) {
		case 's':
			double staffRate;
			cout << "Input Employee's Hourly Rate: "; cin >> staffRate; cout << endl;
			emp.push_back(new Staff(last, first, id, staffRate));
			break;
		case 'f':
			int resNum; 	
			
			cout << "Input Employee's Degree: "; cin >> deg;
			cout << "Input Employee's Major: "; cin >> maj;
			cout << "Input Employee's Number of Research: "; cin >> resNum;
			cout << "Input Faculty Level (AS/AO/FU): "; cin >> levelStr; cout << endl;
			
			Level level;
			if(levelStr == "AS"){
				level = AS;
			} else if (levelStr == "AO"){
				level = AO;
			} else if (levelStr == "FU"){
				level = FU;
			} else {
				cout << "N/A";
				break;
			}
			
			emp.push_back(new Faculty(last, first, id, deg, maj, resNum, level));
			break;
		case 'p':
			double ptRate;
			int hrs;
			
			cout << "Input Employee's Hourly Rate: "; cin >> ptRate; cout << endl;
			cout << "Input Employee's Hours: "; cin >> hrs; cout << endl;
			emp.push_back(new Partime(last, first, id, ptRate, hrs));
			break;
		default:
			cout << "Invalid employee type." << endl;
			break;
	}	
}

void displayData(vector<Employee*>& emp){
	double totalSalary = 0;
	double totalPartTimeSalary = 0;
	double totalFacultySalary = 0;
	double totalStaffSalary = 0;
	
	for(int i = 0; i < emp.size(); i++){
		emp[i]->putData();
		totalSalary += emp[i]->monthlyEarning();
		
		if(Partime* pt = dynamic_cast<Partime*>(emp[i])){
			totalPartTimeSalary += emp[i]->monthlyEarning();
		} else if (Faculty* fy = dynamic_cast<Faculty*>(emp[i])){
			totalFacultySalary += emp[i]->monthlyEarning();
		} else if (Staff* st = dynamic_cast<Staff*>(emp[i])) {
			totalStaffSalary += emp[i]->monthlyEarning();
		}
	}
	
	cout << "Total monthly salary for all the part-time staff: $" << totalPartTimeSalary << endl;
	cout << "Total monthly salary for faculty: $" << totalFacultySalary << endl;
	cout << "Total monthly salary for all staff: $" << totalStaffSalary << endl;
	cout << "Total monthly salary for all employees: $" << totalSalary << endl;
}

void writeData(vector<Employee*>& emp){
	ofstream partimeFile("partime.txt");
	ofstream facultyFile("faculty.txt");
	ofstream staffFile("staff.txt");
	for(int i = 0; i < emp.size(); i++){
		if(Partime* pt = dynamic_cast<Partime*>(emp[i])){
			partimeFile << "Employee ID: ";
			partimeFile << emp[i]->getNameID() << endl;
			partimeFile << "Employee name: ";
			partimeFile << emp[i]->getFirstName() << " " << emp[i]->getLastName() << endl;
			partimeFile << "Hours worked per month: ";
			partimeFile << pt->getHours() << endl;
			partimeFile << "Monthly Salary: $";
			partimeFile << emp[i]->monthlyEarning() << endl;
			partimeFile << endl;
		} else if (Faculty* fy = dynamic_cast<Faculty*>(emp[i])){
			facultyFile << "Employee ID: ";
			facultyFile << emp[i]->getNameID() << endl;
			facultyFile << "Employee name: ";
			facultyFile << emp[i]->getFirstName() << " " << emp[i]->getLastName() << endl;
			if(fy->getLevel() == 0){
				facultyFile << "Assistant Professor" << endl;
			} else if (fy->getLevel() == 1){
				facultyFile << "Associate Professor" << endl;
			} else if (fy->getLevel() == 2) {
				facultyFile << "Fulltime Professor" << endl;
			}
			facultyFile <<  "Monthly Salary: $";
			facultyFile << emp[i]->monthlyEarning() << endl;
			facultyFile << endl;
		} else if (Staff* st = dynamic_cast<Staff*>(emp[i])) {
			staffFile << "Employee ID: ";
			staffFile << emp[i]->getNameID() << endl;
			staffFile << "Employee name: ";
			staffFile << emp[i]->getFirstName() << " " << emp[i]->getLastName() << endl;
			staffFile << "Full time" << endl;
			staffFile << "Monthly Salary: $" << emp[i]->monthlyEarning() << endl;
			staffFile << endl;
		}
	}
	
	partimeFile.close();
	facultyFile.close();
	staffFile.close();	
}

void readData(vector<Employee*>& emp) {
	string readPartime;
	string readFaculty;
	string readStaff;
	ifstream partimeFile("partime.txt");
	ifstream facultyFile("faculty.txt");
	ifstream staffFile("staff.txt");
	
	if(staffFile.is_open()){
		while(getline(staffFile, readStaff)) {
			cout << readStaff << endl;
		}
	} else {
		cerr << "no staff employees" << endl;
	}
	
	if(facultyFile.is_open()){
		while(getline(facultyFile, readFaculty)) {
			cout << readFaculty << endl;
		}
	} else {
		cerr << "no faculty employees" << endl;
	}
	
	if(partimeFile.is_open()){
		while(getline(partimeFile, readPartime)) {
			cout << readPartime << endl;
		}
	} else {
		cerr << "no partime employees" << endl;
	}
	
	staffFile.close();
	facultyFile.close();
	partimeFile.close();
}
