#include <stdexcept>
#include <iostream>
#include "Database.h"
namespace secret{
  Database::Database(){
    nextElement = 0;
    nextEmployee = employeeIDStart;
  }

  Employee& Database::addEmployee(string firstName,string lastName){
    //check if hit maximum list of employees
    if(nextElement>= maximumEmployees){
      cout << "Hit the limit, can't add more employees in list" <<endl;
      throw exception();
    }
    //reference to database list of employees
    Employee& employee = listEmployee[nextElement++];
    //set employee info
    employee.setFirstName(firstName);
    employee.setLastName(lastName);
    employee.setEmployeeNumber(nextEmployee++);
    employee.hired();
    return employee;

  }
  Employee& Database::getEmployee(int employeeNumber){
    for(int i = 0;i<nextElement;i++){
      if(listEmployee[i].getEmployeeNumber() == employeeNumber){
        return listEmployee[i];
      }
    }
    throw exception();
  }
  Employee& Database::getEmployee(string firstName,string lastName){

    for(int i = 0;i<nextElement;i++){
      if((listEmployee[i].getLastName() == lastName) && (listEmployee[i].getFirstName() == firstName)){
        return listEmployee[i];
      }
    }
    throw exception();
  }
  void Database::displayAllE(){
    for(int i =0;i<nextElement;i++){
      listEmployee[i].display();
    }
  }
  void Database::displayCurrentE(){
    for(int i =0;i<nextElement;i++){
      if(listEmployee[i].isFired() == false)
        listEmployee[i].display();
    }
  }
  void Database::displayPrevE(){
    for(int i =0;i<nextElement;i++){
      if(listEmployee[i].isFired() == true)
        listEmployee[i].display();
    }
  }
}
