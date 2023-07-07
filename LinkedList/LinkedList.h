#ifndef GRAPHS_LINKEDLIST_H
#define GRAPHS_LINKEDLIST_H

template <typename T>
class LinkedList {
private:
    struct Node{
        T data;
        Node* next;
    };
    Node* head;

public:
    LinkedList();
    ~LinkedList();

    void push_back(T value); // add Node to end
    void printList() const; // print List)
    void clear(); // clear all list
    int size(); // give size of list
    void pop();//delete last Node
    void insert(int position, T value);  // add Node to any position
    void push_front(T value); // add Node to start List
    void pop_front(); // delete first Node
    void delete_node(int position); // delete Node
    void assign(int position, T value); // new Node data
    T get_data(int position); // get data of List from position
    Node* begin(); // return first Node
    Node* end(); // return last Node
};

#endif //GRAPHS_LINKEDLIST_H
