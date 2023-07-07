#ifndef GRAPHS_BINARYTREE_H
#define GRAPHS_BINARYTREE_H

#include "../LinkedList/LinkedList.h"

template <typename T>
class BinaryTree {
private:
    struct Node {
        int key;
        T data;
        Node* leftNode;
        Node* rightNode;
        Node() {
            leftNode = nullptr;
            rightNode = nullptr;
        }
    };
    Node* head;

protected:
    void get_data_list(Node* node, LinkedList<T>& list); // add data to my LinckedList (for class)
    void print_tree(Node* node);// print all data from list (for class)
    void clear(Node* node); // clear all Tree (for class)


public:
    BinaryTree();
    ~BinaryTree();

    void add_data(int key, T data);// add data to tree
    void print_tree();// print all tree
    T get_data(int key);// get data from tree
    LinkedList<T>& get_data_list(LinkedList<T>& list); // add data to my LinckedList
    void clear(); // clear all tree
};

#endif //GRAPHS_BINARYTREE_H
