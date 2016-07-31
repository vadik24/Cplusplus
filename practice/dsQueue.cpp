#include"node.h"
#include<iostream>
// pop, insert, and peek front & back
Node *pop(Node * head);
Node *insert(Node *tail);
void front(Node *head);
void end(Node *tail);
void printList(Node *head);
using namespace std;
int main(){
  Node *head=0;
  Node *tail=0;
  Node *printNode;
  //add data in queue list
  cout <<"type a number between 1-5" << endl;
  cout << "1 = insert new data to the list" << endl;
  cout << "2 = pop(remove from the list)" << endl;
  cout << "3 = peek front data from the list" << endl;
  cout << "4 = peek end data from the list " << endl;
  cout << "5 = print the data from the list" << endl;
  while(1){
    int input;
    cin >> input;
    switch(input){
      case 1:
        tail = insert(tail);
        if(head== 0){
          head = tail;
        }
        break;
      case 2:
        head = pop(head);
        break;
      case 3:
        front(head);
        break;
      case 4:
        end(tail);
        break;
      case 5:
        printList(head);
        break;
      default:
        cout << "invalid input" << endl;
    }
    cout <<"type a number between 1-4" << endl;
  }

  return 0;
}
//remove node from front list
Node *pop(Node * head){
  if(head!= 0)
    head = head->next;
    if(head ==0){
     cout << "The list is already empty" << endl;
    }
    return head;
}
//add note in list
Node *insert(Node *tail){
  cout << "type the value to add in the sequence list" << endl;
  int data;
  cin >> data;
  Node *temps = new Node(data);
  if(tail==0){
    tail = temps;
  }
  else{
    tail->next = temps;
    tail = tail->next;
  }
}
//print front node
void front(Node *head){
  if(head!= 0){
    cout << " front data info" << endl;
    cout << head->data << endl;
  }
  else
    cout << "The list is empty" << endl;
}
//print end node
void end(Node *tail){
  if(tail !=0){
    cout << "end data info" << endl;
    cout << tail->data << endl;
  }
  else
    cout << "The list is empty" << endl;
}
//print list of nodes
void printList(Node *head){
  while(head != 0){
    cout << head->data << "|";
    head = head->next;
  }
  cout << endl;
}
