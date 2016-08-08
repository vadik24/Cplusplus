#include "node.h"
using namespace std;
Node::Node(int d){
  data = d;
  next = 0;
  prev = 0;
}

// or this way
/*
struct Node{
  Node *next;
  int data;
};
*/
