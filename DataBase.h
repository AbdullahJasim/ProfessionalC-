#pragma once

#include <iostream>
#include <vector>
#include "Employee.h"

namespace Records {

	const int kFirstEmployeeNumber = 1000;

	class Database {
	public:
		Database();
		Employee& addEmployee(const string& firstName, const string& lastName);
		Employee& getEmployee(int employeeNumber);
		Employee& getEmployee(const string& firstName, const string& lastName);

		void displayAll() const;
		void displayCurrent() const;
		void displayFormer() const;

	private:
		vector<Employee> mEmployees;
		int mNextEmployeeNumber;
	};
}