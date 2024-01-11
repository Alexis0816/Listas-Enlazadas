#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};

class CircularDoublyLinkedList {
private:
    Node* head;

public:
    CircularDoublyLinkedList() : head(nullptr) {}

    void insert(int value) {
        Node* newNode = new Node(value);

        if (!head) {
            head = newNode;
            head->next = head;
            head->prev = head;
        } else {
            Node* last = head->prev;

            last->next = newNode;
            newNode->prev = last;

            newNode->next = head;
            head->prev = newNode;
        }
    }

    int T_front() { //Ejercicio 1
        if (head) {
            return head->data;
        } else {
            cout<<"La lista está vacía"<<endl;
            return 0;
        }
    };
    int T_back(){ //Ejericio 2
        if (head){
            return head->prev->data;
        }
        else{
            cout<<"La lista está vacía"<<endl;
            return 0;
        }
    };
    void push_front(int value){ //Ejercicio 3
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            head->next = head;
            head->prev = head;
        } else {
            Node* last = head->prev;

            last->next = newNode;
            newNode->prev = last;

            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    };
    void push_back(int value){ //Ejercicio 4
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            head->next = head;
            head->prev = head;
        } else {
            Node* last = head->prev;

            last->next = newNode;
            newNode->prev = last;

            newNode->next = head;
            head->prev = newNode;
        }
    };
    int pop_front(){ //Ejercicio 5
        if (head){
            Node* last = head->prev;
            Node* newHead = head->next;
            last->next = newHead;
            newHead->prev = last;
            head = newHead;
        }
        else{
            cout<<"La lista está vacía"<<endl;
        }
        return 0;
    };
    int pop_back(){ //Ejercicio 6
        if (head){
            Node* last = head->prev;
            Node* newLast = last->prev;
            newLast->next = head;
            head->prev = newLast;
        }
        else{
            cout<<"La lista está vacía"<<endl;
        }
        return 0;
    };
};

int main() {
    CircularDoublyLinkedList myList;

    myList.insert(1);
    myList.insert(2);
    myList.insert(3);
    //EJ1
    try {
        int frontElement = myList.T_front();
        cout << "Elemento al comienzo: " << frontElement << endl;
    } catch (const char* msg) {
        cout << msg << endl;
    }
    //EJ 2
    try{
        int backelement = myList.T_back();
        cout<<"Elemento al final: "<<backelement<<endl;
    }catch(const char* msg){
        cout<<msg<<endl;
    }
    return 0;
    //EJ 3
    try {
        myList.push_front(4);
        int frontElement = myList.T_front();
        cout << "Elemento al comienzo: " << frontElement << endl;
    } catch (const char* msg) {
        cout << msg << endl;
    }
    //EJ 4
    try {
        myList.push_back(5);
        int backElement = myList.T_back();
        cout << "Elemento al final: " << backElement << endl;
    } catch (const char* msg) {
        cout << msg << endl;
    }
    //EJ 5
    try {
        myList.pop_front();
        int frontElement = myList.T_front();
        cout << "Elemento al comienzo: " << frontElement << endl;
    } catch (const char* msg) {
        cout << msg << endl;
    }
    //EJ 6
    try {
        myList.pop_back();
        int backElement = myList.T_back();
        cout << "Elemento al final: " << backElement << endl;
    } catch (const char* msg) {
        cout << msg << endl;
    }
}
