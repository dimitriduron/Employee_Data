/*
 * Employee.h
 *
 * General class for all workers
 */

//Included files
#include <iostream>
using namespace std;

#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

class Employee
{
	public:
		//Employee constructor
		Employee(string name, long id, char workType, long salary, long restEarnings);
		//Includes "Name", "Employee ID", "Employment Type", and "Salary"

		//display function for ostream
		virtual void display(ostream &out) const;

		//Generalizes bonus from each employee and simplifies earnings
		double bonus = 0;

	protected:
		//protected variables
		string myName;
		long myId;
		char myWorkType;

	public:
		long mySalary;
		long myRestEarnings;
		double total;
};

//Employee definition
inline Employee::Employee(string name, long id, char workType, long salary, long restEarnings)
:myName(name), myId(id), myWorkType(workType), mySalary(salary), myRestEarnings(restEarnings) {}

//Display definition
inline void Employee::display(ostream &out) const
{
	out << "-------------------------------" << endl
		<< "Name:		 	" << myName << endl
		<< "Employee ID:	 	" << myId << endl
		<< "Monthly Salary:	 	$" << mySalary << endl;
}

//Definition of ostream override
inline ostream &operator<<(ostream &out, Employee &emp)
{
	emp.display(out);
	return out;
};


#endif /* EMPLOYEE_H_ */
