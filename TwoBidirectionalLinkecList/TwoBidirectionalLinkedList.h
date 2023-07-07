//
// Created by Volkov on 07.07.2023.
//

#ifndef GRAPHS_TWOBIDIRECTIONALLINKEDLIST_H
#define GRAPHS_TWOBIDIRECTIONALLINKEDLIST_H


template <typename T>
class TwoBidirectionalLinkedList {
private:
    struct Node {
        T data;
        Node* next;
        Node* previous;

        Node() {
            next = nullptr;
            previous = nullptr;
        }
    };
    Node* head;
    Node* tail;


public:
    TwoBidirectionalLinkedList();
    ~TwoBidirectionalLinkedList();

    void push_back(T data); // add data to end of list
    void push_front(T data); // add data to start of list
    void pop_back(); // delete last data
    void pop_front(); // delete first data
    void print(); // print list
    int size(); // return size of list
    void clear(); // clear all list
    void delete_node(int position); // delete Node in any position
    void insert(int position, T data);// add new Node to any position
    void assign(int position, T data); // add data to any position
    Node* end();
    Node* begin();
};




#endif //GRAPHS_TWOBIDIRECTIONALLINKEDLIST_H
