#include<string>
#include<iostream>
struct Node{
  Node *next;
  int data;
};

int main(){
  Node *listNode;
  Node *head = NULL;
  //add info to linked list
  for(int i = 0;i<10;i++){
    listNode = new Node;
      listNode->data = i+ 1;
      listNode->next = head;
      head =listNode;
  }
  std::cout << "HMM"<< std::endl;
  std::cout << listNode->data << " || " << std::endl;
std::cout << listNode->next->data << " || " << std::endl;

  return 0;
}
