#include "TwoBidirectionalLinkedList.h"
#include <iostream>

using namespace std;

template class TwoBidirectionalLinkedList<int>;
template class TwoBidirectionalLinkedList<double>;
template class TwoBidirectionalLinkedList<string>;
template class TwoBidirectionalLinkedList<char>;
template class TwoBidirectionalLinkedList<bool>;

template <typename T>
TwoBidirectionalLinkedList<T>::TwoBidirectionalLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

template <typename T>
TwoBidirectionalLinkedList<T>::~TwoBidirectionalLinkedList() {
    clear();
    head = nullptr;
    tail = nullptr;
}

template <typename T>
void TwoBidirectionalLinkedList<T>::push_back(T data) { // add data to end of list
    Node* newNode = new Node;
    newNode->data = data;
    if (tail == nullptr) {
        head = newNode;
        tail = newNode;
    }
    else {
        tail->next = newNode;
        newNode->previous = tail;
        tail = newNode;
    }
}

template <typename T>
void TwoBidirectionalLinkedList<T>::push_front(T data) { // add data to start of list
    Node* newNode = new Node;
    newNode->data = data;
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    }
    else {
        head->previous = newNode;
        newNode->next = head;
        head = newNode;
    }
}

template <typename T>
void TwoBidirectionalLinkedList<T>::pop_back() { // delete last data
    if (!tail) {
        cout << "error" << endl;
    }
    else {
        Node* saveNode = tail;
        Node* temp = tail;
        temp = tail->previous;
        tail = temp;
        tail->next = nullptr;
        delete saveNode;
    }
}

template <typename T>
void TwoBidirectionalLinkedList<T>::pop_front() { // delete first data
    if (!head) {
        cout << "error" << endl;
    }
    else {
        Node* temp = head->next;
        temp->previous = nullptr;
        head = temp;
        head->previous = nullptr;
    }
}

template <typename T>
void TwoBidirectionalLinkedList<T>::print() { // print list
    Node* temp = head;
    if (!head) {
        cout << "List is empty" << endl;
    }
    for (; temp != nullptr;) {
        cout << temp->data << endl;
        temp = temp->next;
    }
}

template <typename T>
int TwoBidirectionalLinkedList<T>::size() { // return size of list
    if (!head) {
        return 0;
    }
    Node* temp = head;
    int count = 0;
    for (; temp != nullptr;) {
        count++;
        temp = temp->next;
    }
    return count;
}

template <typename T>
void TwoBidirectionalLinkedList<T>::clear() { // clear all list
    if (head) {
        Node* temp = head;
        Node* newTemp = nullptr;
        for (; temp != nullptr;) {
            newTemp = temp->next;
            delete temp;
            temp = newTemp;
        }
        head = nullptr;
    }
}

template <typename T>
void TwoBidirectionalLinkedList<T>::delete_node(int position) { // delete Node in any position
    if (!head || position >= size() || position < 0) {
        cout << "error" << endl;
    }
    else {
        if (position == size() - 1) {
            pop_back();
        }
        else if (position == 0) {
            pop_front();
        }
        else {
            Node* temp = head;
            for (int i = 0; i < position - 1; i++) {
                temp = temp->next;
            }
            Node* saveNode = temp->next;
            temp->next = temp->next->next;
            temp->next->previous = temp;
            delete saveNode;
        }
    }
}

template <typename T>
void TwoBidirectionalLinkedList<T>::insert(int position, T data) { // add new Node to any position
    if (!head || position >= size() || position < 0) {
        cout << "error" << endl;
    }
    else {
        if (position == 0) {
            push_front(data);
        }
        else {
            Node* temp = head;
            for (int i = 0; i < position - 1; i++) {
                temp = temp->next;
            }
            Node* newNode = new Node;
            newNode->data = data;
            Node* saveNode = temp->next;

            temp->next = newNode;
            saveNode->previous = newNode;

            newNode->next = saveNode;
            newNode->previous = temp;
        }
    }

}

template <typename T>
void TwoBidirectionalLinkedList<T>::assign(int position, T data) { // add data to any position
    if (!head || position >= size() || position < 0)
    {
        cout << "error" << endl;
    }
    else {
        Node* temp = head;
        for (int i = 0; i < position; i++) {
            temp = temp->next;
        }
        temp->data = data;
    }
}

template <typename T>
typename TwoBidirectionalLinkedList<T>::Node* TwoBidirectionalLinkedList<T>::end() {
    if (!tail) { //return last Node
        cout << "List is empty" << endl;
        return nullptr;
    }
    else {
        return tail;
    }
}

template <typename T>
typename TwoBidirectionalLinkedList<T>::Node* TwoBidirectionalLinkedList<T>::begin() { // return first Node
    if (!head) {
        cout << "List is empty" << endl;
        return nullptr;
    }
    else {
        return head;
    }
}



