#include <iostream>
using namespace std;

struct Node {
    string data;
    Node* next_ptr;
};

class Queue {
private:
    Node* front;  
    Node* rear;  

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }


    bool isEmpty() {
        return front == nullptr;
    }

    void enqueue(string value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next_ptr = nullptr;

        if (isEmpty()) {
            front = rear = newNode;  // first node
        } else {
            rear->next_ptr = newNode;
            rear = newNode;
        }
        cout << value << " added to queue." << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is EMPTY." << endl;
            return;
        }
        cout << front->data << " removed from queue." << endl;
        Node* temp = front;
        front = front->next_ptr;

        if (front == nullptr)  
            rear = nullptr;

        delete temp;
    }

   

    void display() {
        if (isEmpty()) {
            cout << "Queue is EMPTY." << endl;
            return;
        }
        Node* current = front;
        cout << "Queue elements: ";
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next_ptr;
        }
        cout << endl;
    }
};

int main() {
    Queue q;

    q.enqueue("test1");
    q.enqueue("test2");
    q.enqueue("test3");

    q.display();

    q.dequeue();
    q.display();

    q.dequeue();
    q.dequeue();
    q.dequeue(); 

    return 0;
}
