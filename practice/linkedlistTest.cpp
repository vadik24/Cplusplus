#include<iostream>
#include"linkedlist.h"

//declare front
Node *addNodeBeggining(Node *node, int d);
void *addNodeMiddle(Node *node,int d,int position);
void *addNodeEnding(Node *node,int d);
Node *deleteNodeFront(Node *node);
Node *deleteNodeMiddle(Node *node, int position);
Node *deleteNodeEnd(Node *node);
void printNodeList(Node *node);
int main(){
  Node *listNode;
  Node *head = 0;
  //add info to linked list
  for(int i = 0;i<10;i++){
    listNode = new Node(i+ 1);
      listNode->next = head;
      head =listNode;
  }
  //print list of data in linkedlist
  std:: cout << "List of data in Linkedlist" << std:: endl;
  printNodeList(head);

  //insert 20 at beggining
  head = addNodeBeggining(head,20);
  //print list of data in linkedlist
  printNodeList(head);

  //insert 50 in position 5
  addNodeMiddle(head,50,5);
  //print list of data in linkedlist
  printNodeList(head);

  //insert 30 end of the node list
  addNodeEnding(head,30);
  //print list of data in linkedlist
  printNodeList(head);

  //delete front Node
  head= deleteNodeFront(head);
  //print list of data in linkedlist
  printNodeList(head);

  //delete middle node of the list
  deleteNodeMiddle(head,5);
  //print list of data in linkedlist
  printNodeList(head);

  //delete last node in the list
  deleteNodeEnd(head);
  //print list of data in linkedlist
  printNodeList(head);
  return 0;
}
//print linkedlist Node
void printNodeList(Node *node){
  while(node->next != 0){
    std::cout << node->data << " || ";
    node = node->next;
  }
  std::cout << node->data << " || ";
  std:: cout << std::endl;
}
//add node in list
Node *addNodeBeggining(Node *node,int d){
  Node *newNode = new Node;
  newNode->data = d;
  newNode->next = node;
  node = newNode;
  return node;
}

void *addNodeEnding(Node *node,int d){
  Node *currentNode = new Node(d);
  currentNode->next = 0;
  while(node->next!= 0){
    node = node->next;
  }
  node->next = currentNode;
}

void *addNodeMiddle(Node *node,int d,int position){
    Node *currentNode = node;
    Node *prevNode;
    Node *newNode = new Node(d);
    while(position-1){
      position--;
      prevNode = currentNode;
      currentNode= currentNode->next;
    }
    newNode->next = currentNode;
    prevNode->next = newNode;
}
//delete node in list if data match
Node *deleteNodeFront(Node *node){
  Node *currentNode = node;
  currentNode = currentNode->next;
  delete node;
  return currentNode;
}

//delete node in list if data match
Node *deleteNodeMiddle(Node *node,int position){
  Node *currentNode= node;
  Node *prevNode;
  while(position-1){
    position--;
    prevNode = currentNode;
    currentNode = currentNode->next;
  }
  prevNode->next = currentNode->next;
  delete currentNode;
  return node;
}

//delete node in list if data match
Node *deleteNodeEnd(Node *node){
  while(node->next->next!=0)
    node=node->next;
  delete node->next->next;
  node->next= 0;
  return node;
}
