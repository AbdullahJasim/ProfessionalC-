#include <iostream>
#include "Employee.h"

namespace Records {
	Employee::Employee() :
		mFirstName(""),
		mLastName(""),
		mEmployeeNumber(-1),
		mSalary(kDefaultStartingSalary),
		mHired(false)
	{}

	void Employee::promote(int raiseAmount) {
		setSalary(mSalary = getSalary() + raiseAmount);
	}

	void Employee::demote(int demeritAmount) {
		setSalary(mSalary = getSalary() - demeritAmount);
	}

	void Employee::hire() {
		mHired = true;
	}

	void Employee::fire() {
		mHired = false;
	}

	void Employee::display() const {
		cout << "Employee: " << getLastName() << ", " << getFirstName() << endl;
		cout << "------------------" << endl;
		cout << (mHired ? "Current Employee" : "Former Employee") << endl;
		cout << "Employee Number: " << getEmployeeNumber() << endl;
		cout << "Salary: $" << getSalary() << endl;
		cout << endl;
	}

	void Employee::setFirstName(const string& firstName) {
		mFirstName = firstName;
	}

	const string& Employee::getFirstName() const {
		return mFirstName;
	}

	void Employee::setLastName(const string& lastName) {
		mLastName = lastName;
	}

	const string& Employee::getLastName() const {
		return mLastName;
	}

	void Employee::setEmployeeNumber(int employeeNumber) {
		mEmployeeNumber = employeeNumber;
	}

	int Employee::getEmployeeNumber() const {
		return mEmployeeNumber;
	}

	void Employee::setSalary(int newSalary) {
		mSalary = newSalary;
	}

	int Employee::getSalary() const {
		return mSalary;
	}

	bool Employee::getIsHired() const {
		return mHired;
	}
} 