/*
    Implement a base class called Employee with virtual functions like
    calculateSalary() and displayDetails(). Create derived classes like Manager and
    Engineer, and override the virtual functions as per the specific requirements.
*/
#include <bits/stdc++.h>
using namespace std;

class Employee {
protected:
    string name;
    double baseSalary;

public:
    Employee(const string& empName, double empBaseSalary)
    {
        name=empName; 
        baseSalary=empBaseSalary; 
    }
    virtual double calculateSalary()
    {
        return 0;
    }

    void displayDetails() {
        cout << "Name: " << name << ", Base Salary: $" << baseSalary << endl;
    }

    //virtual ~Employee() {}
};

class Manager : public Employee {
private:
    double bonusPercentage;

public:
    Manager(const string& empName, double empBaseSalary, double empBonusPercentage)
    {
        Employee(empName, empBaseSalary); 
            bonusPercentage=(empBonusPercentage); 
    }

    double calculateSalary() {
        return baseSalary + (baseSalary * bonusPercentage / 100.0);
    }

    void displayDetails() {
        cout << "Manager Details - ";
        Employee::displayDetails();
        cout << "Bonus Percentage: " << bonusPercentage << "%" << endl;
    }
};

class Engineer : public Employee {
private:
    int overtimeHours;
    double overtimeRate;

public:
    Engineer(const string& empName, double empBaseSalary, int empOvertimeHours, double empOvertimeRate)
        : Employee(empName, empBaseSalary), overtimeHours(empOvertimeHours), overtimeRate(empOvertimeRate) {}

    double calculateSalary() {
        return baseSalary + (overtimeHours * overtimeRate);
    }

    void displayDetails() {
        cout << "Engineer Details - ";
        Employee::displayDetails();
        cout << "Overtime Hours: " << overtimeHours << ", Overtime Rate: $" << overtimeRate << endl;
    }
};

int main() {
    Manager manager("John Manager", 50000.0, 10.0);
    Engineer engineer("Jane Engineer", 60000.0, 20, 25.0);

    cout << "Manager Salary: $" << manager.calculateSalary() << endl;
    manager.displayDetails();

    cout << "\nEngineer Salary: $" << engineer.calculateSalary() << endl;
    engineer.displayDetails();

    return 0;
}