#include "Database.h"
#include "iostream"
using namespace secret;
int main(){
  Database db;
  Employee& test=  db.addEmployee("vadim","Belonenko");
  cout << test.getEmployeeNumber();
  Employee test2 = db.getEmployee("vadim","Belonenko");
  cout << test2.getEmployeeNumber()<<endl;

}
