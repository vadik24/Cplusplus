#include<string>
using namespace std;
namespace secret{
  class Employee{
  public:
    Employee();
    void setFirstName(string firstName);
    void setLastName(string lastName);
    string getFirstName();
    string getLastName();
    void setEmployeeNumber(int employeeNumber);
    int getEmployeeNumber();
    void hired();
    void fired();
    bool isFired();
    void promote(int raisedSalary = 1000);
    void demote(int dropSalary);
    void setSalary(int newSalary);
    int getSalary();
    void display();
  private:
    string firstName;
    string lastName;
    int salary;
    bool mhired;
    int employeeNumber;
  };
}
