#include <iostream>
#include <stdexcept>
#include "DataBase.h"

using namespace std;

namespace Records {
	Database::Database() : mNextEmployeeNumber(kFirstEmployeeNumber)
	{}

	Employee& Database::addEmployee(const string& firstName, const string& lastName) {
		Employee newEmployee;
		newEmployee.setFirstName(firstName);
		newEmployee.setLastName(lastName);
		newEmployee.setEmployeeNumber(mNextEmployeeNumber++);
		newEmployee.hire();
		mEmployees.push_back(newEmployee);
		return mEmployees[mEmployees.size() - 1];
	}

	Employee& Database::getEmployee(int employeeNumber) {
		for (auto& employee : mEmployees) {
			if (employee.getEmployeeNumber() == employeeNumber) {
				return employee;
			}
		}

		throw runtime_error("No Employee found.");
	}

	Employee& Database::getEmployee(const string& firstName, const string& lastName) {
		for (auto& employee : mEmployees) {
			if (employee.getFirstName() == firstName && employee.getLastName() == lastName) {
				return employee;
			}
		}

		throw runtime_error("No Employee found.");
	}

	void Database::displayAll() const {
		for (const auto& employee : mEmployees) {
			employee.display();
		}
	}

	void Database::displayCurrent() const{
		for (const auto& employee : mEmployees) {
			if (employee.getIsHired()) employee.display();
		}
	}

	void Database::displayFormer() const {
		for (const auto& employee : mEmployees) {
			if (!employee.getIsHired()) employee.display();
		}
	}
}