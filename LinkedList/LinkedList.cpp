#include "LinkedList.h"
#include <iostream>

using namespace std;

template class LinkedList<int>;
template class LinkedList<double>;
template class LinkedList<string>;
template class LinkedList<char>;
template class LinkedList<bool>;


template <typename T>
LinkedList<T>::LinkedList() {
    head = nullptr;
}

template <typename T>
LinkedList<T>::~LinkedList() {
    clear();
    head = nullptr;
}

template <typename T>
void LinkedList<T>::push_back(T value) { // add Node to end
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    if (head == nullptr) {
        head = newNode;
    }
    else {
        Node* temp = head;
        for (; temp->next != nullptr;) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

template <typename T>
void LinkedList<T>::printList() const { // print List
    if (!head) {
        cout << "Empty" << endl;
    }
    else {
        Node* temp = head;
        for (; temp != nullptr;) {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }
}

template <typename T>
void LinkedList<T>::clear() { // clear all list
    if (head) {
        Node* temp = head;
        Node* newTemp = nullptr;
        while (temp != nullptr) {
            newTemp = temp->next;
            delete temp;
            temp = newTemp;
        }
        head = nullptr;
    }
}

template <typename T>
int LinkedList<T>::size() { // give size of list
    if (head == nullptr) {
        return 0;
    }
    else {
        Node* temp = head;
        int n = 0;
        for (; temp != nullptr;) {
            n++;
            temp = temp->next;
        }
        return n;
    }
}

template <typename T>
void LinkedList<T>::pop() { //delete last Node
    if (!head) {
        cout << "Error" << endl;
    }
    else {
        Node* temp = head;
        for (; temp->next->next != nullptr;) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }
}

template <typename T>
void LinkedList<T>::insert(int position, T value) {  // add Node to any position
    if (position > size()) {
        cout << "error" << endl;
    }
    else {
        Node* temp = head;
        Node* newNode = new Node;
        newNode->data = value;
        Node* saveNode;
        if (position == 0) {
            saveNode = head;
            head = newNode;
            newNode->next = saveNode;
        }
        else {
            for (int i = 0; i < position - 1; i++) {
                temp = temp->next;
            }
            saveNode = temp->next;
            temp->next = newNode;
            newNode->next = saveNode;
        }
    }
}

template <typename T>
void LinkedList<T>::push_front(T value) { // add Node to start List
    Node* newNode = new Node;
    newNode->data = value;
    if (head == nullptr) {
        head = newNode;
    }
    else {
        Node* temp = head;
        Node* saveNode;

        saveNode = head;
        head = newNode;
        newNode->next = saveNode;
    }
}

template <typename T>
void LinkedList<T>::pop_front() { // delete first Node
    if (!head) {
        cout << "List is empty" << endl;
    }
    else {
        Node* temp = head;
        Node* saveNode;
        saveNode = temp->next;
        head = nullptr;
        head = saveNode;
    }
}

template <typename T>
void LinkedList<T>::delete_node(int position) { // delete Node
    if (position >= size() || position < 0) {
        cout << "error" << endl;
    }
    else if (position == 0) {
        pop_front();
    }
    else {
        Node* temp = head;
        Node* saveNode;
        for (int i = 0; i < position - 1; i++) {
            temp = temp->next;
        }
        saveNode = temp->next->next;
        delete temp->next;
        temp->next = saveNode;
    }
}

template <typename T>
void LinkedList<T>::assign(int position, T value) { // new Node data
    if (position >= size() || position < 0) {
        cout << "error" << endl;
    }
    else {
        Node* temp = head;
        for (int i = 0; i < position; i++) {
            temp = temp->next;
        }
        temp->data = value;
    }
}

template <typename T>
T LinkedList<T>::get_data(int position) { // get data of List from position
    if (!head || position >= size() || position < 0)
    {
        cout << "error" << endl;
        return T();
    }
    else {
        Node* temp = head;
        for (int i = 0; i < position; i++) {
            temp = temp->next;
        }
        return temp->data;
    }
}

template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::begin() { // return first Node
    if (!head) {
        cout << "List is epty" << endl;
        return nullptr;
    }
    else {
        return head;
    }
}

template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::end() { // return last Node
    if (!head) {
        cout << "List is epty" << endl;
        return nullptr;
    }
    else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        return temp;
    }
}

