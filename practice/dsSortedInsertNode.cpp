#include<iostream>
#include "node.h"
Node* SortedInsert(Node *head,int data)
{
    // Complete this function
   // Do not write the main method.

    if(head ==0){
        head = new Node(data);
        head->data = data;
        head->next = 0;
        head->prev = 0;
        return head;
    }
    Node *temp = new Node(data);
    temp->data = data;
    Node *curr = head;
    while(curr->next!=0){
         if(data > curr->next->data){
              curr = curr->next;
         }
       else
           break;
   }
    temp->next = curr->next;
    temp->prev = curr->prev;
    curr->next = temp;


    return head;
}

void printNodeList(const Node *list){
  while(list!=0){
    std::cout << list->data << " | ";
    list = list->next;
  }
  std::cout << std::endl;
}

int main(){
  //create first linked list sorted
  Node *head= new Node(0);
  Node *n1 = head;
  for(int i =1;i<15;i++){
    n1->next = new Node(i*2+1);
    n1 = n1->next;
  }

  head = SortedInsert(head,30);

    printNodeList(head);
  return 0;
}
