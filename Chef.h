/*
 * Chef.h
 *
 * Only for restaurant Chefs
 */

//Included header files
#include "Employee.h"

#ifndef CHEF_H_
#define CHEF_H_

class Chef: public Employee
{
	public:
		//Chef constructor
		Chef(string name, long id, char workType, long salary, long restEarnings, string specialty);
		//Includes employee variables + extra monthly earning

		//display constructor
		virtual void display(ostream &out) const;

		double myMonthlyPercent = .2;
		double bonus = myMonthlyPercent * myRestEarnings;
		double total = bonus + mySalary;

	protected:
		string mySpecialty;
};

//Definition of Chef constructor
inline Chef::Chef(string name, long id, char workType, long salary, long restEarnings, string specialty)
:Employee(name, id, workType, salary, restEarnings), mySpecialty(specialty) {}

//Definition of Owner display
inline void Chef::display(ostream &out) const
{
	Employee::display(out);
	out << "Monthly Bonus:		$" << bonus << endl
		<< "Monthly Earnings: 	$" << total << endl
		<< "Title:			" << "Chef" << endl
		<< "Cuisine of Expertise:	" << mySpecialty << endl;
}



#endif /* CHEF_H_ */
