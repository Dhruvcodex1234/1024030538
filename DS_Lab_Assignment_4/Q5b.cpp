#include <iostream>
#include <queue>
using namespace std;

class Stack {
    queue<int> q;

public:
    void push(int x) {
        q.push(x);
        int size = q.size();
        while (size-- > 1) {
            q.push(q.front());
            q.pop();
        }
    }

    void pop() {
        if (q.empty()) cout << "Stack empty\n";
        else {
            cout << "Popped: " << q.front() << endl;
            q.pop();
        }
    }

    void top() {
        if (q.empty()) cout << "Stack empty\n";
        else cout << "Top: " << q.front() << endl;
    }
};

int main() {
    Stack s;

    s.push(5);
    s.push(15);
    s.push(25);

    s.top();
    s.pop();
    s.top();

    return 0;
}

