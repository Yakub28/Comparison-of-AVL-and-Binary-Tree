#ifndef AVL_H_KNOWN
#define AVL_H_KNOWN
#include <iostream>
using namespace std;

template <typename T>
class Avl_tree {
public:
    class Node {
        public:
        T data;
        int height;
        Node *l, *r;

        Node(T val) : data(val), height(1), l(nullptr), r(nullptr) {}
    };
    Node *root;
    Avl_tree() : root(nullptr) { }
    void clear(Node* node) {
        if (!node) return;
        clear(node->l);
        clear(node->r);
        delete node;
    }
    void insert(T data) {
    root = insert(root, data);
    }

    int height(Node *node) {
        if (!node) return 0;
        return node->height;
    }

    int balancing(Node *node) {
        if (!node) return 0;
        return height(node->l) - height(node->r);
    }

    Node* rotate_left(Node *node) {
        Node *r = node->r;
        if (!r) {
        return node;
        }
        Node *rightLeft = r->l;

        r->l = node;
        node->r = rightLeft;

        node->height = std::max(height(node->l), height(node->r)) + 1;
        r->height = std::max(height(r->l), height(r->r)) + 1;

        return r;
    }

    Node* rotate_right(Node *node) {
        
        Node *left = node->l;
        if (!left) {
        return node;
        }
        Node *leftRight = left->r;

        left->r = node;
        node->l = leftRight;

        node->height = std::max(height(node->l), height(node->r)) + 1;
        left->height = std::max(height(left->l), height(left->r)) + 1;

        return left;
    }

    Node* insert(Node *nd, T d) {
        if (!nd) return new Node(d);

        if (d < nd->data) {
            nd->l = insert(nd->l, d);
        } else {
            nd->r = insert(nd->r, d);
        }

        nd->height = std::max(height(nd->l), height(nd->r)) + 1;
        int b_factor = balancing(nd); 

        if (b_factor > 1 && d < nd->l->data) {
            return rotate_right(nd);
        }

        if (b_factor < -1 && d > nd->r->data) {
            return rotate_left(nd);
        }

        if (b_factor > 1 && d > nd->l->data) {
            nd->l = rotate_left(nd->l);
            return rotate_right(nd);
        }

        if (b_factor < -1 && d < nd->r->data) {
            nd->r = rotate_right(nd->r);
            return rotate_left(nd);
        }

        return nd;
    }
    bool contains(T d) {
    Node *present = root;
    while (present) {
        if (d < present->data) {
            present = present->l;
        } else if (d > present->data) {
            present = present->r;
        } else {
            return true;
        }
    }
    return false;
    }

void print() {
    print(root);
    cout << endl;
}
void print(Node *nd, int lvl = 0) {
    if (!nd) return;
    print(nd->r, lvl + 1);
    for (int i = 0; i < lvl; i++) {
        cout << "    ";
    }
    cout << nd->data << endl;
    print(nd->l, lvl + 1);
}
~Avl_tree() {
    clear(root);
}
};
#endif