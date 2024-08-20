#include <iostream>
using namespace std;

class Stack {
    int* arr;
    int top;
    int capacity;
    
public:
    Stack(int size) {
        arr = new int[size];
        capacity = size;
        top = -1;
    }
    
    ~Stack() {
        delete[] arr;
    }
    
    void push(int value) {
        if (top == capacity - 1) {
            cout << "Stack Overflow" << endl;
            return;
        }
        arr[++top] = value;
    }
    
    int pop() {
        if (top == -1) {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        return arr[top--];
    }
    
    bool isEmpty() {
        return top == -1;
    }
    
    int peek() {
        if (!isEmpty())
            return arr[top];
        else
            return -1;
    }
};

int findWinner(int n, int k) {
    int* friends = new int[n];
    
    for (int i = 0; i < n; i++) {
        friends[i] = i + 1;
    }
    
    int index = 0;  
    int remainingFriends = n; 
    
    Stack s(remainingFriends);
    
    while (remainingFriends > 1) {
        index = (index + k - 1) % remainingFriends;
        
        
        for (int i = index; i < remainingFriends - 1; i++) {
            friends[i] = friends[i + 1];
        }
        remainingFriends--;
    }
    
    int winner = friends[0];
    delete[] friends;
    
    return winner;
}

int main() {
    int n, k;
    
    cout << "Enter the number of friends: ";
    cin >> n;
    
    cout << "Enter the counting number (k): ";
    cin >> k;
    
    int winner = findWinner(n, k);
    cout << "The winner is friend number: " << winner << endl;
    
    return 0;
}
