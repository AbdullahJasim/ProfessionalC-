#include <iostream>
#include "Employee.h"

using namespace std;
using namespace Records;

void testEmployeeClass () {
	cout << "Testing the Employee Class." << endl;
	Employee emp;

	emp.setFirstName("Edward");
	emp.setLastName("Kenway");
	emp.setEmployeeNumber(145);
	emp.setSalary(50000);
	emp.promote();
	emp.promote(50);
	emp.hire();
	emp.display();
}

//int main() {
//	testEmployeeClass();
//
//	return 0;
//}