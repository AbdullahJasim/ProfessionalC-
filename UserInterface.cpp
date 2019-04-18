#include <iostream>
#include <stdexcept>
#include <exception>
#include"DataBase.h"

using namespace std;
using namespace Records;

int displayMenu();
void doHire(Database& db);
void doFire(Database& db);
void doPromote(Database& db);
void doDemote(Database& db);

int main() {
	Database db;
	bool done = false;

	while (!done) {
		int selection = displayMenu();

		switch (selection) {
		case 0:
			done = true;
			break;
		case 1:
			doHire(db);
			break;
		case 2:
			doFire(db);
			break;
		case 3:
			doPromote(db);
			break;
		case 4:
			db.displayAll();
			break;
		case 5:
			db.displayCurrent();
			break;
		case 6:
			db.displayFormer();
			break;
		default:
			cerr << "Unknown command." << endl;
			break;
		}
	}

	return 0;
}

int displayMenu() {
	int selection;

	cout << endl;
	cout << "Employee Database" << endl;
	cout << "--------------------------" << endl;
	cout << "1. Hire Employee" << endl;
	cout << "2. Fire Employee" << endl;
	cout << "3. Promote Employee" << endl;
	cout << "4. Show All Employees" << endl;
	cout << "5. Show Current Employees" << endl;
	cout << "6. Show Former Employees" << endl;
	cout << "0. Quit" << endl;
	cout << endl;
	cout << "Enter choice: ";
	cin >> selection;
	return selection;
}

void doHire(Database& db) {
	string firstName;
	string lastName;

	cout << "Please enter the new employee's first name: ";
	cin >> firstName;

	cout << "Please enter the new employee's last name: ";
	cin >> lastName;

	try {
		db.addEmployee(firstName, lastName);
	} catch (const exception& exception) {
		cerr << "Unable to add new employee: " << exception.what() << endl;
	}
}

void doFire(Database &db) {
	int employeeNumber;
	cout << "Enter employee number to fire: ";
	cin >> employeeNumber;

	try {
		Employee& emp = db.getEmployee(employeeNumber);
		emp.fire();
		cout << "Employee " << employeeNumber << " terminated." << endl;
	} catch (const exception& exception) {
		cerr << "Unable to terminate employee." << endl;
	}
}

void doPromote(Database& db) {
	int employeeNumber;
	int raiseAmount;
	cout << "Enter employee number to promote: ";
	cin >> employeeNumber;
	cout << endl;
	cout << "Enter raise amount: ";
	cin >> raiseAmount;

	try {
		Employee& emp = db.getEmployee(employeeNumber);
		emp.promote(raiseAmount);
	} catch (const exception& exception) {
		cerr << "Unable to promote employee." << endl;
	}
}

void doDemote(Database& db) {
	int employeeNumber;
	int demeritAmount;
	cout << "Enter employee number to demote: ";
	cin >> employeeNumber;
	cout << endl;
	cout << "Enter demerit amount: ";
	cin >> demeritAmount;

	try {
		Employee& emp = db.getEmployee(employeeNumber);
		emp.demote(demeritAmount);
	} catch (const exception& exception) {
		cerr << "Unable to promote employee." << endl;
	}
}