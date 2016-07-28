#include "linkedlist.h"
using namespace std;
Node::Node(int d){
  data = d;
  next = 0;
}

// or this way
/*
struct Node{
  Node *next;
  int data;
};
*/
