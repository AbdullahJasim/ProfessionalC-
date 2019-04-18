#include <iostream>
#include "DataBase.h"

using namespace std;
using namespace Records;

void testDatabaseClass() {
	Database myDB;

	Employee& emp1 = myDB.addEmployee("Kenway", "Edward");
	emp1.fire();

	Employee& emp2 = myDB.addEmployee("Kenway", "Haytham");
	emp2.setSalary(100000);

	Employee& emp3 = myDB.addEmployee("Kenway", "Connor");
	emp3.setSalary(100000);
	emp3.promote();

	cout << "All Employees:" << endl << endl;
	myDB.displayAll();

	cout << "Current Employees:" << endl << endl;
	myDB.displayCurrent();

	cout << "Former Employees:" << endl << endl;
	myDB.displayFormer();
}

//int main() {
//	testDatabaseClass();
//
//	return 0;
//}