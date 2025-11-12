#include <iostream>
using namespace std;

struct Node {
    string data;
    Node* next_ptr;
};

class Stack {
private:
    Node* top;   // pointer to top of stack

public:
    Stack() {
        top = nullptr; // stack starts empty
    }

    // Check if empty
    bool isEmpty() {
        return top == nullptr;
    }

    
    void push(string value) {
        Node* newNode = new Node;  
        newNode->data = value;
        newNode->next_ptr = top;   // new node points to old top
        top = newNode;             // new node becomes top
        cout << value << " pushed to stack." << endl;
    }

    
    void pop() {
        if (isEmpty()) {
            cout << "Stack is EMPTY." << endl;
            return;
        }
        cout << top->data << " popped from stack." << endl;
        Node* temp = top;
        top = top->next_ptr; 
        delete temp;         
    }

    
    void peek() {
        if (isEmpty()) {
            cout << "Stack is EMPTY" << endl;
            return;
        }
        cout << "Top element: " << top->data << endl;
    }

   
    void display() {
        if (isEmpty()) {
            cout << "Stack is EMPTY" << endl;
            return;
        }
        Node* current = top;
        cout << "Stack elements: ";
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next_ptr;
        }
        cout << endl;
    }
};

int main() {
    Stack s; //stack object

    s.push("test1");
    s.push("test2");
    s.push("test3");

    s.display();

    s.peek();

    s.pop();
    s.display();

    s.pop();
    s.pop();
    s.pop(); 

    return 0;
}
