#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q;

    int n = 6;
    int arr[] = {4, 7, 11, 20, 5, 9};
    for (int i = 0; i < n; i++) q.push(arr[i]);

    queue<int> firstHalf;
    int half = q.size() / 2;

    for (int i = 0; i < half; i++) {
        firstHalf.push(q.front());
        q.pop();
    }

    cout << "Interleaved Output: ";

    while (!firstHalf.empty()) {
        cout << firstHalf.front() << " ";
        firstHalf.pop();

        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}

