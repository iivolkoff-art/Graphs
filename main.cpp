#include <iostream>

using namespace std;


template <typename T>
class LinkedList {
private:
    struct Node {
        T data;
        Node* next;
    };
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    ~LinkedList() {
        clear();
        head = nullptr;
    }

    void push_back(T value) { // add Node to end
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

    void printList() const { // print List)
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

    void clear() { // clear all list
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


    int size() { // give size of list
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

    void pop() { //delete last Node
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

    void insert(int position, T value) {  // add Node to any position
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

    void push_front(T value) { // add Node to start List
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

    void pop_front() { // delete first Node
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

    void delete_node(int position) { // delete Node
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

    void assign(int position, T value) { // new Node data
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

    T get_data(int position) { // get data of List from position
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

    Node* begin() { // return first Node
        if (!head) {
            cout << "List is epty" << endl;
            return T();
        }
        else {
            return head;
        }
    }

    Node* end() { // return last Node
        if (!head) {
            cout << "List is epty" << endl;
            return T();
        }
        else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            return temp;
        }
    }
};


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
    TwoBidirectionalLinkedList() {
        head = nullptr;
        tail = nullptr;
    }
    ~TwoBidirectionalLinkedList() {
        clear();
        head = nullptr;
        tail = nullptr;
    }
    void push_back(T data) { // add data to end of list
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

    void push_front(T data) { // add data to start of list
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

    void pop_back() { // delete last data
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

    void pop_front() { // delete first data
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

    void print() { // print list
        Node* temp = head;
        if (!head) {
            cout << "List is empty" << endl;
        }
        for (; temp != nullptr;) {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }

    int size() { // return size of list
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

    void clear() { // clear all list
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

    void delete_node(int position) { // delete Node in any position
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

    void insert(int position, T data) { // add new Node to any position
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

    void assign(int position, T data) { // add data to any position
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

    T end() {
        if (!tail) { //return last Node
            cout << "List is empty" << endl;
            return T();
        }
        else {
            return tail;
        }
    }

    T begin() { // return first Node
        if (!head) {
            cout << "List is empty" << endl;
            return T();
        }
        else {
            return head;
        }
    }

};


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
    void get_data_list(Node* node, LinkedList<T>& list) { // add data to my LinckedList (for class)
        if (node == nullptr) {
            return;
        }
        get_data_list(node->leftNode, list);
        list.push_back(node->data);
        get_data_list(node->rightNode, list);
    }

    void print_tree(Node* node) { // print all data from list (for class)
        if (node == nullptr) {
            return;
        }
        print_tree(node->leftNode);

        cout << node->data << " ";

        print_tree(node->rightNode);
    }

    void clear(Node* node) { // clear all Tree (for class)
        if (!node) {
            return;
        }
        clear(node->leftNode);
        clear(node->rightNode);
        delete node;
        head = nullptr;
    }

public:
    BinaryTree() {
        head = nullptr;
    }
    ~BinaryTree() {
        clear(head);
    }

    void add_data(int key, T data) { // add data to tree
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

    void print_tree() {// print all tree
        if (!head) {
            cout << "Tree is empty" << endl;
        }
        print_tree(head);
    }

    T get_data(int key) {// get data from tree
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

    LinkedList<T>& get_data_list(LinkedList<T>& list) { // add data to my LinckedList
        get_data_list(head, list);
        return list;
    }

    void clear() { // clear all tree
        clear(head);
    }

};


int main() {
    BinaryTree<string> a;
    a.add_data(5, "Ivan");
    a.add_data(3, "Nikita");
    a.add_data(10, "Dima");
    a.clear();

    a.print_tree();
    cout << endl;
    cout << endl;
    // LinkedList<string> b;
     //a.get_data_list(b);
     //b.printList();

}
