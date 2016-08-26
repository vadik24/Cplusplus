#include <iostream>
class Node{
public:
  Node(int data):data(data){}
  Node * left;
  Node * right;
  int data;

};

//insert
void insert(Node** head, int data){
  if(*head==0){
    *head = new Node(data);
    (*head)->left =0;
    (*head)->right = 0;
    return;
  }
  if((*head)->data > data){
    insert(&(*head)->left,data);
  }
  else if((*head)->data < data){
    insert(&(*head)->right,data);
  }

}

void deleteTree(Node **head){
  if(*head==0){
    return;
  }
    deleteTree(&(*head)->left);
    deleteTree(&(*head)->right);
    delete *head;
}

void printPreTree(Node* head){
  if(head==0){
    return;
  }
  //display
  std::cout << head->data << "|" << std::endl;
  if(head->left!=0){
    printPreTree(head->left);
  }
  if(head->right!=0){
    printPreTree(head->right);
  }
}

void printInTree(Node *head){
  if(head==0){
    return;
  }
  if(head->left!= 0){
    printInTree(head->left);
  }
  std::cout << head->data << "|" << std::endl;

  if(head->right!=0){
    printInTree(head->right);
  }


}
//insert, remove, search
int main(){
Node * root = 0;
insert(&root,10);
insert(&root,30);
insert(&root,20);
insert(&root,25);
insert(&root,41);
insert(&root,5);
std::cout << "Print PreTree Traverse" << std::endl;
printPreTree(root);
std::cout << "Print InTree Traverse" << std::endl;
printInTree(root);
deleteTree(&root);
printPreTree(root);
  return 0;
}
