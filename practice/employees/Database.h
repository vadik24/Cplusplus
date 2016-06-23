#include "Employee.h"

namespace secret{
  const int maximumEmployees = 100;
  const int employeeIDStart = 1000;

  class Database{
  public:
    Database();
    Employee& addEmployee(string firstName,string lastName);
    Employee& getEmployee(int employeeNumber);
    Employee& getEmployee(string firstName,string lastName);
    void displayAllE();
    void displayPrevE();
      void displayCurrentE();


  private:
    Employee listEmployee[maximumEmployees];
    int nextElement;
    int nextEmployee;
  };
}
