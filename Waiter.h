/*
 * Waiter.h
 *
 *  Only for restaurant Waiters
 */

//Included header files
#include "Employee.h"

#ifndef WAITER_H_
#define WAITER_H_

class Waiter: public Employee
{
	public:
		//Waiter constructor
		Waiter(string name, long id, char workType, long salary, long restEarnings, int years, long tips);
		//Includes employee variables + extra monthly earning

		//display constructor
		virtual void display(ostream &out) const;

		//generalized bonus from base class
		long myTips;
		double bonus = myTips;
		double total = bonus + mySalary;

	protected:
		double myMonthlyPercent = 0;
		int myYears;
};

//Definition of Waiter constructor
inline Waiter::Waiter(string name, long id, char workType, long salary, long restEarnings, int years, long tips)
:Employee(name, id, workType, salary, restEarnings), myTips(tips), myYears(years) {}

//Definition of Owner display
inline void Waiter::display(ostream &out) const
{
	Employee::display(out);
	out << "Monthly Tips:		$" << bonus << endl
		<< "Monthly Earnings:	$" << total << endl
		<< "Title:			" << "Waiter" << endl
		<< "Years of Exp:		" << myYears << endl;
}



#endif /* WAITER_H_ */
