//two linked list sorted
//merge two list into one linkedlist sorted
#include "node.h"
#include <iostream>

//print list
void printNodeList(const Node *list);
//merge two linkedlist into one sorted list;
Node *mergeLinkedListR(Node *n1,Node *n2);
Node *mergeLinkedListL(Node *n1,Node *n2);
int main(){
  //create first linked list sorted
  Node *leftS = new Node(1);
  Node *n1 = leftS;
  for(int i =1;i<100;i++){
    leftS->next = new Node(i*2+1);
    leftS = leftS->next;

  }
  //create second linked list sorted
  Node *rightS = new Node(0);
  Node *n2 = rightS;
  for(int i =1;i<100;i++){
    rightS->next = new Node(i*2);
    rightS = rightS->next;
  }
  std::cout << "first Linkedlist" << std::endl;
  printNodeList(n1);
  std::cout <<  "second Linkedlist" << std::endl;
  printNodeList(n2);
  std::cout << "merge Linkedlist" << std::endl;
  //n1 = mergeLinkedListR(n1,n2);
  n1 = mergeLinkedListL(n1,n2);
  printNodeList(n1);
}

void printNodeList(const Node *list){
  while(list!=0){
    std::cout << list->data << " | ";
    list = list->next;
  }
  std::cout << std::endl;
}
//merge two linkedlist into one sorted list;
Node *mergeLinkedListR(Node *n1, Node *n2){
  //create a node to sort the list
  Node *head = 0;
  //if both are null
  if(n1!=0 && n2!=0){
    if(n1->data >n2->data){
      //head = n2;
      n2->next = mergeLinkedListR(n1,n2->next);
      return n2;
    }
    else if(n1->data == n2->data){
      //head = n1;
      n1->next= mergeLinkedListR(n1->next,n2);
      return n1;
    }
    else{
      //n1->data < n2->data
      //head = n1;
      n1->next = mergeLinkedListR(n1->next,n2);
      return n1;
    }

    return head;
  }
  else if(n2==0 && n1==0){
    return 0;
  }
  else if(n2==0)
    return n1;
  else
    return n2;

}

// merge two sort linkedlist, my method!
Node *mergeLinkedListL(Node *n1, Node *n2){
  Node *head = 0;
  //check if any of linkedlist is empty
  if(n1==0 && n2==0)
    return 0;
  else if(n1 ==0)
    return n2;
  else if(n2==0)
    return n1;

  if(n1->data>n2->data){
    head = n2;
    n2 = n1;
    n1 = head;
  }
  else{
    head = n1;
  }

  while(n1->next!=0 &&n2->next!=0){
    if(n1->next->data>n2->data){
      Node *tempNode = n1->next;
      n1->next = n2;
      n1 = n1->next;
      n2 = n2->next;
      n1->next =tempNode;
    }
    else
      n1=n1->next;
  }
  return head;
}
