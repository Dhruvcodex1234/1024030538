#include <iostream>
#include <stack>
using namespace std;

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;

    stack<char> st;

    for (char c : s)
        st.push(c);

    string rev = "";
    while (!st.empty()) {
        rev += st.top();
        st.pop();
    }

    cout << "Reversed string: " << rev << endl;
    return 0;
}

