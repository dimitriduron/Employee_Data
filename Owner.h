/*
 * Owner.h
 *
 * Only for restaurant owner
 */

//Included header files
#include "Employee.h"

#ifndef OWNER_H_
#define OWNER_H_

class Owner: public Employee
{
	public:
		//Owner constructor
		Owner(string name, long id, char workType, long salary, long restEarnings);
		//Includes employee variables + extra monthly earning

		//display constructor
		virtual void display(ostream &out) const;


		double myMonthlyPercent = .6;
		double bonus = myMonthlyPercent * myRestEarnings;
		double total = bonus + mySalary;
};

//Definition of Owner constructor
inline Owner::Owner(string name, long id, char workType, long salary, long restEarnings)
:Employee(name, id, workType, salary, restEarnings) {}

//Definition of Owner display
inline void Owner::display(ostream &out) const
{
	Employee::display(out);
	out << "Monthly Bonus:		$" << bonus << endl
		<< "Monthly Earnings:	$" << total << endl
		<< "Title:			" << "Owner" << endl;
}


#endif /* OWNER_H_ */
