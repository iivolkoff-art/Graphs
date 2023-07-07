#include "BinaryTree.h"
#include <iostream>
#include "../LinkedList/LinkedList.h"

using namespace std;

template class BinaryTree<int>;
template class BinaryTree<double>;
template class BinaryTree<string>;
template class BinaryTree<char>;
template class BinaryTree<bool>;

template <typename T>
void BinaryTree<T>::get_data_list(Node* node, LinkedList<T>& list) { // add data to my LinckedList (for class)
    if (node == nullptr) {
        return;
    }
    get_data_list(node->leftNode, list);
    list.push_back(node->data);
    get_data_list(node->rightNode, list);
}

template <typename T>
void BinaryTree<T>::print_tree(Node* node) { // print all data from list (for class)
    if (node == nullptr) {
        return;
    }
    print_tree(node->leftNode);

    cout << node->data << " ";

    print_tree(node->rightNode);
}

template <typename T>
void BinaryTree<T>::clear(Node* node) { // clear all Tree (for class)
    if (!node) {
        return;
    }
    clear(node->leftNode);
    clear(node->rightNode);
    delete node;
    head = nullptr;
}


template <typename T>
BinaryTree<T>::BinaryTree() {
    head = nullptr;
}
template <typename T>
BinaryTree<T>::~BinaryTree() {
    clear(head);
}


template <typename T>
void BinaryTree<T>::add_data(int key, T data) { // add data to tree
    Node* newNode = new Node;
    newNode->key = key;
    newNode->data = data;
    if (!head) {
        head = newNode;
    }
    else {
        Node* temp = head;
        for (;;) {
            if (key > temp->key) {
                if (temp->rightNode == nullptr) {
                    temp->rightNode = newNode;
                    return;
                }
                else {
                    temp = temp->rightNode;
                }
            }
            else if (key == temp->key) {
                return;
            }
            else {
                if (temp->leftNode == nullptr) {
                    temp->leftNode = newNode;
                    return;
                }
                else {
                    temp = temp->leftNode;
                }
            }
        }
    }
}

template <typename T>
void BinaryTree<T>::print_tree() {// print all tree
    if (!head) {
        cout << "Tree is empty" << endl;
    }
    print_tree(head);
}

template <typename T>
T BinaryTree<T>::get_data(int key) {// get data from tree
    Node* temp = head;
    for (; temp != nullptr;) {
        if (key == temp->key) {
            return temp->data;
        }
        else if (key > temp->key) {
            temp = temp->rightNode;
        }
        else {
            temp = temp->leftNode;
        }
    }
    cout << "error" << endl;
    return T();
}

template <typename T>
LinkedList<T>& BinaryTree<T>::get_data_list(LinkedList<T>& list) { // add data to my LinckedList
    get_data_list(head, list);
    return list;
}

template <typename T>
void BinaryTree<T>::clear() { // clear all tree
    clear(head);
}
