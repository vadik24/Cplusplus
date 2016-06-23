#include "Database.h"
#include "iostream"

using namespace std;
using namespace secret;


int displayMenu();
void hireE(Database& db);
void fireE(Database& db);
void promoteE(Database& db);
int main(){
  Database db;
  while(1){
    switch(displayMenu()){
      case 0:
        return 0 ;
      case 1:
        // hire
        hireE(db);
        break;
      case 2:
        //fire
        fireE(db);
        break;
      case 3:
        // promote
        promoteE(db);
        break;
      case 4:
        // show all employees
        db.displayAllE();
        break;
      case 5:
        // show current employees
        db.displayCurrentE();
        break;
      case 6:
        // show prev employees;
        db.displayPrevE();
        break;
      default:
        cerr << "bad command" << endl;
    }
  }
}

int displayMenu(){
  cout << endl;
  cout << "Employee Database" << endl;
  cout << "-----------------" << endl;
  cout << "1) Hire a new employee" << endl;
  cout << "2) Fire an employee" << endl;
  cout << "3) Promote an employee" << endl;
  cout << "4) List all employees" << endl;
  cout << "5) List all current employees" << endl;
  cout << "6) List all previous employees" << endl;
  cout << "0) Quit" << endl;
  cout << endl;
  cout << "---> ";
  int select;
  cin >> select;
  return select;
}
void hireE(Database& db){
  string firstName;
  string lastName;
  cout << "First name? ";
  cin >> firstName;
  cout << "Last name? ";
  cin >> lastName;
  try {
  db.addEmployee(firstName,lastName);
  }
  catch (exception ex) {
    cerr << "Unable to add new employee!" << endl;
  }
}
void fireE(Database& db){
  int employeeNumber;
  cout << "Employee's number?" << endl;
  cin >> employeeNumber;
  Employee& empl =  db.getEmployee(employeeNumber);
  empl.fired();
  cout << "Employee id # " << employeeNumber << " has been fired."<< endl;
}

void promoteE(Database& db){
  int raiseSalary;
  int employeeNumber;
  try{
    cout << "Employee's number?" << endl;
    cin >> employeeNumber;
    Employee& empl = db.getEmployee(employeeNumber);
    cout << "How much is the raise?" << endl;
    cin >> raiseSalary;
    empl.promote(raiseSalary);
  }catch(exception ex){
    cerr << "match not found" << endl;
  }

}
