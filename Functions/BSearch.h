#include <iostream>
#ifndef BSearch_h
#define  BSearch_h


template <typename T>
class b_tree {
 public:
  b_tree() : root(nullptr) {} 

  ~b_tree() { 
    clear();
  }

  class Node {
    public:
    T data;
    Node* l;
    Node* r;

    Node(T val) : data(val), l(nullptr), r(nullptr) {}
  };

  Node* root;


  void clear() {
    clear(root);
  }
  void clear(Node* nd) {
    if (nd == nullptr) {
      return;
    }
    clear(nd->l);
    clear(nd->r);
    delete nd;
  }

  void insert(T val) {
    Node* newNode = new Node(val);

    if (root == nullptr) {
      root = newNode;
      return;
    }

    Node* present = root;
    Node* parent = nullptr;

    while (present != nullptr) {
      parent = present;

      if (val < present->data) {
        present = present->l;
      } else {
        present = present->r;
      }
    }

    if (val < parent->data) {
      parent->l = newNode;
    } else {
      parent->r = newNode;
    }
  }
bool contains(T val) {
    Node* present = root;
    while (present != nullptr) {
        if (present->data == val) {
            return true;
        }
        if (val < present->data) {
            present = present->l;
        } else {
            present = present->r;
        }
    }
    return false;
}
void print() {
    print(root);
}
void print(Node* nd){
    if(nd==nullptr){
        return;
    }
    print(nd->l);
    std::cout<<nd->data<<" ";
    print(nd->r);
}
};

#endif