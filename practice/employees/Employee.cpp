#include <iostream>
#include "Employee.h"
namespace secret{
  Employee::Employee(){
    firstName = "";
    lastName = "";
    salary = 30000;
    mhired = false;
    employeeNumber = -1;
  }
  void Employee::setFirstName(string firstName){
    this->firstName = firstName;
  }
  void Employee::setLastName(string lastName){
    this->lastName = lastName;
  }
  string Employee::getFirstName(){
    return this->firstName;
  }
  string Employee::getLastName(){
    return this->lastName;
  }
  void Employee::setEmployeeNumber(int employeeNumber){
    this->employeeNumber = employeeNumber;
  }
  int Employee::getEmployeeNumber(){
    return this->employeeNumber;
  }
  void Employee::hired(){
    mhired = true;
  }
  void Employee::fired(){
    mhired = false;
  }
  bool Employee::isFired(){
    return !mhired;
  }
  void Employee::promote(int raiseSalary){
    setSalary(getSalary() + raiseSalary);
  }
  void Employee::demote(int dropSalary){
    setSalary(getSalary()-dropSalary);
  }
  void Employee::setSalary(int newSalary){
    this->salary = newSalary;
  }
  int Employee::getSalary(){
    return this->salary;
  }
  void Employee::display(){
    cout << "Employee: " << getLastName() << ", " << getFirstName() << endl;
    cout << "-------------------------" << endl;
    cout << (mhired ? "Current Employee" : "Former Employee") << endl;
    cout << "Employee Number: " << getEmployeeNumber() << endl;
    cout << "Salary: $" << getSalary() << endl;
    cout << endl;
}
}
